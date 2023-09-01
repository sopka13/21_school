/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:06:03 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 17:57:23 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_c2(char *a, char b, t_modify *modify, int i)
{
	char	c;

	if (modify->zero > 0)
		c = '0';
	else
		c = ' ';
	if (modify->mns > 0)
	{
		a[i++] = b;
		while (i < modify->num1)
			a[i++] = c;
	}
	else
	{
		while (i < modify->num1 - 1)
			a[i++] = c;
		a[i++] = b;
	}
	return (i);
}

void		ft_c(int *num, t_modify *modify, va_list ap)
{
	char	*a;
	char	b;
	int		i;

	i = 0;
	b = va_arg(ap, int);
	if (modify->num1 > 1)
		a = (char*)malloc(sizeof(char) + modify->num1);
	else
	{
		ft_putchar(b);
		num[0]++;
		num[1]++;
		return ;
	}
	i = ft_c2(a, b, modify, i);
	write(1, a, i);
	num[0] += i;
	free(a);
	num[1]++;
	return ;
}
