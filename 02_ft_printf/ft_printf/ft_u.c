/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:23:28 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 16:38:29 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_u(int *num, t_modify *modify, va_list ap)
{
	int		x;
	char	*a;

	x = va_arg(ap, int);
	a = ft_itoauns(x);
	if (x == 0 && modify->num1 == 0 && modify->num2 == 0 && modify->zero == 0 &&
			modify->dot > 0 && modify->pls == 0 && modify->space == 0)
		return (num[1]++);
	if (modify->pls > 0 || (modify->space > 0 && modify->pls == 0))
		modify->num1--;
	a = ft_di2(a, modify);
	if (modify->pls > 0 || (modify->space > 0 && modify->pls == 0))
	{
		if ((modify->pls > 0 && modify->dot > 0 && x >= 0) ||
				((int)ft_strlen(a) > 0 && modify->pls > 0 && x >= 0))
			a = ft_strputst(a, '+');
		modify->num1++;
	}
	a = ft_spaceuns(x, a, modify);
	num[0] += ft_putstr(a);
	free(a);
	return (num[1]++);
}
