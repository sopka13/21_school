/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:42:59 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 16:46:10 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*ft_spacep(char *a, t_modify *modify)
{
	while (modify->num1 > modify->num2 && modify->num1 > (int)ft_strlen(a))
	{
		if (modify->mns == 0)
			a = ft_strputst(a, ' ');
		else
			a = ft_strputend(a, ' ');
	}
	return (a);
}

void					ft_p(int *num, t_modify *modify, va_list ap)
{
	char				*a;
	long unsigned int	q;
	char				*b;

	a = va_arg(ap, char*);
	q = (long unsigned int)&(*a);
	a = ft_itoahexunl(q);
	if (q == 0 && modify->dot > 0 && modify->num2 == 0)
	{
		free(a);
		a = ft_strdup("\0");
	}
	while ((modify->num2 > (int)ft_strlen(a) && modify->mns2 == 0) ||
			(modify->zero > 0 && modify->num1 > (int)ft_strlen(a) &&
			modify->num2 == 0))
		a = ft_strputst(a, '0');
	b = a;
	a = ft_strjoin("0x", a);
	free(b);
	a = ft_spacep(a, modify);
	ft_putstr(a);
	num[0] += ft_strlen(a);
	free(a);
	num[1]++;
	return ;
}
