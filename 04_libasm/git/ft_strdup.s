;This function allocates memory and write str

global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc
extern __errno_location

section .text
ft_strdup:
	push rdi					;save str adress
	call ft_strlen				;get leigth str in RAX
	inc rax						;RAX++
	mov rdi, rax				;move RAX in RDI for malloc
	call malloc wrt ..plt		;system call malloc
	cmp rax, 0					;if return NULL
	jz error					;go to error
	mov rdi, rax				;move RAX in RDI for ft_strcpy
	pop rsi						;get str1 from stack
	call ft_strcpy				;call ft_strcpy
	ret

error:
	neg rax
	push rax					;save RAX (ret status)
	call __errno_location wrt ..plt				;error call
	mov rbx, rax				;get error adress
	pop rax						;get ret status
	mov [rbx], rax				;put error adress
	mov rax, 0					;put 0 in RAX
	ret							;return;