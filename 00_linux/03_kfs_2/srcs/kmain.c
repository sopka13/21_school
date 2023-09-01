#include "../includes/kernel_header.h"

char			g_inter_buff[INTER_BUFF_1024];
t_env_vars		env_vars;
t_global_vars	g_vars;

void	init_vars() {
	env_vars.tab_size			= 4;
	//env_vars.print_buff_size	= 10;//4096;
}

static void	print_stack(void) {
	/* Show stack content
	 * addr: value in hex : display with char
	 */
	int	esp;
	int	ebp;
	int lines;

	GET_STACK_POINTER(esp);
	GET_STACK_FRAME(ebp);
	lines = (((ebp - esp) % 16) > 0) ? ((ebp - esp) / 16) + 1
			: (ebp - esp) / 16;
	printk("stack pointer: %p\n", esp);
	printk("stack frame: %p\n", ebp);
	for (int i = 0; i < lines; i++) {
		printk("%p: ", esp + (i * 16));
		for (int k = 0; k < 16; k++) {
			printk("%X ", *((uint8_t *)esp + k));
		}
		printk("\n");
		esp += (i * 16);
	}
}

static void temp_func(int arg_1, char arg_2) {
	printk("temp_func start with args_1 = %d, arg_2 = '%c'\n", arg_1, arg_2);
	print_stack();
}

void	kmain(void) {
  	/* Install GDT */
	gdt_install();

	/* Init environment variables */
	init_vars();

	/* Initialize terminal interface */
	terminal_initialize();

	// for(unsigned char i = 31; i < 128; i ++)
	// 	terminal_putchar(i);

	//terminal_writestring("Hello");
	print_stack();
	temp_func(12, 'B');
	print_stack();
	//printk("|\n|");
	//printk("\n");
	//printk("123");

	//test_hello();

	/* Newline support is left as an exercise. */
	//terminal_writestring("Hello, kernel World!\n");
	//while(1);
	return ;
}
