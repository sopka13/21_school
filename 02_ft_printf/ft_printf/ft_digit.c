/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:00:21 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 17:01:12 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digit(char c, t_modify *modify, int *num)
{
	if (modify->mns2 != 0)
	{
		num[1]++;
		return (1);
	}
	if (c == '0' && modify->dot == 0 && modify->num1 == 0)
	{
		if (modify->zero == 0)
			modify->zero++;
		num[1]++;
		return (1);
	}
	if (modify->dot == 1)
	{
		modify->num2 = (modify->num2 * 10) + (c - '0');
		num[1]++;
		return (1);
	}
	else
	{
		modify->num1 = (modify->num1 * 10) + (c - '0');
		num[1]++;
		return (1);
	}
	return (0);
}
