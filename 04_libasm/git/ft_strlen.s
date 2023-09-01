;This function counts the number of characters in a string

global ft_strlen

section .text
ft_strlen:
	mov bx, -1					;put start value
cycle:
	inc bx						;RCX++
	cmp BYTE [di + bx], 0		;compare character number and zero
	jne cycle					;if not equal go repeat

exit:
	mov ax, bx				;put result
	ret