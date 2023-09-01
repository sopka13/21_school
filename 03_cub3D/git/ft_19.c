/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_19.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:34:10 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:34:12 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_leit_2(t_mlx *mlx, t_vect *vect, int i1, int i2)
{
	double	om;
	double	x_m;
	double	y_m;
	double	alfa_bc;
	t_leit	leit;

	ft_xym(mlx, vect, &x_m, &y_m);
	om = sqrt(pow(x_m - mlx->sflag->cam.x_start, 2) +
		pow(y_m - mlx->sflag->cam.y_start, 2));
	alfa_bc = ft_grad(mlx, vect->i) + 90;
	ft_alfa_bc(&leit, x_m, y_m, alfa_bc);
	while (alfa_bc < 0.0)
		alfa_bc += 360;
	while (alfa_bc >= 360.0)
		alfa_bc -= 360;
	leit.i1 = i1;
	leit.i2 = i2;
	ft_xyfict(mlx, vect, &leit, om);
	if (vect->s_lent[mlx->sflag->fict] > 0)
	{
		vect->k_s[mlx->sflag->fict] = 1 / (vect->s_lent[mlx->sflag->fict] / 15);
		return (1);
	}
	return (0);
}

void		ft_vect_s1(t_vect *vect, double *i1)
{
	vect->s1 = fabs(vect->dxstart1 + vect->dx * *i1);
	vect->s = vect->s1;
	vect->e = 1;
	*i1 += 1;
}

void		ft_leit_vect(t_mlx *mlx, t_vect *vect)
{
	int		i;
	double	i1;
	double	i2;

	i = 0;
	i1 = 0.0;
	i2 = 0.0;
	while (ft_leit_1(mlx, vect))
	{
		mlx->sflag->fict = i;
		if (((vect->dxstart1 + vect->dx * i1) > 0 ? (vect->dxstart1 + vect->dx
		* i1) : (-1.0) * (vect->dxstart1 + vect->dx * i1)) < ((vect->dystart1
		+ vect->dy * i2) > 0 ? (vect->dystart1 + vect->dy * i2) : (-1.0) *
		(vect->dystart1 + vect->dy * i2)))
			ft_vect_s1(vect, &i1);
		else
		{
			vect->s2 = fabs(vect->dystart1 + vect->dy * i2++);
			vect->s = vect->s2;
			vect->e = 2;
		}
		if (vect->coord_2[i] == 0 && (ft_pr_vec1(mlx, vect->s1, vect->i,
			vect->e) || ft_pr_vec2(mlx, vect->s2, vect->i, vect->e)))
			i += ft_leit_2(mlx, vect, i1, i2);
	}
}

int			ft_condition_1(t_mlx *mlx, t_vect *vect, int i)
{
	t_dt	data;

	data.wall = vect->wall_heig * vect->k_s[i] * 2;
	data.coord = vect->coord_2[i];
	if (((mlx->sflag->i1 > ((mlx->sflag->ry / 2) - vect->wall_heig *
	vect->k_s[i]) && mlx->sflag->i1 < (mlx->sflag->ry - ((mlx->sflag->ry
	/ 2) - vect->wall_heig * vect->k_s[i])) && (ft_colour(mlx, vect->i,
	0, data) != -16777216)) || ((mlx->sflag->i1 > ((mlx->sflag->ry / 2)
	- vect->wall_heig * vect->k) && mlx->sflag->i1 < (mlx->sflag->ry -
	((mlx->sflag->ry / 2) - vect->wall_heig * vect->k))))))
		return (1);
	if (i == 99 || (vect->k_s[i] == 0 && vect->coord_2[i] == 0))
		return (0);
	return (ft_condition_1(mlx, vect, ++i));
}

int			ft_condition_2(t_mlx *mlx, t_vect *vect, int i)
{
	t_dt data;

	ft_bzero(&data, sizeof(data));
	data.wall = vect->wall_heig * vect->k_s[i] * 2;
	data.coord = vect->coord_2[i];
	if (vect->coord_2[i] > 0 && ft_colour(mlx, vect->i, 0, data) != -16777216)
	{
		mlx->sflag->fict = i;
		return (1);
	}
	if (i == 99 || (vect->coord_2[i] == 0 && vect->k_s[i] == 0))
		return (0);
	return (ft_condition_2(mlx, vect, ++i));
}
