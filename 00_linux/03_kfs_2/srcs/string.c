#include "../includes/kernel_header.h"

size_t	strlen(const char *str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

void	*memset(void *s, int c, size_t n) {
	while (n-- > 0)
		*((unsigned char *)s + n) = (unsigned char)c;
	return (s);
}

void	bzero(void *arr, size_t size) {
	memset(arr, 0x00, size);
}
