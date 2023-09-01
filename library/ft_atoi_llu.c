#include "libft.h"

unsigned long long int		ft_atoi_llu(const char *a)
{
	unsigned long long int	q;

	q = 0;
	while ((*a == ' ') || (*a <= 13 && *a >= 7))
		a++;
	if (*a == '+' && *(a + 1) == '-')
		return (0);
	if (*a == '+')
		a++;
	if (*a == '-')
		a++;
	while (*a <= '9' && *a >= '0')
	{
		if (q > 18446744073709551614u)
			return (0);
		q = q * 10 + *a++ - '0';
	}
	return (q);
}
