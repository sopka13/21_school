/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:28:21 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:28:22 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		ft_cross(t_mlx *mlx, t_leit *leit)
{
	double	dot[2];
	double	x[6];

	x[0] = (((leit->y_fict - mlx->sflag->cam.y_start) * (leit->x_c - leit->x_b))
	- ((leit->x_fict - mlx->sflag->cam.x_start) * (leit->y_c - leit->y_b)));
	if (x[0] != 0)
	{
		x[1] = (((leit->x_fict - mlx->sflag->cam.x_start) * (leit->y_b -
		mlx->sflag->cam.y_start)) - ((leit->y_fict - mlx->sflag->cam.y_start) *
		(leit->x_b - mlx->sflag->cam.x_start))) / x[0];
		x[2] = (((leit->x_c - leit->x_b) * (leit->y_b -
		mlx->sflag->cam.y_start)) - ((leit->y_c - leit->y_b) * (leit->x_b -
		mlx->sflag->cam.x_start))) / x[0];
	}
	dot[0] = leit->x_b + x[1] * (leit->x_c - leit->x_b);
	dot[1] = leit->y_b + x[1] * (leit->y_c - leit->y_b);
	x[4] = sqrt(pow(dot[0] - leit->x_c, 2) + pow(dot[1] - leit->y_c, 2));
	if (x[4] > 1)
		x[4] = 0;
	x[5] = sqrt(pow(dot[0] - leit->x_b, 2) + pow(dot[1] - leit->y_b, 2));
	x[5] = (x[5] > 1) ? 0 : x[5];
	if (x[4] != 0 && x[5] != 0)
		return (x[4]);
	else
		return (0);
}

int			ft_pr_vec1(t_mlx *mlx, double s1, double i, int e)
{
	double	cs2;
	double	sn2;

	cs2 = cos(((double)ft_grad(mlx, i) * M_PI) / 180.0);
	sn2 = sin(((double)ft_grad(mlx, i) * M_PI) / 180.0);
	if ((mlx->sflag->map[ft_round_y_s1((mlx->sflag->cam.y_start + (s1 * sn2) /
	ZOOM), ft_grad(mlx, i), e)][ft_round_x_s1((mlx->sflag->cam.x_start + (s1 *
	cs2) / ZOOM), ft_grad(mlx, i), e)] == '2' && e == 1) && ((ft_round_y_s1((
	mlx->sflag->cam.y_start + (s1 * sn2) / ZOOM), ft_grad(mlx, i), e) != (int)
	mlx->sflag->cam.y_start && ft_round_x_s1((mlx->sflag->cam.x_start + (s1 *
	cs2) / ZOOM), ft_grad(mlx, i), e) != (int)mlx->sflag->cam.x_start) || (
	ft_round_y_s1((mlx->sflag->cam.y_start + (s1 * sn2) / ZOOM), ft_grad(mlx,
	i), e) == (int)mlx->sflag->cam.y_start && ft_round_x_s1((mlx->sflag->
	cam.x_start + (s1 * cs2) / ZOOM), ft_grad(mlx, i), e) != (int)mlx->sflag->
	cam.x_start) || (ft_round_y_s1((mlx->sflag->cam.y_start + (s1 * sn2) / ZOOM)
	, ft_grad(mlx, i), e) != (int)mlx->sflag->cam.y_start && ft_round_x_s1((
	mlx->sflag->cam.x_start + (s1 * cs2) / ZOOM), ft_grad(mlx, i), e) ==
	(int)mlx->sflag->cam.x_start)))
		return (1);
	return (0);
}

int			ft_pr_vec2(t_mlx *mlx, double s2, double i, int e)
{
	double	cs2;
	double	sn2;

	cs2 = cos(((double)ft_grad(mlx, i) * M_PI) / 180.0);
	sn2 = sin(((double)ft_grad(mlx, i) * M_PI) / 180.0);
	if ((mlx->sflag->map[ft_round_y_s2((mlx->sflag->cam.y_start + (s2 * sn2) /
	ZOOM), ft_grad(mlx, i), e)][ft_round_x_s2((mlx->sflag->cam.x_start + (s2 *
	cs2) / ZOOM), ft_grad(mlx, i), e)] == '2' && e == 2) && ((ft_round_y_s2((
	mlx->sflag->cam.y_start + (s2 * sn2) / ZOOM), ft_grad(mlx, i), e) != (int)
	mlx->sflag->cam.y_start && ft_round_x_s2((mlx->sflag->cam.x_start + (s2 *
	cs2) / ZOOM), ft_grad(mlx, i), e) != (int)mlx->sflag->cam.x_start) ||
	(ft_round_y_s2((mlx->sflag->cam.y_start + (s2 * sn2) / ZOOM), ft_grad(mlx
	, i), e) == (int)mlx->sflag->cam.y_start && ft_round_x_s2((mlx->sflag->
	cam.x_start + (s2 * cs2) / ZOOM), ft_grad(mlx, i), e) != (int)mlx->sflag->
	cam.x_start) || (ft_round_y_s2((mlx->sflag->cam.y_start + (s2 * sn2) / ZOOM)
	, ft_grad(mlx, i), e) != (int)mlx->sflag->cam.y_start && ft_round_x_s2((
	mlx->sflag->cam.x_start + (s2 * cs2) / ZOOM), ft_grad(mlx, i), e) ==
	(int)mlx->sflag->cam.x_start)))
		return (1);
	return (0);
}

void		ft_destr_img(t_mlx *mlx)
{
	if (mlx->img != 0 && mlx->mlx != 0)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = NULL;
	}
}
