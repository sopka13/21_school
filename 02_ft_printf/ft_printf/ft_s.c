/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:30:06 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 16:32:18 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_spaces(char *a, t_modify *modify, int i)
{
	while (modify->num1 > ((int)ft_strlen(a) + i))
	{
		if (modify->mns == 0)
			a = ft_strputst(a, ' ');
		else
			a = ft_strputend(a, ' ');
	}
	return (a);
}

void		ft_s(int *num, t_modify *modify, va_list ap)
{
	char	*a;

	a = ft_strdup(va_arg(ap, char*));
	if (!a)
	{
		free(a);
		if (modify->dot == 0 || (modify->dot > 0 && modify->num2 > 0))
			a = ft_strdup("(null)");
		else
			a = ft_strdup("\0");
	}
	if (modify->dot > 0 && modify->num2 < (int)ft_strlen(a) &&
			modify->mns2 == 0)
		a = ft_substr(a, 0, modify->num2);
	a = ft_spaces(a, modify, 0);
	if (a)
		num[0] += ft_putstr(a);
	free(a);
	num[1]++;
	return ;
}
