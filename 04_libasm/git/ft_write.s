;This function write in descriptor

global ft_write
extern __errno_location

section .text
ft_write:
	mov rax, 1					;put sys_write system call
	syscall

	cmp rax, 0					;compare RAX and 0
	jl error
	ret							;return


error:
	neg rax
	push rax					;save RAX (ret status)
	call __errno_location wrt ..plt				;error call
	mov rbx, rax				;get error adress
	pop rax						;get ret status
	mov [rbx], rax				;put error adress
	mov rax, -1					;put -1 in RAX
	ret							;return;