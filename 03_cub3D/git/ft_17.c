/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_17.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:28:26 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:28:27 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_init_vect(t_vect *vect)
{
	vect->i = 0.0;
	vect->e = 0;
	vect->x1 = 0;
	vect->cs2 = 0.0;
	vect->sn2 = 0.0;
	vect->dy = 0.0;
	vect->dx = 0.0;
	vect->dxstart1 = 0.0;
	vect->dystart1 = 0.0;
	vect->lentp = 0.0;
	vect->s = 0.0;
	vect->s1 = 0.0;
	vect->s2 = 0.0;
	vect->alfa_x1 = 0.0;
	vect->alfa_x2 = 0.0;
	vect->alfa_y1 = 0.0;
	vect->alfa_y2 = 0.0;
	vect->nul = 0.0;
	vect->coord_1 = 0.0;
	ft_bzero(&vect->coord_2, sizeof(vect->coord_2));
	vect->k = 0.0;
	ft_bzero(&vect->k_s, sizeof(vect->k_s));
	ft_bzero(&vect->s_lent, sizeof(vect->s_lent));
	vect->wall_heig = 0.0;
}

void		ft_dxystart(t_mlx *mlx, t_vect *vect)
{
	vect->dxstart1 = (ft_grad(mlx, vect->i) > 90 && ft_grad(mlx, vect->i) <
	270) ? ((modf(mlx->sflag->cam.x_start, &vect->nul) / vect->cs2) * ZOOM)
	: (((1.0 - modf(mlx->sflag->cam.x_start, &vect->nul)) / vect->cs2) * ZOOM);
	vect->dystart1 = (ft_grad(mlx, vect->i) > 0 && ft_grad(mlx, vect->i) <
	180) ? (((1.0 - modf(mlx->sflag->cam.y_start, &vect->nul)) / vect->sn2)
	* ZOOM) : ((modf(mlx->sflag->cam.y_start, &vect->nul) / vect->sn2) * ZOOM);
	if (ft_grad(mlx, vect->i) < vect->alfa_y1 || ft_grad(mlx, vect->i) > (360 -
		vect->alfa_y1))
		vect->dystart1 = (ft_grad(mlx, vect->i) > (360 - vect->alfa_y1)) ?
		((-1.0) * (mlx->sflag->cam.x_max - mlx->sflag->cam.x_start + 2) * ZOOM)
		: (mlx->sflag->cam.x_max - mlx->sflag->cam.x_start + 2) * ZOOM;
	if (ft_grad(mlx, vect->i) < (180 + vect->alfa_y2) && ft_grad(mlx, vect->i) >
		(180 - vect->alfa_y2))
		vect->dystart1 = (ft_grad(mlx, vect->i) < 180) ? ((-1.0) *
		mlx->sflag->cam.x_start * ZOOM) : mlx->sflag->cam.x_start * ZOOM;
	if (ft_grad(mlx, vect->i) < (90 + vect->alfa_x2) && ft_grad(mlx, vect->i)
		> (90 - vect->alfa_x2))
		vect->dxstart1 = (ft_grad(mlx, vect->i) > 90) ?
		((-1.0) * (mlx->sflag->cam.y_max - mlx->sflag->cam.y_start + 2) * ZOOM)
		: (mlx->sflag->cam.y_max - mlx->sflag->cam.y_start + 2) * ZOOM;
	if (ft_grad(mlx, vect->i) < (270 + vect->alfa_x1) && ft_grad(mlx, vect->i)
		> (270 - vect->alfa_x1))
		vect->dxstart1 = (ft_grad(mlx, vect->i) < 270) ?
		(mlx->sflag->cam.y_start * ZOOM) : ((-1.0) *
		mlx->sflag->cam.y_start * ZOOM);
}

void		ft_dxy(t_mlx *mlx, t_vect *vect)
{
	vect->dx = ((double)ZOOM) / vect->cs2;
	vect->dy = ((double)ZOOM) / vect->sn2;
	if (ft_grad(mlx, vect->i) < vect->alfa_y1 || ft_grad(mlx, vect->i) >
		(360 - vect->alfa_y1))
		vect->dy = (ft_grad(mlx, vect->i) > (360 - vect->alfa_y1)) ?
		((-1.0) * ((double)mlx->sflag->cam.x_max - mlx->sflag->cam.x_start + 2)
		* (double)ZOOM) : ((double)mlx->sflag->cam.x_max -
		mlx->sflag->cam.x_start + 2) * (double)ZOOM;
	if (ft_grad(mlx, vect->i) < (180 + vect->alfa_y2) && ft_grad(mlx, vect->i)
		> (180 - vect->alfa_y2))
		vect->dy = (ft_grad(mlx, vect->i) < 180) ? ((-1.0) * mlx->sflag->
		cam.x_start * (double)ZOOM) : mlx->sflag->cam.x_start * (double)ZOOM;
	if (ft_grad(mlx, vect->i) < (90 + vect->alfa_x2) && ft_grad(mlx, vect->i) >
		(90 - vect->alfa_x2))
		vect->dx = (ft_grad(mlx, vect->i) > 90) ? ((-1.0) * ((double)mlx->
		sflag->cam.y_max - mlx->sflag->cam.y_start + 2) * (double)ZOOM)
		: ((double)mlx->sflag->cam.y_max - mlx->sflag->cam.y_start + 2)
		* (double)ZOOM;
	if (ft_grad(mlx, vect->i) < (270 + vect->alfa_x1) && ft_grad(mlx, vect->i) >
		(270 - vect->alfa_x1))
		vect->dx = (ft_grad(mlx, vect->i) < 270) ? (mlx->sflag->cam.y_start *
		(double)ZOOM) : ((-1.0) * mlx->sflag->cam.y_start * (double)ZOOM);
}

void		ft_vect_start(t_mlx *mlx, t_vect *vect)
{
	vect->i = VI_GRAD;
	vect->alfa_x1 = ft_alfa(mlx, 2);
	vect->alfa_x2 = ft_alfa(mlx, 4);
	vect->alfa_y1 = ft_alfa(mlx, 1);
	vect->alfa_y2 = ft_alfa(mlx, 3);
}
