;This function read id descriptor

global ft_read
extern __errno_location

section .text
ft_read:
	mov rax, 0					;put sys_read system call
	syscall						;kernel call

	cmp rax, 0					;compare RAX and 0
	jl error
	ret							;return


error:
	neg rax
	push rax					;save RAX (ret status)
	call __errno_location wrt ..plt		;error call
	mov rbx, rax				;get error adress
	pop rax						;get ret status
	mov [rbx], rax				;put error adress
	mov rax, -1					;put -1 in RAX
	ret							;return;