/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_18.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:33:59 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:34:05 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_vect_start_1(t_mlx *mlx, t_vect *vect)
{
	vect->e = 0;
	vect->s = 0;
	vect->cs2 = cos(((double)ft_grad(mlx, vect->i) * M_PI) / 180.0);
	vect->sn2 = sin(((double)ft_grad(mlx, vect->i) * M_PI) / 180.0);
	vect->dxstart1 = 0;
	vect->dystart1 = 0;
	vect->s1 = 0.0;
	vect->s2 = 0.0;
	vect->coord_1 = 0.0;
	ft_bzero(&vect->coord_2, 100);
	ft_bzero(&vect->k_s, 100);
	ft_bzero(&vect->s_lent, 100);
	vect->wall_heig = (double)mlx->sflag->ry;
	mlx->sflag->fict = 0;
}

int			ft_leit_1(t_mlx *mlx, t_vect *vect)
{
	if (mlx->sflag->map[ft_round_y_s1((mlx->sflag->cam.y_start + (vect->s1
		* vect->sn2) / ZOOM), ft_grad(mlx, vect->i), vect->e)]
		[ft_round_x_s1((mlx->sflag->cam.x_start + (vect->s1 * vect->cs2) /
		ZOOM), ft_grad(mlx, vect->i), vect->e)] != '1' && mlx->sflag->map
		[ft_round_y_s2((mlx->sflag->cam.y_start + (vect->s2 * vect->sn2) /
		ZOOM), ft_grad(mlx, vect->i), vect->e)][ft_round_x_s2((
		mlx->sflag->cam.x_start + (vect->s2 * vect->cs2) /
		ZOOM), ft_grad(mlx, vect->i), vect->e)] != '1')
		return (1);
	return (0);
}

void		ft_xym(t_mlx *mlx, t_vect *vect, double *x_m, double *y_m)
{
	if (vect->e == 1)
	{
		*x_m = ft_round_x_s1((mlx->sflag->cam.x_start + (vect->s * vect->cs2)
		/ ZOOM), ft_grad(mlx, vect->i), vect->e) + 0.5;
		*y_m = ft_round_y_s1((mlx->sflag->cam.y_start + (vect->s * vect->sn2)
		/ ZOOM), ft_grad(mlx, vect->i), vect->e) + 0.5;
	}
	else if (vect->e == 2)
	{
		*x_m = ft_round_x_s2((mlx->sflag->cam.x_start + (vect->s * vect->cs2)
		/ ZOOM), ft_grad(mlx, vect->i), vect->e) + 0.5;
		*y_m = ft_round_y_s2((mlx->sflag->cam.y_start + (vect->s * vect->sn2)
		/ ZOOM), ft_grad(mlx, vect->i), vect->e) + 0.5;
	}
}

void		ft_xyfict(t_mlx *mlx, t_vect *vect, t_leit *leit, double om)
{
	if (vect->e == 1)
	{
		leit->x_fict = fabs((mlx->sflag->cam.x_start + ((vect->dxstart1 +
		vect->dx * (leit->i1 - 1) + ZOOM) * vect->cs2) / ZOOM));
		leit->y_fict = fabs((mlx->sflag->cam.y_start + ((vect->dxstart1 +
		vect->dx * (leit->i1 - 1) + ZOOM) * vect->sn2) / ZOOM));
	}
	else
	{
		leit->x_fict = fabs((mlx->sflag->cam.x_start + ((vect->dystart1 +
		vect->dy * (leit->i2 - 1) + ZOOM) * vect->cs2) / ZOOM));
		leit->y_fict = fabs((mlx->sflag->cam.y_start + ((vect->dystart1 +
		vect->dy * (leit->i2 - 1) + ZOOM) * vect->sn2) / ZOOM));
	}
	vect->coord_2[mlx->sflag->fict] = ft_cross(mlx, leit);
	if (vect->coord_2[mlx->sflag->fict] > 0)
		vect->s_lent[mlx->sflag->fict] = om * ZOOM;
}

void		ft_alfa_bc(t_leit *leit, double x_m, double y_m, double alf_b)
{
	leit->x_b = x_m + (0.5 * cos(alf_b * M_PI / 180));
	leit->y_b = y_m + (0.5 * sin(alf_b * M_PI / 180));
	leit->x_c = x_m - (0.5 * cos(alf_b * M_PI / 180));
	leit->y_c = y_m - (0.5 * sin(alf_b * M_PI / 180));
}
