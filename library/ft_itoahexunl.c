/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoahexunl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:35:03 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/11 20:36:38 by eyohn            ###   ########.fr       */
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

static int	ft_num2(unsigned long int l)
{
	int		a;

	a = 0;
	if (l > 0)
	{
		while (l != 0)
		{
			l = l / 16;
			a++;
		}
		a++;
	}
	else
		a = 2;
	return (a);
}

char		*ft_itoahexunl(unsigned long int n)
{
	char	*p;
	int		num;

	num = ft_num2(n);
	p = malloc(sizeof(char) * num);
	if (!p)
		return (NULL);
	p[--num] = '\0';
	while (num--)
	{
		p[num] = ft_hex(n % 16);
		n /= 16;
	}
	return (p);
}
