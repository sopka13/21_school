/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoahex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:31:37 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/11 20:33:01 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_hex(int n)
{
	if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else if (n == 15)
		return ('f');
	else
		return (n + '0');
}

static int	ft_num(int k)
{
	int		i;

	i = 0;
	while (k != 0)
	{
		k = k / 16;
		i++;
	}
	return (i);
}

static int	ft_num2(int l)
{
	int		a;

	if (l < 0)
		a = ft_num(l) + 2;
	else if (l > 0)
		a = ft_num(l) + 1;
	else
		a = 2;
	return (a);
}

char		*ft_itoahex(int n)
{
	char	*p;
	int		m;
	int		num;

	m = 0;
	num = ft_num2(n);
	if (n < 0)
		m++;
	p = malloc(sizeof(char) * num);
	if (!p)
		return (NULL);
	p[--num] = '\0';
	while (num--)
	{
		p[num] = ft_hex(n % 16);
		n /= 16;
	}
	if (m)
		p[0] = '-';
	return (p);
}
