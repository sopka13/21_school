/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_15.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:28:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:28:17 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_round_x_s1(double x, int alfa, int e)
{
	if (e == 1)
		x = round(x);
	if (alfa > 90 && alfa < 180 && e == 1)
		x = (x >= 1) ? (x - 1) : x;
	if (alfa > 180 && alfa < 270 && e == 1)
		x = (x >= 1) ? (x - 1) : x;
	if (alfa == 180 && e == 1)
		x = (x >= 1) ? (x - 1) : x;
	return (x);
}

int			ft_round_x_s2(double x, int alfa, int e)
{
	if (alfa > 270 && alfa < 360 && e == 1)
		return ((int)x);
	return (x);
}

int			ft_round_y_s1(double y, int alfa, int e)
{
	if (alfa > 270 && alfa < 360 && e == 2)
		return ((int)y);
	return (y);
}

int			ft_round_y_s2(double y, int alfa, int e)
{
	if (e == 2)
		y = round(y);
	if (alfa > 180 && alfa <= 270 && e == 2)
		y = (y >= 1) ? (y - 1) : y;
	if (alfa > 270 && alfa < 360 && e == 2)
		y = (y >= 1) ? (y - 1) : y;
	return (y);
}
