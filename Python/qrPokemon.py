import pyqrcode 
import png 
from pyqrcode import QRCode 

# open file
file = open('qrData','r')
arr = file.readlines()

for id,item in enumerate(arr):
    # delete \n
    s = item[:-1]
    
    name = 'qr/myqr'+str(id+1)+'.png'
    pyqrcode.create(s).png(name,scale = 10)
    print(name)

# contoh file qrData
# 883427597189
# 883427597189
# 883427597189
