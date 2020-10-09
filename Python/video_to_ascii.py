'''
Video to ASCII Video Converter

Note    : Kodingannya masih sangat experimental
          kemungkinan masih banyak bug, kode blm clean,
          dan juga belum teroptimasi dengan baik.
          Silakan jika mau dikembangkan.
'''

import cv2
import os
import numpy as np
import moviepy.editor
from PIL import Image
import multiprocessing
from ffpyplayer.player import MediaPlayer
import time
import shutil

# Ubah nama file videonya kalau mau pake video lain
input_video = "iofi.mp4"

ascii_dir = "./ascii"
capture_dir = "./captures"

cols = 100
scale = 0.43

def run_procs(procs):
    for proc in procs:
        proc.start()
    for proc in procs:
        proc.join()

def rename(value):
    value = str(value)
    if len(value) == 1:
        value = '0000' + value
    elif len(value) == 2:
        value = '000' + value
    elif len(value) == 3:
        value = '00' + value
    elif len(value) == 4:
        value = '0' + value
    return value

def writeFrame(capture_dir, i , frame):
    cv2.imwrite('{}/{}.jpg'.format(capture_dir, rename(i)), frame)

def getAverageL(image): 
    im = np.array(image) 
    w,h = im.shape 
    return np.average(im.reshape(w*h)) 

def covertImageToAscii(fileName, cols, scale): 
    gscale = "@%#*+=-:. "

    image = Image.open(fileName).convert('L') 
    W, H = image.size[0], image.size[1] 
    w = W/cols 
    h = w/scale 
    rows = int(H/h) 
  
    if cols > W or rows > H: 
        print("kekecilan cuy") 
        exit(0) 
  
    aimg = [] 
    for j in range(rows): 
        y1 = int(j*h) 
        y2 = int((j+1)*h) 
  
        if j == rows-1: 
            y2 = H 
  
        aimg.append("") 
  
        for i in range(cols): 
            x1 = int(i*w) 
            x2 = int((i+1)*w) 
  
            if i == cols-1: 
                x2 = W 
  
            img = image.crop((x1, y1, x2, y2)) 
            avg = int(getAverageL(img)) 
  
            gsval = gscale[int((avg*(len(gscale)-1))/255)] 
            aimg[j] += gsval 
      
    return aimg, W, H, w, h

def asciiTask(i, img):
    filename = '{}/{}'.format(capture_dir, img)
    ascii_strings, W, H, w, h = covertImageToAscii(filename, cols, scale)
    blank_image = 255 * np.ones(shape=[H, W, 3], dtype=np.uint8)
    for j, text in enumerate(ascii_strings):
        for k, char in enumerate(text):
            cv2.putText(
                blank_image,
                char,
                (int(k*w), int(j*h)),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.2,
                (232, 67, 147, 255),
                0
            )
    cv2.imwrite('{}/{}.png'.format(ascii_dir, rename(i)), blank_image)

def createAsciiRunner(tasks):
    for task in tasks:
        asciiTask(task['i'], task['img'])

def PlayVideo(video_path, name, x, y):
    video=cv2.VideoCapture(video_path)

    player = MediaPlayer(video_path)
    while True:
        grabbed, frame=video.read()
        audio_frame, val = player.get_frame()
        if not grabbed:
            print("End")
            break
        if cv2.waitKey(28) & 0xFF == ord("q"):
            break
        cv2.moveWindow(name, x, y)
        cv2.imshow(name, frame)
        if val != 'eof' and audio_frame is not None:
            img, t = audio_frame
    video.release()
    cv2.destroyAllWindows()

def main():
    procs = []

    capture = cv2.VideoCapture("./" + input_video)
    fps = capture.get(cv2.CAP_PROP_FPS)

    print("Extract audio from video...")
    video = moviepy.editor.VideoFileClip(input_video)
    audio = video.audio
    audio.write_audiofile("audio.mp3")

    if not os.path.exists(capture_dir):
        os.makedirs(capture_dir)

    print("Generate img frames from video...")
    print("Frame rate: {}", fps)
    i = 0
    while capture.isOpened():
        ret, frame = capture.read()
        if ret == False:
            break
        writeFrame(capture_dir, i , frame)
        i += 1
    capture.release()

    print("Generate ascii img frames...")
    os.makedirs(ascii_dir)
    captures = os.listdir(capture_dir)
    taskCount = int(len(captures)/10)+1
    tasks = []
    prcsize = 1
    for i, img in enumerate(captures):
        tasks.append({
            'i': i,
            'img': img
        })
        if prcsize % taskCount == 0:
            p = multiprocessing.Process(target=createAsciiRunner, args=(tasks,))
            procs.append(p)
            tasks = []
        prcsize += 1
    run_procs(procs)
    procs = []

    print("Generate video from ascii img frames...")

    ascii_listdir = os.listdir('./ascii/')
    tmp = cv2.imread('./ascii/' + ascii_listdir[0])
    height, width, layers = tmp.shape
    size = (width,height)
    out = cv2.VideoWriter('out.avi',cv2.VideoWriter_fourcc(*'DIVX'), fps, size)

    ascii_frames = []
    for i, frame in enumerate(ascii_listdir):
        img = cv2.imread('./ascii/' + frame)
        out.write(img)
    out.release()

    print("Adding audio to newest video...")
    video = moviepy.editor.VideoFileClip("out.avi")
    audio = moviepy.editor.AudioFileClip("audio.mp3")
    new_audio = moviepy.editor.CompositeAudioClip([audio])
    video.audio = audio
    video.write_videofile('out.mp4')

    shutil.rmtree('./captures/')
    shutil.rmtree('./ascii/')

    print("=== DONE ===")

    # Ini kalau mau abis render langsung play
    p = multiprocessing.Process(target=PlayVideo, args=("out.mp4", "ascii", 200, 100,))
    p.start()

if __name__ == '__main__':
    main()