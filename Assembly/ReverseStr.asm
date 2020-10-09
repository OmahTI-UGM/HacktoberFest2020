%INCLUDE "ReverseStr.INC"
;VARIABEL DECLARATION
;------------------------------------------------------------------------------------------------
section .data use32		
The_Title       db "REVERSE TEXT", 0 
Msg1            db 13,10,13,10,"     WRITE TEXT  : ", 0 
Msg1_len		dd $-Msg1
Msg2            db 13,10,13,10,"     YOUR TEXT   : ", 0 
Msg2_len		dd $-Msg2 
Msg3            db 13,10,13,10,"     TEXT REVERSE: ", 0 
Msg3_len		dd $-Msg3 
Msg4			db 13,10,13,10,"     Please <Enter>..... to close", 13,10,0 
Msg4_len        dd $-Msg4 

buff			resb 255
buff_len		dd 255
buf2			resb 255
buf2_len		dd 255

section .bss use32	;; Initialize variabel: hStdOut, hStdIn, nBytes, iBytes AS double-word TYPE

hStdOut         resd 1 
hStdIn          resd 1 
nBytes          resd 1
iBytes          resd 1

; START PROGRAM
;--------------------------------------------------------------------------------------------------
section .text use32 
..start: 

call [AllocConsole] 

push dword The_Title 
call [SetConsoleTitleA] 

push dword -11 				;; STD_OUTPUT_HANDLE = -11.
call [GetStdHandle] 
mov dword [hStdOut], eax 

push dword -10				;; STD_INPUT_HANDLE = -10 
call [GetStdHandle] 
mov dword [hStdIn], eax 
							;; menampilkan Teks ke Console(Monitor) dg WriteFile
push dword 0 				;; parameter ke 5 dari WriteFile() adalah 0 
push dword nBytes			;; parameter ke 4 jumlah byte yg sesungguhnya tertulis
push dword [Msg1_len] 		;; parameter ke 3 panjang string
push dword Msg1				;; parameter ke 2 string yang akan ditampilkan
push dword [hStdOut] 		;; parameter ke 1 handle stdout
call [WriteFile] 				
							;; membaca string dari Console(keyboard) dg ReadFile
push dword 0 				;; parameter ke 5 dari ReadFile() adalah 0 
push dword iBytes 			;; parameter ke 4 jumlah byte yg sesungguhnya terbaca (TERMASUK ENTER)
push dword [buff_len] 		;; parameter ke 3 panjang buffer yg disediakan
push dword buff 			;; parameter ke 2 buffer untuk menyimpan string yg dibaca 
push dword [hStdIn] 		;; parameter ke 1 handle stdin
call [ReadFile] 			

							;; menampilkan Teks ke Console(Monitor) dg WriteFile
push dword 0 				;; parameter ke 5 dari WriteFile() adalah 0 
push dword nBytes			;; parameter ke 4 jumlah byte yg sesungguhnya tertulis
push dword [Msg2_len] 		;; parameter ke 3 panjang string
push dword Msg2				;; parameter ke 2 string yang akan ditampilkan 
push dword [hStdOut] 		;; parameter ke 1 handle stdout
call [WriteFile] 				

push dword 0 				;; parameter ke 5 dari WriteFile() adalah 0 
push dword nBytes			;; parameter ke 4 jumlah byte yg sesungguhnya tertulis
push dword [iBytes] 		;; parameter ke 3 panjang string
push dword buff				;; parameter ke 2 string yang akan ditampilkan 
push dword [hStdOut] 		;; parameter ke 1 handle stdout
call [WriteFile] 

;REVERSE TEXT:	
;-----------------------------------------------------------------------------------------------
mov ebx, dword buff
mov ecx, [iBytes]
add ebx, ecx
sub ebx,3					; EBX berisi alamat terakhir (sebelum enter)

mov esi, buf2				; ESI alamat tujuan
sub ecx,2					; counter kurangi 2 (krn tdk termasuk enter)
mov [buf2_len], ecx

balik:
	mov al, byte [ebx]
	mov [esi], al
	dec ebx
	inc esi
	loop balik
;------------------------------------------------------------------------------------------------
							;; menampilkan Teks ke Console(Monitor) dg WriteFile
push dword 0 				;; parameter ke 5 dari WriteFile() adalah 0 
push dword nBytes			;; parameter ke 4 jumlah byte yg sesungguhnya tertulis
push dword [Msg3_len] 		;; parameter ke 3 panjang string
push dword Msg3				;; parameter ke 2 string yang akan ditampilkan "Tampilkan lagi: "
push dword [hStdOut] 		;; parameter ke 1 handle stdout
call [WriteFile] 				

push dword 0 				;; parameter ke 5 dari WriteFile() adalah 0 
push dword nBytes			;; parameter ke 4 jumlah byte yg sesungguhnya tertulis
push dword [iBytes] 		;; parameter ke 3 panjang string
push dword buf2				;; parameter ke 2 string yang akan ditampilkan 
push dword [hStdOut] 		;; parameter ke 1 handle stdout
call [WriteFile] 
			
push dword 0 
push dword nBytes 
push dword [Msg4_len] 
push dword Msg4 			;;parameter ke 2 string "Tunggu 10 detik ...................."
push dword [hStdOut] 
call [WriteFile] 

;push dword 30000 			;; delay 10 second 
;call [Sleep] 

push dword 0 				;; parameter ke 5 dari ReadFile() adalah 0 
push dword iBytes 			;; parameter ke 4 jumlah byte yg sesungguhnya terbaca (TERMASUK ENTER)
push dword [buff_len] 		;; parameter ke 3 panjang buffer yg disediakan
push dword buff 			;; parameter ke 2 buffer untuk menyimpan string yg dibaca 
push dword [hStdIn] 		;; parameter ke 1 handle stdin
call [ReadFile] 			

call [FreeConsole] 

xor eax, eax 
push eax 
call [ExitProcess] 
