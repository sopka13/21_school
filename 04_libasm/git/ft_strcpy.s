;This function copy first str in second

global ft_strcpy

section .text
ft_strcpy:
	xor rcx, rcx				;RCX = 0

cycle:
	cmp byte[rsi + rcx], 0		;compare str2 and 0
	jz quit						;if str2 == 0 go to quit
	mov dl, byte[rsi + rcx]		;move character in DL
	mov byte[rdi + rcx], dl		;move character from DL in RDI
	inc rcx						;RCX++
	jmp cycle					;repeat cycle

quit:
	mov byte[rdi + rcx], 0		;write \0 in RDI
	mov rax, rdi				;move RDI in RAX
	ret							;return