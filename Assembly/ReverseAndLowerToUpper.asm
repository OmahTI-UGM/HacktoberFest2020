%INCLUDE "winAPI.inc"		;;Declare external procedure {winapi}
%INCLUDE "Console1.mac"		;;Macro definition

SEGMENT .DATA use32
Title   	db "Tugas Mikroprosesor Reverse and Lower to Upper",0

msg1 		db 13,10,"WRITE TEXT (Enter to quit)  : ",0
msg1_len 	dd $-msg1
msg2 		db 13,10,"YOUR TEXT                   : ",0
msg2_len 	dd $-msg2
msg3		db 13,10,"REVERSED TEXT               : ",0
msg3_len	dd $-msg3
msg4 		db 13,10,"CONVERTED TEXT              : ",0
msg4_len 	dd $-msg4


buff		resb 255
buff_len	dd 255

str_char	db '     ',0
str_word	db '     ',0
str_len		db 6

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

CALL ReverseString

DisplayText	hStdOut, msg3, msg3_len, nBytes
DisplayText	hStdOut, buff, iBytes, nBytes		; Reversed

CALL LowertoUpper

DisplayText	hStdOut, msg4, msg4_len, nBytes
DisplayText	hStdOut, buff, iBytes, nBytes		; Uppercased

JMP ..start

Exit:
	QuitConsole
	
RET


LowertoUpper:
	MOV ECX, [iBytes]
	SUB ECX, 2
	MOV EBX, dword buff
	
	upper:
		CMP byte[EBX], 0x61
		JL next
		CMP byte[EBX], 0x7A
		JG next
		SUB byte[EBX], 0x20
		INC EBX
		loop upper
		RET
		
	next:
		INC EBX
		DEC ECX
		JNZ upper
		RET
		
ReverseString:
	MOV ECX, [iBytes]
	MOV EBX, dword buff
	SUB ECX, 2
	
	loop1:
		MOV DX, word[EBX]
		XOR DH, DH
		PUSH DX
		INC EBX
		loop loop1
		
	MOV ECX, [iBytes]
	MOV EBX, dword buff
	SUB ECX, 2
	
	loop2:
		POP DX
		XOR DH, DH
		MOV word[EBX], DX
		INC EBX
		loop loop2
		RET
	
		