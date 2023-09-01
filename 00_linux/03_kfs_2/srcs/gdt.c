#include "../includes/kernel_header.h"

t_gdt_entry	gdt[GDT_SIZE];
t_gdt_ptr	*gdtr = (t_gdt_ptr *)GDT_ADDR;

void	gdt_set_gate(t_gdt_entry *desc,
					uint32_t base,
					uint32_t limit,
					uint8_t access,	// Byte of access
					uint8_t other)	// Flags
{
	desc->limit_low		= (limit & 0xffff);
	desc->base_low		= (base & 0xffff);
	desc->base_middle	= (base & 0xff0000) >> 16;
	desc->access		= access;
	desc->limit			= (limit & 0xf0000) >> 16;
	desc->other			= (other & 0xf);
	desc->base_high		= (base & 0xff000000) >> 24;
}

void	gdt_install()
{
	gdtr->limit = (sizeof(struct gdt_entry) * GDT_SIZE) - 1;
	gdtr->base = (uint32_t)&gdt;

	/*
	gdt_set_gate(&gdt[0], 0, 0, 0, 0);
	gdt_set_gate(&gdt[1], 0, 0xFFFFFFFF, 0x9A, 0xC);		// Code segment
	gdt_set_gate(&gdt[2], 0, 0xFFFFFFFF, 0x92, 0xC);		// Data segment
	gdt_set_gate(&gdt[3], 0, 0xFFFFFFFF, 0x96, 0xC);		// Stack segment

	gdt_set_gate(&gdt[4], 0, 0xFFFFFFFF, 0xFA, 0xC);		// User space code segment
	gdt_set_gate(&gdt[5], 0, 0xFFFFFFFF, 0xF2, 0xC);		// User space data segment
	gdt_set_gate(&gdt[6], 0, 0xFFFFFFFF, 0xF6, 0xC);		// User space stack segment
	*/
	gdt_set_gate(&gdt[0], 0, 0, 0, 0);
	gdt_set_gate(&gdt[1], 0, 0xFFFFFFFF, (uint8_t)(GDT_CODE_PL0), 0xC);		// Code segment
	gdt_set_gate(&gdt[2], 0, 0xFFFFFFFF, (uint8_t)(GDT_DATA_PL0), 0xC);		// Data segment
	gdt_set_gate(&gdt[3], 0, 0xFFFFFFFF, (uint8_t)(GDT_STACK_PL0), 0xC);	// Stack segment

	gdt_set_gate(&gdt[4], 0, 0xFFFFFFFF, (uint8_t)(GDT_CODE_PL3), 0xC);		// User space code segment
	gdt_set_gate(&gdt[5], 0, 0xFFFFFFFF, (uint8_t)(GDT_DATA_PL3), 0xC);		// User space data segment
	gdt_set_gate(&gdt[6], 0, 0xFFFFFFFF, (uint8_t)(GDT_STACK_PL3), 0xC);	// User space stack segment

	/* TSS */
	// gdt_set_gate(&gdt[7], &TSS, sizeof(TSS), 0x89, 0x0);		// TSS segment

	load_gdt(((uint32_t)gdtr));
}
