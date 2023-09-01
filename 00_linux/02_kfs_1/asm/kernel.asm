bits 32								;nasm directive - 32 bit
section .text
		;multiboot specification for grub
		align	4
		dd		0x1BADB002			;magic number
		dd		0x00				;flags? dont need in this project
		dd - (0x1BADB002 + 0x00)	;checksum. m+f+c should be zero


global start						;directive for entry point
extern kmain						;our func in .c file

start:								;start function
	cli								;block interrupts
	mov esp, stack_space			;set stack pointer
	call kmain
	hlt								;halt the CPU

section .bss
resb 8192							;reserve 8KB for stack
stack_space: