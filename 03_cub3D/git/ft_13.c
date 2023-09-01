/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:28:05 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:28:06 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_move_left(t_mlx *mlx)
{
	double	cs1;
	double	sn1;

	cs1 = cos(((90 - mlx->sflag->cam.alfa) * M_PI) / 180);
	sn1 = sin(((90 - mlx->sflag->cam.alfa) * M_PI) / 180);
	if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
		[(int)mlx->sflag->cam.x_start] != '1')
	{
		if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
			[(int)mlx->sflag->cam.x_start] != '1')
		{
			mlx->sflag->cam.y_start += (0.15 * sn1);
			mlx->sflag->cam.x_start -= (0.15 * cs1);
		}
		if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
			[(int)mlx->sflag->cam.x_start] == '1')
		{
			mlx->sflag->cam.y_start -= (0.15 * sn1);
			mlx->sflag->cam.x_start += (0.15 * cs1);
		}
	}
	else
		mlx->move.left = 0;
}

void		ft_move_right(t_mlx *mlx)
{
	double	cs1;
	double	sn1;

	cs1 = cos(((90 - mlx->sflag->cam.alfa) * M_PI) / 180);
	sn1 = sin(((90 - mlx->sflag->cam.alfa) * M_PI) / 180);
	if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
		[(int)mlx->sflag->cam.x_start] != '1')
	{
		if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
			[(int)mlx->sflag->cam.x_start] != '1')
		{
			mlx->sflag->cam.y_start -= (0.15 * sn1);
			mlx->sflag->cam.x_start += (0.15 * cs1);
		}
		if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
			[(int)mlx->sflag->cam.x_start] == '1')
		{
			mlx->sflag->cam.y_start += (0.15 * sn1);
			mlx->sflag->cam.x_start -= (0.15 * cs1);
		}
	}
	else
		mlx->move.right = 0;
}

void		ft_move_cam_r(t_mlx *mlx)
{
	if (mlx->sflag->cam.alfa < 360)
		mlx->sflag->cam.alfa -= 3;
	if (mlx->sflag->cam.alfa < 0)
		mlx->sflag->cam.alfa = mlx->sflag->cam.alfa + 360;
}

void		ft_move_cam_l(t_mlx *mlx)
{
	if (mlx->sflag->cam.alfa >= 0)
		mlx->sflag->cam.alfa += 3;
	if (mlx->sflag->cam.alfa >= 360)
		mlx->sflag->cam.alfa = mlx->sflag->cam.alfa - 360;
}
