bits 32		;nasm directive - 32 bi

MBALIGN		equ 1 << 0 ;aligns modules on 4Kb pages boundaries
MEMINFO		equ 1 << 1 ;if mem_* is present, include it
FLAGS		equ MBALIGN | MEMINFO
MAGIC		equ 0x1BADB002
CHECKSUM	equ -(MAGIC + FLAGS)

section .multiboot
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

section .bss
align 16
stack_bottom:
	resb 16384
stack_top:

section .text
global start
global set_idt
global test_hello
global load_gdt
extern kmain
extern gdtr
;extern idtr

start:
	cli
	mov	esp, stack_top
	call	kmain
	hlt

;set_idt:
;	lidt	[idtr]
;	ret

load_gdt:
	mov eax, [esp + 4]
	lgdt [eax]

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov ss, ax
	mov gs, ax

	jmp 0x08:.flush
.flush:
	ret

test_hello:
	mov	ax, word [0x07690748]
	mov	word [0xb8000], ax
	ret