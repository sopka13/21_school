#ifndef KERNEL_HEADER_H
# define KERNEL_HEADER_H

/* ------------------------------
 * Std headers
 * ------------------------------*/
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

/* ------------------------------
 * Defines
 * ------------------------------*/
#define SEG_DESCTYPE(x)  ((x) << 0x04) // Descriptor type (0 for system, 1 for code/data)
#define SEG_PRES(x)      ((x) << 0x07) // Present
#define SEG_SAVL(x)      ((x) << 0x0C) // Available for system use
#define SEG_LONG(x)      ((x) << 0x0D) // Long mode
#define SEG_SIZE(x)      ((x) << 0x0E) // Size (0 for 16-bit, 1 for 32)
#define SEG_GRAN(x)      ((x) << 0x0F) // Granularity (0 for 1B - 1MB, 1 for 4KB - 4GB)
#define SEG_PRIV(x)     (((x) &  0x03) << 0x05)   // Set privilege level (0 - 3)

#define SEG_DATA_RD        0x00 // Read-Only
#define SEG_DATA_RDA       0x01 // Read-Only, accessed
#define SEG_DATA_RDWR      0x02 // Read/Write
#define SEG_DATA_RDWRA     0x03 // Read/Write, accessed
#define SEG_DATA_RDEXPD    0x04 // Read-Only, expand-down
#define SEG_DATA_RDEXPDA   0x05 // Read-Only, expand-down, accessed
#define SEG_DATA_RDWREXPD  0x06 // Read/Write, expand-down
#define SEG_DATA_RDWREXPDA 0x07 // Read/Write, expand-down, accessed
#define SEG_CODE_EX        0x08 // Execute-Only
#define SEG_CODE_EXA       0x09 // Execute-Only, accessed
#define SEG_CODE_EXRD      0x0A // Execute/Read
#define SEG_CODE_EXRDA     0x0B // Execute/Read, accessed
#define SEG_CODE_EXC       0x0C // Execute-Only, conforming
#define SEG_CODE_EXCA      0x0D // Execute-Only, conforming, accessed
#define SEG_CODE_EXRDC     0x0E // Execute/Read, conforming
#define SEG_CODE_EXRDCA    0x0F // Execute/Read, conforming, accessed

#define GDT_CODE_PL0	SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
			SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
			SEG_PRIV(0)     | SEG_CODE_EXRD

#define GDT_DATA_PL0	SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
			SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
			SEG_PRIV(0)     | SEG_DATA_RDWR

#define GDT_STACK_PL0	SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
			SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
			SEG_PRIV(0)     | SEG_DATA_RDWREXPD

#define GDT_CODE_PL3	SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
			SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
			SEG_PRIV(3)     | SEG_CODE_EXRD

#define GDT_DATA_PL3	SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
			SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
			SEG_PRIV(3)     | SEG_DATA_RDWR

#define GDT_STACK_PL3	SEG_DESCTYPE(1) | SEG_PRES(1) | SEG_SAVL(0) | \
			SEG_LONG(0)     | SEG_SIZE(1) | SEG_GRAN(1) | \
			SEG_PRIV(3)     | SEG_DATA_RDWREXPD

#define GDT_ADDR				0x00000800	// GDT addr
#define GDT_SIZE				7			// GDT size
#define VGA_WIDTH				80			// Number of columns
#define VGA_HEIGHT				25			// Number of str
#define PRINT_BUFF_SIZE			4096		// printk buffer size
#define INTER_BUFF_1024			1024		// Interfunctional buffer
#define ERROR_MSG_LIMIT_SIZE	128			// Limit for error message
#define SUCCESS					0			// Success result
#define ERROR					-1			// Result with error

#define GET_STACK_POINTER(x)	asm volatile("mov %%esp, %0" : "=r"(x) ::)
#define GET_STACK_FRAME(x)		asm volatile("mov %%ebp, %0" : "=r"(x) ::)

/* ------------------------------
 * Types
 * ------------------------------*/
// kmain.c
typedef struct				env_variables {
	uint8_t					tab_size;			// Size of tabs
} __attribute__((packed))	t_env_vars;

typedef struct		global_vars {
	uint8_t			ret_value;							// Return value
	char			error_msg[ERROR_MSG_LIMIT_SIZE];	// Err msg buffer
}					t_global_vars;

// gdt.c
typedef struct		gdt_entry {
	uint16_t		limit_low;				// 0..15	| 1
	uint16_t		base_low;				// 0..15	| 2
	uint8_t			base_middle;			// 16..23	| 1
	uint8_t			access;					// 24..31	| 1
	uint8_t			limit:4;				// 16..19	| 2
	uint8_t			other:4;				// 20..23	| 2
	uint8_t			base_high;				// 24..31	| 2
} __attribute__((packed)) t_gdt_entry;

typedef struct		gdt_ptr {
	uint16_t		limit;
	uint32_t		base;
} __attribute__((packed)) t_gdt_ptr;

// idt.c
typedef struct		idt_entry_struct {
   uint16_t			base_lo;             // Младшие 16 битов адреса, куда происходи переход в случае возникновения прерывания.
   uint16_t			sel;                 // Переключатель сегмента ядра.
   uint8_t			always0;             // Это значение всегда должно быть нулевым.
   uint8_t			flags;               // More flags. See documentation.
   uint16_t			base_hi;             // Старшие 16 битов адреса, куда происходи переход.
} __attribute__((packed)) t_idt_entry_struct;

typedef struct		idt_ptr_struct {
   uint16_t			limit;
   uint32_t			base;                // Адрес первого элемента нашего массива idt_entry_t.
} __attribute__((packed)) t_idt_ptr_struct;

// printk.c
typedef struct		ft_specifiers {
	uint16_t		pre_dot;			// Number before dot
	uint16_t		post_dot;			// Number after dot
	bool			dot;				// If have dot
	bool			positive;			// If have negative sign
	bool			negative;			// If have positive sign
}					t_ft_specifiers;

// terminal.c
enum	vga_color {
		VGA_COLOR_BLACK = 0,
		VGA_COLOR_BLUE = 1,
		VGA_COLOR_GREEN = 2,
		VGA_COLOR_CYAN = 3,
		VGA_COLOR_RED = 4,
		VGA_COLOR_MAGENTA = 5,
		VGA_COLOR_BROWN = 6,
		VGA_COLOR_LIGHT_GREY = 7,
		VGA_COLOR_DARK_GREY = 8,
		VGA_COLOR_LIGHT_BLUE = 9,
		VGA_COLOR_LIGHT_GREEN = 10,
		VGA_COLOR_LIGHT_CYAN = 11,
		VGA_COLOR_LIGHT_RED = 12,
		VGA_COLOR_LIGHT_MAGENTA = 13,
		VGA_COLOR_LIGHT_BROWN = 14,
		VGA_COLOR_WHITE = 15,
};

/* ------------------------------
 * Global vars
 * ------------------------------*/

// kmain.c
extern char	g_inter_buff[INTER_BUFF_1024];
extern t_global_vars	g_vars;
extern t_env_vars		env_vars;

// terminal.c
extern size_t			terminal_row;		// Current row of terminal
extern size_t			terminal_column;	// Current column of terminal
extern uint8_t			terminal_color;		// Current color of terminal
extern uint16_t			*terminal_buffer;	// Buffer of terminal

// gdt.c
extern t_gdt_entry			gdt[GDT_SIZE];
extern t_gdt_ptr			*gdtr;
extern t_idt_entry_struct	idt_entries[256];
extern t_idt_ptr_struct		idtr;

// printk.c

/* ------------------------------
 * Functions
 * ------------------------------*/
// kmain.c
void					kmain(void);

// printk.c
size_t					printk(const char *str, ... );

// terminal.c
static inline uint8_t	vga_entry_color(enum vga_color fg, enum vga_color bg);
static inline uint16_t	vga_entry(unsigned char uc, uint8_t color);
void					terminal_initialize(void);
void					terminal_setcolor(uint8_t color);
void					terminal_putentryat(char c,
											uint8_t color,
											size_t x,
											size_t y);
void					terminal_putchar(char c);
void					terminal_write(const char* data, size_t size);
void					terminal_writestring(const char* data);
void					terminal_set_font_color(uint8_t color);
void					terminal_set_background_color(uint8_t color);
void					terminal_put_new_line(void);

// string.c
size_t		strlen(const char *str);
void		*memset(void *s, int c, size_t n);
void		bzero(void *arr, size_t size);

// gdt.c
void		gdt_set_gate(t_gdt_entry *desc,
						 uint32_t base,
						 uint32_t limit,
						 uint8_t access,
						 uint8_t other);
void		gdt_install(void);

// kernel.asm
extern void		start();
extern void		set_gdt();
extern void		set_idt();
extern void		reload_segments();
extern void		test_hello();
extern void		load_gdt(uint32_t gdt_ptr);

// libftk.c
int				itoa_int(int a);
int				itoa_uint(unsigned int a);
int				itoa_pointer(unsigned int a);
int				itoa_hex_uint(unsigned int a, bool upper);

#endif
