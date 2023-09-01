/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_14.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:28:10 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:28:11 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int			ft_move(t_mlx *mlx)
{
	if (mlx->move.forward == 1)
		ft_move_forward(mlx);
	if (mlx->move.back == 1)
		ft_move_back(mlx);
	if (mlx->move.left == 1)
		ft_move_left(mlx);
	if (mlx->move.right == 1)
		ft_move_right(mlx);
	if (mlx->move.cam_r == 1)
		ft_move_cam_r(mlx);
	if (mlx->move.cam_l == 1)
		ft_move_cam_l(mlx);
	return (0);
}

double		ft_grad(t_mlx *mlx, double i)
{
	double	a;

	a = mlx->sflag->cam.alfa + i - (VI_GRAD / 2);
	while (a < 0.0)
		a += 360.0;
	while (a >= 360.0)
		a -= 360.0;
	return (a);
}

double		ft_alfa(t_mlx *mlx, int d)
{
	double	a;
	double	b;
	double	c;

	a = ZOOM;
	b = 0;
	c = 0;
	if (d == 1)
		c = (mlx->sflag->cam.x_max - mlx->sflag->cam.x_start + 2) * ZOOM * 40;
	if (d == 2)
		c = mlx->sflag->cam.y_start * ZOOM * 40;
	if (d == 3)
		c = mlx->sflag->cam.x_start * ZOOM * 40;
	if (d == 4)
		c = (mlx->sflag->cam.y_max - mlx->sflag->cam.y_start + 2) * ZOOM * 40;
	b = sqrt(pow(a, 2) + pow(c, 2));
	return ((acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) /
			(2 * b * c)) * 180) / M_PI);
}

int			ft_return_colour(t_mlx *mlx, t_dt data)
{
	return (*(unsigned int*)(mlx->sprite.addr + ((int)fabs((mlx->sflag->i1 - ((
		mlx->sflag->ry - data.wall) / 2)) / (data.wall / mlx->sprite.height))
		* mlx->sprite.ll + (int)(data.coord * mlx->sprite.width) *
		(mlx->sprite.bpp / 8))));
}

int			ft_colour(t_mlx *mlx, int i, int e, t_dt data)
{
	if (e == 0)
		return (ft_return_colour(mlx, data));
	else if (((ft_grad(mlx, i) >= 0 && ft_grad(mlx, i) <= 180)) && e == 2)
		return (*(unsigned int*)(mlx->north.addr + ((int)((mlx->sflag->i1 -
		((mlx->sflag->ry - data.wall) / 2)) / (data.wall /
		mlx->north.height)) * mlx->north.ll + (int)(data.coord *
		mlx->north.width) * (mlx->north.bpp / 8))));
	else if (((ft_grad(mlx, i) > 90 && ft_grad(mlx, i) <= 270)) && e == 1)
		return (*(unsigned int*)(mlx->west.addr + ((int)((mlx->sflag->i1 -
		((mlx->sflag->ry - data.wall) / 2)) / (data.wall /
		mlx->west.height)) * mlx->west.ll + (int)(data.coord *
		mlx->west.width) * (mlx->west.bpp / 8))));
	else if (((ft_grad(mlx, i) > 180 && ft_grad(mlx, i) < 360)) && e == 2)
		return (*(unsigned int*)(mlx->south.addr + ((int)((mlx->sflag->i1 -
		((mlx->sflag->ry - data.wall) / 2)) / (data.wall /
		mlx->south.height)) * mlx->south.ll + (int)(data.coord *
		mlx->south.width) * (mlx->south.bpp / 8))));
	else if (((ft_grad(mlx, i) > 270 || ft_grad(mlx, i) <= 90)) && e == 1)
		return (*(unsigned int*)(mlx->east.addr + ((int)((mlx->sflag->i1 -
		((mlx->sflag->ry - data.wall) / 2)) / (data.wall /
		mlx->east.height)) * mlx->east.ll + (int)(data.coord *
		mlx->east.width) * (mlx->east.bpp / 8))));
	else
		return (0);
}
