/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:01:20 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 17:02:34 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_percent(int *num, t_modify *modify)
{
	char	*a;

	a = (char *)malloc(sizeof(char) * 2);
	if (!a)
		return (-1);
	a[0] = '%';
	a[1] = '\0';
	while (modify->num1 > (int)ft_strlen(a))
	{
		if (modify->mns > 0)
		{
			if (modify->zero > 0 && modify->mns == 0)
				a = ft_strputend(a, '0');
			else
				a = ft_strputend(a, ' ');
			continue;
		}
		if (modify->zero > 0 && modify->mns == 0)
			a = ft_strputst(a, '0');
		else
			a = ft_strputst(a, ' ');
	}
	num[0] += ft_putstr(a);
	free(a);
	return (num[1]++);
}
