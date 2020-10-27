%INCLUDE "console1.inc"
IMPORT MessageBoxA user32.dll
IMPORT ExitProcess kernel32.dll

EXTERN MessageBoxA	
EXTERN ExitProcess	


;VARIABEL DECLARATION
;------------------------------------------------------------------------------------------------
section .data 		

judul1		db "Summing Numbers", 0 	;;judul1 konsol
judul2		db "Summing Result", 0 		;;judul1 messagebox
teks1       db 13,10,13,10,"Write Number ( last number 0)     :",13,10, 0 
pteks1		dd 0 
	
buff		resb 255
nul			db 0
buff_len	dd 256

teks2       db " Result                      : "
strResult	db '            ',0			
ptekssthasil dd 0
str_len		db 12

bil			resd 1
resultSum	dd 0

section .bss 	

hStdOut         resd 1 
hStdIn          resd 1 
nBytes          resd 1
iBytes          resd 1

section .text use32 
..start: 
	initconsole judul1, hStdOut, hStdIn				;; Membuat konsol
	display_text teks1, pteks1, nBytes, hStdOut		;; Menampilkan pesan teks1

again:

	call read_text									;; Menerima inputan user
	
	cekinput:									
		mov ecx,[iBytes]
		cmp ecx, 2									;; Jika inputan hanya enter atau 0 maka akan berhenti meminta data
		je stopr
		
	cekbuff:
		mov ebx,buff
		mov ecx,[iBytes]
		sub ecx,2
	
		cek:
			mov al,byte[ebx]		;;ebx sebagai penunjuk, al menyimpan sementara
			cmp al,47				;; Jika inputan bukan angka akan meminta input lagi
			jle again
			cmp al,58				;; Jika inputan bukan angka akan meminta input lagi
			jge again
			inc ebx					;; Memajukan penunjuk
			loop cek
		
	call String_to_Int								;; Mengubah string menjadi integer
	mov eax,[bil]
	cmp eax,0
	je stopr
	
	call adder									;; Menambahkan integer tersebut ke hasil
	jmp again
	
	stopr:
	
	call Int_to_String								;; Mengubah integer menjadi string
	call messagebox								;; Akan menampilkan messagebox
	
	coba:
	mov dword[resultSum],0
	call reset
	jmp ..start
	
;=================================================================================================

messagebox:
	push dword 05h				;; tombol RetryCancel
 	push dword judul2			;; judul1 messagebox
 	push dword teks2     		;; akan menampilkan pesan teks2
 	push dword 0				;; owner 0
	call [MessageBoxA]
	cmp eax,4					;; Mengecek apakah user menginput retry atau tidak
	je coba						;; Jika iya maka kembali lagi ke coba
	quitconsole					;; Jika tidak program selesai
	ret

read_text:
								;; membaca string dari Console(keyboard) dg ReadFile
push dword 0 					;; parameter ke 5 dari ReadFile() adalah 0 
push dword iBytes 				;; parameter ke 4 jumlah byte yg sesungguhnya terbaca (TERMASUK ENTER)
push dword [buff_len] 			;; parameter ke 3 panjang buffer yg disediakan
push dword buff 				;; parameter ke 2 buffer untuk menyimpan string yg dibaca 
push dword [hStdIn] 			;; parameter ke 1 handle stdin
call [ReadFile] 			
ret
;--------------------------------------------------------------------------------------------------
display_total:
push dword 0 				;; parameter ke 5 dari WriteFile() adalah 0 
push dword nBytes			;; parameter ke 4 jumlah byte yg sesungguhnya tertulis
push dword [str_len] 		;; parameter ke 3 panjang string
push dword strResult		;; parameter ke 2 string yang akan ditampilkan 
push dword [hStdOut] 		;; parameter ke 1 handle stdout
call [WriteFile] 
ret
;--------------------------------------------------------------------------------------------------

reset:
	mov ebx,strResult
	xor ecx,ecx
	mov cl,byte[str_len]
	sub cl,1	
	strt:
		mov byte[ebx],32
		inc ebx
		loop strt
	ret


;-------------------------------------------------------------------------------------

Int_to_String:
	mov ebx, strResult			;; hasil konversi disimpan di strResult
 loop:
    mov byte[ebx],' '
	inc ebx						;; ebx digunakan sebagai pointer ke strResult
	cmp byte[ebx],0				;; diposisikan pada akhir string strResult 
	jne loop
	dec ebx    

	mov eax, [resultSum]			
	mov esi,10
 loop2:
	xor edx, edx				;; membuat nilai edx 0 untuk menampung sisa bagi
	div esi						;; dilakukan pembagian 10 berulang
	add dl, '0'        			;; sisa bagi pada edx (dl) di ubah ke character
	mov [ebx], dl				;; simpan ke strResult dari belakang ke depan
	dec ebx						;; majukan pointer
	or  eax,eax					;; test apakah yang dibagi sudah nol
	jnz loop2 					;; selesai perulangan jika yang dibagi sdh nol
ret

String_to_Int:
        xor eax,eax				;; membuat nilai eax menjadi 0
        mov esi, 10				;; esi sebagai pengali dimasukkan angka 10
        mov ebx, buff
		mov ecx, [iBytes]
		sub ecx, 2
		xor edx,edx
    Loopbil:
        mul esi 				;;hasil sebelumnya dikalikan 10 (nilai esi)
        mov dl, byte [ebx]		
        sub dl,30h 				;;ubah ke angka 0-9
        add eax,edx 			;;tambahkan dengan digit terakhir 
        inc ebx
        loop Loopbil
    
	mov [bil], eax
ret


adder:
	mov eax,dword[resultSum]
	mov edi,[bil]
	add eax,edi
	mov dword[resultSum],eax
	
	ret
	