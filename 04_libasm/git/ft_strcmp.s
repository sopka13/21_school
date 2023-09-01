;This function compare 2 str

global ft_strcmp

section .text
ft_strcmp:
	cmp byte[rdi], 0			;compare rdi and 0
	jz quit_zero				;if rdi == \0 go to quit_zero
	cmp byte[rsi], 0			;compare rsi and 0
	jz quit_zero				;if rsi == \0 go to quit_zero
	xor rcx, rcx				;direction of comparison is ascending 

cycle:
	mov	dl, byte [rdi + rcx]	;move 1 byte from RDX + RCX
	cmp dl, 0					;compare DL and 0
	jz quit_zero				;if rdi == \0 go to quit_zero
	cmp dl, byte[rsi + rcx]		;compare str1 and str2
	jnz quit_zero				;if str1 != str2 go to quit_zero
	inc rcx						;RCX++
	jmp cycle

quit_zero:
	cmp rdi, rsi				;compare first character str1 and str2
	jz equal					;if they are equal
	movzx rax, byte[rdi + rcx]	;move RDI + RCX in RAX
	movzx rdx, byte[rsi + rcx]	;move RSI + RCX in RAX
	sub rax, rdx				;RAX - RDX character str2
	jmp quit					;return

equal:
	xor rax, rax				;return 0

quit:
	ret