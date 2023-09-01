/**
 * printk
 * type specifiers:
 * %% - single '%';
 * + %c - ARGUMENT wide character;
 * + %C - ARGUMENT single-byte character;
 * + %d - ARGUMENT signed decimal integer;
 * + %i - ARGUMENT signed decimal integer;
 * %o - ARGUMENT signed octal integer;
 * + %u - ARGUMENT unsigned decimal integer;
 * + %x - ARGUMENT unsigned hexadecimal integer; uses "abcdef";
 * + %X - ARGUMENT unsigned hexadecimal integer; uses "ABCDEF";
 * %e
 * %E
 * %f
 * %F
 * %g
 * %G
 * %a
 * %A
 * %n
 * %p - ARGUMENT address in hexadecimal digits;
 * + %s - ARGUMENT wide-character string;
 * + %S - ARGUMENT multi-byte character string;
 * %Z
 *
 * format-type specifiers:
 * l:	long double:			with types: a, A, e, E, f, F, g, G.
 * 		long int
 * 		long unsigned int:		with types: d, i, o, u, x, X.
 * ll:	long long int
 * 		long long unsigned int:	with types: d, i, o, u, x, X.
 *
 * special chars:
 * \n:	new line;
 * \t:	tab;
 *
 * Backlog:
 * 1. Add handle special chars in args ('\n', '\t' ...)
 * 2. Add handle special chars ('\a', '\b' ...)
 */


#include "../includes/kernel_header.h"

static char		sg_print_buff[PRINT_BUFF_SIZE + 1];
static uint16_t	sg_fill_print_buff;
static va_list	sg_args;
static uint64_t	sg_pos_number;

enum type_specifiers{
	c, C, d, i, o, u, x, X, e, E,
	f, F, g, G, a, A, n, p, s, S,
	Z, prc, zero
};

static int	string_handler(char *str);
static int	int_handler(int a);
static int	uint_handler(unsigned int a);
static int	pointer_handler(unsigned int a);
static int	hex_uint_handler(unsigned int a, bool upper);
static int	percent_handler(const char *str);
static int	slash_handler(const char *str);
static void	flush_print_buffer(void);
static void	put_end_char(char *target, char a);
static int	char_handler(const char *str);
static int	spec_char_handler(char a);
static void	put_new_line(void);
static void	put_tab(void);
static void	error_handler(void);
static void	clear_static_vars(void);
size_t		printk(const char *str, ...);

static void	put_new_line(void) {
	flush_print_buffer();
	terminal_put_new_line();
	return ;
}

static void	put_tab(void) {
	for(int i = 0; i < env_vars.tab_size; i++)
		put_end_char(sg_print_buff, ' ');
}

static int	spec_char_handler(char a) {
	switch (a) {
		case '\a':
			break;
		case '\b':
			break;
		case '\t':
			put_tab();
			break;
		case '\n':
			put_new_line();
			break;
		case '\v':
			break;
		case '\f':
			break;
		case '\r':
			break;
		default:
			break;
	}
	return 0;
}

static int	string_handler(char *str) {
	/* Handler for string args */
	int	ret;

	ret = strlen(str);
	for(size_t i = 0; i < ret; i++){
		if(str[i] < 32 || str[i] > 126)	// For special chars
			spec_char_handler(str[i]);
		put_end_char(sg_print_buff, str[i]);
	}

	return ret;
}

static int	char_arg_handler(char a) {
	if (a < 32 || a > 126)
		spec_char_handler(a);
	else
		put_end_char(sg_print_buff, a);
	return 1;
}

static void	set_error_msg(const char *str) {
	for(int i = 0; str[i]; i++)
		g_vars.error_msg[i] = str[i];
	return ;
}

static int	int_handler(int a) {
	size_t	ret;

	if(itoa_int(a)) {								// Error handle
		set_error_msg("printk: itoa_int error.");
		g_vars.ret_value = -1;
		return ERROR;
	}
	ret = string_handler(g_inter_buff);
	bzero (g_inter_buff, INTER_BUFF_1024);

	return ret;
}

static int	uint_handler(unsigned int a) {
	size_t	ret;

	if(itoa_uint(a)) {								// Error handle
		set_error_msg("printk: itoa_uint error.");
		g_vars.ret_value = -1;
		return ERROR;
	}
	ret = string_handler(g_inter_buff);
	bzero (g_inter_buff, INTER_BUFF_1024);

	return ret;
}

static int	pointer_handler(unsigned int a) {
	size_t	ret;

	if(itoa_pointer(a)) {								// Error handle
		set_error_msg("printk: itoa_pointer error.");
		g_vars.ret_value = -1;
		return ERROR;
	}
	ret = string_handler(g_inter_buff);
	bzero (g_inter_buff, INTER_BUFF_1024);

	return ret;
}

static int	hex_uint_handler(unsigned int a, bool upper) {
	size_t	ret;

	if(itoa_hex_uint(a, upper)) {								// Error handle
		set_error_msg("printk: itoa_hex error.");
		g_vars.ret_value = -1;
		return ERROR;
	}
	ret = string_handler(g_inter_buff);
	bzero (g_inter_buff, INTER_BUFF_1024);

	return ret;
}

static int	percent_handler(const char *str) {
	/* Handle % character */
	enum	type_specifiers type;
	int		ret = 0;
	int		tmp = 0;

	switch (str[sg_pos_number + 1]) {
	case 'c':
		sg_pos_number += 1;
		ret += char_arg_handler((char)va_arg(sg_args, int));
		break;
	case 'C':
		sg_pos_number += 1;
		ret += char_arg_handler((char)va_arg(sg_args, int));
		break;
	case 'd':
		sg_pos_number += 1;
		if((tmp = int_handler(va_arg(sg_args, int))) == ERROR)
			goto error;
		else
			ret += tmp;
		break;
	case 'i':
		sg_pos_number += 1;
		if((tmp = int_handler(va_arg(sg_args, int))) == ERROR)
			goto error;
		else
			ret += tmp;
		break;
	case 'o':
		type = o;
		break;
	case 'u':
		sg_pos_number += 1;
		if((tmp = uint_handler(va_arg(sg_args, unsigned int))) == ERROR)
			goto error;
		else
			ret += tmp;
		break;
	case 'x':
		sg_pos_number += 1;
		ret += hex_uint_handler(va_arg(sg_args, unsigned int), 0);
		break;
	case 'X':
		sg_pos_number += 1;
		ret += hex_uint_handler(va_arg(sg_args, unsigned int), 1);
		break;
	case 'e':
		type = e;
		break;
	case 'E':
		type = E;
		break;
	case 'f':
		type = f;
		break;
	case 'F':
		type = F;
		break;
	case 'g':
		type = g;
		break;
	case 'G':
		type = G;
		break;
	case 'a':
		type = a;
		break;
	case 'A':
		type = A;
		break;
	case 'n':
		type = n;
		break;
	case 'p':
		sg_pos_number += 1;
		ret += pointer_handler(va_arg(sg_args, unsigned int));
		break;
	case 's':
		sg_pos_number += 1;
		ret += string_handler(va_arg(sg_args, char *));
		break;
	case 'S':
		sg_pos_number += 1;
		ret += string_handler(va_arg(sg_args, char *));
		break;
	case 'Z':
		type = Z;
		break;
	case '%':
		type = prc;
		break;
	default:
		put_end_char(sg_print_buff, '%');
		ret = 1;
		sg_pos_number += (str[sg_pos_number + 1] == '%') ? 1 : 0;
		break;
	}
	return ret;

error:
	return ERROR;
}

static int	slash_handler(const char *str) {
	/* For shelding */
	switch (str[sg_pos_number + 1]) {
	case '\\':
		break;
	case 'a':
		break;
	case 'b':
		break;
	case 't':
		break;
	case 'n':
		break;
	case 'v':
		break;
	case 'f':
		break;
	case 'r':
		break;
	default:
		break;
	}
	terminal_putchar(str[sg_pos_number]);
	return 1;
}

static void	flush_print_buffer(void) {
	terminal_writestring (sg_print_buff);
	bzero(sg_print_buff, PRINT_BUFF_SIZE);
	sg_fill_print_buff = 0;
}

static void	put_end_char(char *target, char a) {
	if(sg_fill_print_buff == PRINT_BUFF_SIZE)
		flush_print_buffer();
	target[sg_fill_print_buff] = a;
	sg_fill_print_buff++;
}

static int	char_handler(const char *str) {
	if (str[sg_pos_number] < 32 || str[sg_pos_number] > 126)
		spec_char_handler(str[sg_pos_number]);
	else
		put_end_char(sg_print_buff, str[sg_pos_number]);
	return 1;
}

static void	error_handler(void) {
	terminal_writestring(g_vars.error_msg);
	clear_static_vars();
}

static void	clear_static_vars(void) {
	bzero (sg_print_buff, PRINT_BUFF_SIZE);
	sg_fill_print_buff = 0;
	sg_pos_number = 0;
}

size_t		printk(const char *str, ...) {
	size_t					ret = 0;
	int						tmp = 0;
	enum type_specifiers	type = zero;

	va_start(sg_args, str);
	for (sg_pos_number = 0; str[sg_pos_number]; sg_pos_number++){
		//terminal_putchar(str[sg_pos_number]);
		switch (str[sg_pos_number]) {
			case '%':
				if((tmp = percent_handler(str)) == ERROR)
					goto error;
				else
					ret += tmp;
				break;
			default:
				ret += char_handler(str);
				break;
			}
	}
	//terminal_putchar('#');
	//char *temp = va_arg(sg_args, char *);
	terminal_writestring(sg_print_buff);
	va_end(sg_args);

	clear_static_vars();
	return ret;
error:
	error_handler();
	return g_vars.ret_value;
}
