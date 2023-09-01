/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_relative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:53:04 by eyohn             #+#    #+#             */
/*   Updated: 2020/12/12 16:55:14 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_relative(char c, t_modify *modify, int *num)
{
	if (c == ' ')
		return (ft_flag_space(modify, num));
	if (c == '-')
		return (ft_flag_mns(modify, num));
	if (c == '+')
		return (ft_flag_pls(modify, num));
	if (c == '#')
		return (ft_flag_res(modify, num));
	if (c == '.')
		return (ft_flag_dot(modify, num));
	if (c == '%')
		return (ft_flag_percent(modify, num));
	if (ft_isdigit(c))
		return (ft_digit(c, modify, num));
	return (0);
}
