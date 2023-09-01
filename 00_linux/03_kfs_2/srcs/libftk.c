#include "../includes/kernel_header.h"

static size_t	get_len_int(int a);
static size_t	get_len_uint(unsigned int a);
int				itoa_int(int a);
int				itoa_uint(unsigned int a);
int				itoa_pointer(unsigned int a);
int				itoa_hex(unsigned int a, bool upper);

static size_t	get_len_int(int a) {
	size_t	len = 0;
	for(; a; a /= 10)
		len++;
	return len;
}

int				itoa_int(int a) {
	/* Get string from int
	 * the result of the work is placed in the global buffer
	 */
	size_t	len;
	int		sign;

	sign = (a < 0) ? -1 : 1;
	len = (a > 0) ? get_len_int(a) : get_len_int(a) + 1;
	if(sign == -1)
		a *= -1;
	for(size_t i = 1; a; i++) {
		g_inter_buff[len - i] = a % 10 + '0';
		a /= 10;
	}
	if (sign < 0)
		g_inter_buff[0] = '-';

	return SUCCESS;
}

static size_t	get_len_uint(unsigned int a) {
	size_t	len = 0;
	for(; a; a /= 10)
		len++;
	return len;
}

int		itoa_uint(unsigned int a) {
	/* Get string from unsigned int
	 * the result of the work is placed in the global buffer
	 */
	size_t	len;

	len = get_len_uint(a);
	for(size_t i = 1; a; i++) {
		g_inter_buff[len - i] = a % 10 + '0';
		a /= 10;
	}

	return SUCCESS;
}

int		itoa_pointer(unsigned int a) {
	/* Get pointer from unsigned int
	 * the result of the work is placed in the global buffer
	 */
	size_t	len = 10;
	char	tmp_buf[len];

	memset(tmp_buf, '0', len);
	for(size_t i = 1; a; i++) {
		int tmp = a % 16;
		switch (tmp) {
			case 10:
				tmp_buf[len - i] = 'a';
				break;
			case 11:
				tmp_buf[len - i] = 'b';
				break;
			case 12:
				tmp_buf[len - i] = 'c';
				break;
			case 13:
				tmp_buf[len - i] = 'd';
				break;
			case 14:
				tmp_buf[len - i] = 'e';
				break;
			case 15:
				tmp_buf[len - i] = 'f';
				break;
			default:
				tmp_buf[len - i] = tmp + '0';
				break;
		}
		a /= 16;
	}
	tmp_buf[1] = 'x';
	for(int i = 0; i < len; i++)
		g_inter_buff[i] = tmp_buf[i];

	return SUCCESS;
}

int				itoa_hex_uint(unsigned int a, bool upper) {
	/* Create hex from unsigned int
	 * the result of the work is placed in the global buffer
	 */
	size_t	len = 8;
	char	tmp_buf[len];

	bzero (tmp_buf, 8);
	if(a == 0)
		tmp_buf[0] = '0';
	for(size_t i = 0; a; i++) {
		int tmp = a % 16;
		switch (tmp) {
			case 10:
				tmp_buf[i] = upper ? 'A' : 'a';
				break;
			case 11:
				tmp_buf[i] = upper ? 'B' : 'b';
				break;
			case 12:
				tmp_buf[i] = upper ? 'C' : 'c';
				break;
			case 13:
				tmp_buf[i] = upper ? 'D' : 'd';
				break;
			case 14:
				tmp_buf[i] = upper ? 'E' : 'e';
				break;
			case 15:
				tmp_buf[i] = upper ? 'F' : 'f';
				break;
			default:
				tmp_buf[i] = tmp + '0';
				break;
		}
		a /= 16;
	}
	len = strlen(tmp_buf);
	for(int i = 0; i < len; i++)
		g_inter_buff[i] = tmp_buf[len - i - 1];

	return SUCCESS;
}
