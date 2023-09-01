/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:11:25 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 17:11:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_percent(t_modify *modify, int *num)
{
	if (modify->percent == 0)
	{
		modify->percent += 1;
		num[1]++;
		return (1);
	}
	else
		return (0);
}
