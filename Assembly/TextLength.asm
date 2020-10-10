%INCLUDE "winAPI.inc"		;;Declare external procedure {winapi}
%INCLUDE "Console1.mac"		;;Macro definition

SEGMENT .DATA use32
Title   	db "TEXT LENGTH (EXCLUDED SPACE)",0 

msg1 		db 13,10,13,10,"WRITE TEXT (Quit Just Enter): ",0
msg1_len 	dd $-msg1
msg2 		db 13,10,"YOUR TEXT                   : ",0
msg2_len 	dd $-msg2
msg3 		db 13,10,"TEXT LENGTH                 : ",0
msg3_len 	dd $-msg3

buff		resb 255
buff_len	dd 255

strhasil	db '     ',0
str_len		db 6   


SEGMENT .BSS  use32
hStdOut		resd 1 
hStdIn		resd 1 
nBytes		resd 1
iBytes		resd 1

SEGMENT .CODE use32
..start:

NewConsole 	Title, hStdOut, hStdIn

Again:
DisplayText	hStdOut, msg1, msg1_len, nBytes
GetText		hStdIn, buff, buff_len, iBytes

CMP dword [iBytes],2    ;; if just Enter (2 char) then Exit
JE  Exitloop

DisplayText	hStdOut, msg2, msg2_len, nBytes
DisplayText	hStdOut, buff, iBytes, nBytes

CALL Numeric2Str


DisplayText	hStdOut, msg3, msg3_len, nBytes
DisplayText	hStdOut, strhasil, str_len, nBytes		; DISPLAY RESULT

JMP Again

Exitloop: 
   QuitConsole
	
RET

; Procedure to CONVERT Numeric (iBytes) TO STRING (strhasil) 
;-------------------------------------------------------------------------------------
Numeric2Str: 
   mov ebx, dword buff 
   mov ecx,0
   
   check:
   mov al,byte[ebx]
   cmp al,32
   jne check2
   inc ecx 
   
   
   check2:
   inc ebx
   cmp al,13
   jne check

	mov ebx, strhasil	;; hasil konversi disimpan di strhasil  
 
 loop1:				
	inc ebx				;; ebx digunakan sebagai pointer ke strhasil
	cmp byte[ebx],0		;; diposisikan pada akhir string strhasil 
	je  next
  	mov byte[ebx],' '
    jmp loop1	
next:
	dec ebx
        		
				
	mov eax, [iBytes]	;; panjang string yang dibaca termasuk cr,lf
	sub eax, 2			;; maka panjangnya dikurangi cr,lf (2)
	mov si,10	
	sub eax,ecx
 loop2:				
	xor edx, edx		;; edx di-nolkan untuk menampung sisa bagi
	div si				;; dilakukan pembagian 10 berulang
	add dl, '0'        	;; sisa bagi pada edx (dl) di ubah ke character
	mov [ebx], dl		;; simpan ke strhasil dari belakang ke depan
	dec ebx				;; majukan pointer
	or  eax,eax			;; test apakah yang dibagi sudah nol
	jnz loop2 			;; selesai perulangan jika yang dibagi sdh nol   
    
 stop:
ret

