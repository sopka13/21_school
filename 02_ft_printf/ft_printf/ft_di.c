/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:34:50 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 17:44:02 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_space(int x, char *a, t_modify *modify)
{
	if ((modify->space > 0 && modify->pls == 0 && x >= 0) ||
			(modify->space > 0 && modify->dot > 0 && modify->zero > 0 &&
			modify->pls == 0 && x >= 0))
		a = ft_strputst(a, ' ');
	if (x == 0 && modify->num2 == 0 && modify->dot > 0 &&
			modify->mns2 == 0)
		a = ft_strtrim(a, "0");
	while (modify->num1 > modify->num2 && modify->num1 > (int)ft_strlen(a))
	{
		if (modify->mns == 0)
			a = ft_strputst(a, ' ');
		else
			a = ft_strputend(a, ' ');
	}
	return (a);
}

static char	*ft_di3(int x, char *a, t_modify *modify)
{
	if (x < 0 || modify->pls > 0 || (modify->space > 0 && modify->pls == 0))
	{
		if (x < 0)
			a = ft_strputst(a, '-');
		if ((modify->pls > 0 && modify->dot > 0 && x >= 0) ||
				((int)ft_strlen(a) > 0 && modify->pls > 0 && x >= 0))
			a = ft_strputst(a, '+');
		modify->num1++;
	}
	return (a);
}

int			ft_di(int *num, t_modify *modify, va_list ap)
{
	int		x;
	char	*a;

	x = va_arg(ap, int);
	a = ft_itoa(x);
	if (x == 0 && modify->num1 == 0 && modify->num2 == 0 && modify->zero == 0 &&
			modify->dot > 0 && modify->pls == 0 && modify->space == 0)
		return (num[1]++);
	if (x < 0 || modify->pls > 0 || (modify->space > 0 && modify->pls == 0))
	{
		a = ft_strtrim(a, "-");
		modify->num1--;
	}
	a = ft_di2(a, modify);
	a = ft_di3(x, a, modify);
	a = ft_space(x, a, modify);
	num[0] += ft_putstr(a);
	free(a);
	return (num[1]++);
}
