%INCLUDE "winAPI.inc"		;;Declare external procedure {winapi}
%INCLUDE "Console1.mac"		;;Macro definition

SEGMENT .DATA use32

Title   	db "Tugas Mikroprosesor Count Word and Char",0

msg1 		db 13,10,"WRITE TEXT (Enter to quit)  : ", 0
msg1_len 	dd $-msg1
msg2 		db 13,10,"YOUR TEXT                   : ", 0
msg2_len 	dd $-msg2
msg3		db 13,10,"CHARACTER COUNT		    : ", 0
msg3_len	dd $-msg3
msg4		db 13,10,"WORD COUNT                  : ", 0
msg4_len	dd $-msg4

buff		resb 255
buff_len	dd 255

res			db '     ', 0
res_len		db 5

SEGMENT .BSS use32
hStdOut		resd 1
hStdIn		resd 1
nBytes		resd 1
iBytes		resd 1

SEGMENT .CODE use32
..start:

NewConsole 	Title, hStdOut, hStdIn

DisplayText	hStdOut, msg1, msg1_len, nBytes
GetText		hStdIn, buff, buff_len, iBytes

CMP dword [iBytes],2
JE  Exit

DisplayText	hStdOut, msg2, msg2_len, nBytes
DisplayText	hStdOut, buff, iBytes, nBytes

CALL CountChar
CALL NumericToString

DisplayText	hStdOut, msg3, msg3_len, nBytes
DisplayText	hStdOut, res, res_len, nBytes

CALL Reset
CALL CountTotalWord
CALL NumericToString

DisplayText	hStdOut, msg4, msg4_len, nBytes
DisplayText	hStdOut, res, res_len, nBytes

CALL Reset

JMP ..start

Exit:
	QuitConsole
	
RET

CountChar:
	MOV EBX, buff
	MOV ECX, [iBytes]
	SUB ECX, 2
	MOV EDI, 0						 ;; count char
	CMP ECX, 0
	JE stop

	start_count_char:
		MOV AL, byte[EBX]
		CMP AL, 0x20	
		JLE next
		INC EDI
		
	next:
		INC EBX	
		loop start_count_char
		
	stop:
RET

CountTotalWord:
	MOV EBX, buff
	MOV ECX, [iBytes]
	CMP ECX, 2
	JE end
	XOR EDI, EDI
	XOR ESI, ESI

	start_count_word:
		MOV AL, byte[EBX]
		CMP AL, 0x20				;; compare if character readable or not
		JLE count_word				;; jump if character not readable ("include space")
		MOV ESI, 1					
		JMP next_char
			
	count_word:
		CMP ESI, 1
		JNE next_char
		ADD EDI, 1					;; count word
		XOR ESI, ESI
	
	next_char:
		INC ebx
		loop start_count_word
			
	end:
RET

NumericToString:
	MOV EBX, res		
	
	loop1:				
		INC EBX						;; EBX digunakan sebagai pointer ke res
		CMP byte[EBX], 0			;; diposisikan pada akhir string res 
		JNE loop1
		DEC EBX    		
				
		MOV EAX, EDI				;; EDI = parameter yang diambil dari hasil counting char/word
		MOV SI, 10		
		
	loop2:				
		XOR EDX, EDX				;; EDX di-nolkan untuk menampung sisa bagi
		DIV SI						;; dilakukan pembagian 10 berulang
		ADD DL, '0'        			;; sisa bagi pada EDX (DL) di ubah ke character
		MOV [EBX], DL				;; simpan ke res dari belakang ke depan
		DEC EBX						;; majukan pointer
		OR  EAX, EAX				;; test apakah yang dibagi sudah nol
		JNZ loop2 					;; selesai perulangan jika yang dibagi sdh nol
RET

Reset:
	MOV EBX, res					
	XOR ECX, ECX
	MOV CL, byte[res_len]
	SUB CL, 1	
	
	reset_loop:
		MOV byte[EBX], 0x20
		INC EBX
		loop reset_loop
RET

