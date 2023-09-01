#include "../includes/kernel_header.h"

size_t		terminal_row;				// Current row of terminal
size_t		terminal_column;			// Current column of terminal
uint8_t		terminal_font_color;		// Current font color
uint8_t		terminal_background_color;	// Current background color
uint8_t		terminal_color;				// Current color of terminal
uint16_t*	terminal_buffer;			// Buffer of terminal

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}

void	terminal_initialize(void) {
	/* Clean terminal */
	terminal_row = 0;
	terminal_column = 0;
	if(terminal_font_color == 0)
		terminal_font_color = VGA_COLOR_LIGHT_GREEN;
	terminal_color = vga_entry_color(terminal_font_color,
									 terminal_background_color);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void	terminal_set_font_color(uint8_t color) {
	/* Set color for font */
	terminal_color = vga_entry_color(color, terminal_color >> 4);
	return ;
}

void	terminal_set_background_color(uint8_t color) {
	/* Set color for background */
	terminal_color = vga_entry_color(terminal_color & 0x0F, color);
	return ;
}

void	terminal_setcolor(uint8_t color) {
	/* Set color for font and background */
	terminal_color = color;
}

void	terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
	/* Put char in received position */
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void	terminal_putchar(char c) {
	/* Put char to terminal */
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}

void	terminal_write(const char* data, size_t size) {
	/* Put received number of characters to terminal */
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void	terminal_writestring(const char* data) {
	/* Put string to terminal */
	terminal_write(data, strlen(data));
}

void	terminal_put_new_line(void) {
	terminal_column = 0;
	if (++terminal_row == VGA_HEIGHT)
		terminal_row = 0;
}