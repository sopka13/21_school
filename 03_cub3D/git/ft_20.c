/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_20.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:34:17 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:34:19 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_a(t_mlx *mlx, t_vect *vect)
{
	int			color;
	t_dt		data;

	ft_bzero(&data, sizeof(data));
	if (ft_condition_2(mlx, vect, 0))
	{
		data.wall = vect->wall_heig * vect->k_s[mlx->sflag->fict] * 2;
		data.coord = vect->coord_2[mlx->sflag->fict];
		color = ft_colour(mlx, vect->i, 0, data);
	}
	else
	{
		data.wall = vect->wall_heig * vect->k * 2;
		data.coord = fabs(vect->coord_1);
		color = ft_colour(mlx, vect->i, vect->e, data);
	}
	my_mlx_pixel_put(mlx, vect->x1, mlx->sflag->i1, color);
}

void			ft_b(t_mlx *mlx, t_vect *vect)
{
	if (mlx->sflag->i1 < (mlx->sflag->ry / 2))
		my_mlx_pixel_put(mlx, vect->x1, mlx->sflag->i1, mlx->sflag->cel);
	else
		my_mlx_pixel_put(mlx, vect->x1, mlx->sflag->i1, mlx->sflag->flor);
}

void			ft_print_line(t_mlx *mlx, t_vect *vect)
{
	mlx->sflag->i1 = 0;
	while (vect->x1 < (mlx->sflag->rx - ((vect->i - STEP_VECT) *
			(mlx->sflag->rx / VI_GRAD))))
	{
		mlx->sflag->i1 = 0;
		while (mlx->sflag->i1 < mlx->sflag->ry)
		{
			mlx->sflag->fict = 0;
			if (ft_condition_1(mlx, vect, 0))
				ft_a(mlx, vect);
			else
				ft_b(mlx, vect);
			mlx->sflag->i1++;
		}
		vect->x1++;
	}
}

void			ft_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}
