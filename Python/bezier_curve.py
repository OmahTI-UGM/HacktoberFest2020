import pygame

# Inisialisasi Window untuk menggambar garis
pygame.init()
pygame.display.set_caption("Bezier Curve with 4 Control Point")
window = (600, 600)  # Mengatur ukuran window width:height 800:600
screen = pygame.display.set_mode(window)

x, y = 500.0, 500.0
width, height = 70, 70
SPEED = 0.001

# Mendeklarasi 4 titik kontrol p1, p2, p3, dan p4
# path_position = [(100, 300), (200, 100), (300, 600), (400, 300)]
path_position = [(100.0, 300.0), (200.0, 100.0),
                 (300.0, 600.0), (400.0, 300.0)]

# Deklarasi variabel untuk mengontrol kecepatan gambar garis
T = 0

# Deklarasi untuk looping while
RUNNING = True

while RUNNING:
    # Memberi background warna hitam dan delay
    screen.fill((0, 0, 0))
    pygame.time.delay(100)

    # Mengambil posisi untuk setiap titik p0, p1, p2, p3
    p0 = path_position[0]
    p1 = path_position[1]
    p2 = path_position[2]
    p3 = path_position[3]

    # Jika window ditutup, window pygame akan dihentikan
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            RUNNING = False

    # Melakukan looping formula bezier
    while T < 1:
        T += SPEED

        # Formula untuk membuat bezier curve
        # Mengambil nilai-nilai dari titik kontrol yang sudah dideklarasi diatas
        p0_x = pow((1 - T), 3) * p0[0]
        p0_y = pow((1 - T), 3) * p0[1]

        p1_x = 3 * pow((1 - T), 2) * T * p1[0]
        p1_y = 3 * pow((1 - T), 2) * T * p1[1]

        p2_x = 3 * (1 - T) * pow(T, 2) * p2[0]
        p2_y = 3 * (1 - T) * pow(T, 2) * p2[1]

        p3_x = pow(T, 3) * p3[0]
        p3_y = pow(T, 3) * p3[0]

        # Total jarak dari seluruh garis
        line = ((p0_x + p1_x + p2_x + p3_x), (p0_y + p1_y + p2_y + p3_y))
        x, y = line

        # Menampilkan garis
        # (255, 255, 255) sebagai warna garis yaitu putih
        # (round(x), round(y)) sebagai posisi pixel yang digambar
        pygame.draw.circle(screen, (255, 255, 255), (round(x), round(y)), 1)

        # Update window untuk tiap pixel
        pygame.display.update()

pygame.quit()
