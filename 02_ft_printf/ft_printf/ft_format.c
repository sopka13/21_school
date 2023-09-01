/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:55:24 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 17:41:16 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_modify	ft_modify(void)
{
	t_modify modify;

	modify.mns = 0;
	modify.pls = 0;
	modify.zero = 0;
	modify.num1 = 0;
	modify.dot = 0;
	modify.num2 = 0;
	modify.res = 0;
	modify.starprev = 0;
	modify.starpost = 0;
	modify.space = 0;
	modify.percent = 0;
	modify.null = 0;
	modify.mns2 = 0;
	return (modify);
}

int				ft_format(char *str, va_list ap)
{
	int			num[2];
	t_modify	modify;

	ft_bzero(num, (sizeof(int) * 2));
	while (str[num[1]])
	{
		modify = ft_modify();
		if (str[num[1]] != '%')
		{
			ft_putchar(str[num[1]]);
			num[0]++;
			num[1]++;
		}
		else
			ft_printf_1(str, num, &modify, ap);
	}
	return (num[0]);
}
