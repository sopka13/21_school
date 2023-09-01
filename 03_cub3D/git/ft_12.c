/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_12.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:27:59 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:28:01 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_key_release(int keycode, t_mlx *mlx)
{
	if (keycode == 119)
		mlx->move.forward = 0;
	else if (keycode == 115)
		mlx->move.back = 0;
	else if (keycode == 97)
		mlx->move.left = 0;
	else if (keycode == 100)
		mlx->move.right = 0;
	else if (keycode == 65361)
		mlx->move.cam_l = 0;
	else if (keycode == 65363)
		mlx->move.cam_r = 0;
	return (0);
}

void		my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void		ft_move_forward(t_mlx *mlx)
{
	double	cs;
	double	sn;

	cs = cos((mlx->sflag->cam.alfa * M_PI) / 180);
	sn = sin((mlx->sflag->cam.alfa * M_PI) / 180);
	if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
		[(int)mlx->sflag->cam.x_start] != '1')
	{
		if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
			[(int)mlx->sflag->cam.x_start] != '1')
		{
			mlx->sflag->cam.y_start += 0.15 * (sn);
			mlx->sflag->cam.x_start += 0.15 * (cs);
		}
		if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
			[(int)mlx->sflag->cam.x_start] == '1')
		{
			mlx->sflag->cam.y_start -= 0.15 * (sn);
			mlx->sflag->cam.x_start -= 0.15 * (cs);
		}
	}
	else
		mlx->move.forward = 0;
}

void		ft_move_back(t_mlx *mlx)
{
	double	cs;
	double	sn;

	cs = cos((mlx->sflag->cam.alfa * M_PI) / 180);
	sn = sin((mlx->sflag->cam.alfa * M_PI) / 180);
	if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
		[(int)mlx->sflag->cam.x_start] != '1')
	{
		if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
			[(int)mlx->sflag->cam.x_start] != '1')
		{
			mlx->sflag->cam.y_start -= 0.15 * (sn);
			mlx->sflag->cam.x_start -= 0.15 * (cs);
		}
		if (mlx->sflag->map[(int)mlx->sflag->cam.y_start]
			[(int)mlx->sflag->cam.x_start] == '1')
		{
			mlx->sflag->cam.y_start += 0.15 * (sn);
			mlx->sflag->cam.x_start += 0.15 * (cs);
		}
	}
	else
		mlx->move.back = 0;
}
