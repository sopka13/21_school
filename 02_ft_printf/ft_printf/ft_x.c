/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:46:39 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 17:42:43 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_x(char *str, int *num, t_modify *modify, va_list ap)
{
	unsigned int	x;
	char			*a;

	x = va_arg(ap, unsigned int);
	a = ft_itoahexunl(x);
	if (modify->res > 0 && x != 0)
		modify->num1 -= 2;
	while ((modify->num2 > (int)ft_strlen(a) && modify->mns2 == 0) ||
			(modify->zero > 0 && modify->num1 > (int)ft_strlen(a) &&
			modify->num2 == 0 && modify->dot == 0 && modify->mns == 0))
		a = ft_strputst(a, '0');
	if (modify->res > 0 && x != 0)
	{
		a = ft_strjoin("0x", a);
		modify->num1 += 2;
	}
	a = ft_spaceuns(x, a, modify);
	if (str[num[1]] == 'X')
		a = ft_strtoupper(a);
	ft_putstr(a);
	num[0] += ft_strlen(a);
	free(a);
	num[1]++;
	return ;
}
