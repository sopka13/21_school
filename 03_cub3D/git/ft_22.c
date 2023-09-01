/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_22.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:34:27 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:34:36 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_print_init(t_mlx *mlx, t_vect *vect)
{
	ft_bzero(vect, sizeof(vect));
	ft_init_vect(vect);
	ft_vect_start(mlx, vect);
	mlx->img = mlx_new_image(mlx->mlx, mlx->sflag->rx, mlx->sflag->ry);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->ll, &mlx->endian);
}

int			ft_print_vectors(t_mlx *mlx)
{
	t_vect	vect;

	ft_print_init(mlx, &vect);
	while (vect.i)
	{
		ft_vect_start_1(mlx, &vect);
		ft_dxystart(mlx, &vect);
		ft_dxy(mlx, &vect);
		ft_leit_vect(mlx, &vect);
		vect.lentp = vect.s;
		vect.k = 1 / (vect.lentp / 15);
		if (vect.e == 1)
			vect.coord_1 = modf(mlx->sflag->cam.y_start + (vect.s * vect.sn2)
			/ ZOOM, &vect.nul);
		else
			vect.coord_1 = modf(mlx->sflag->cam.x_start + (vect.s * vect.cs2)
			/ ZOOM, &vect.nul);
		ft_print_line(mlx, &vect);
		vect.i = vect.i - STEP_VECT;
	}
	if (mlx->sflag->save > 0)
		ft_save_1(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
	return (0);
}

int			ft_render(t_mlx *mlx)
{
	ft_move(mlx);
	ft_print_vectors(mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	sflag;
	t_mlx	mlx;

	init_sflag(&sflag);
	init_mlx(&mlx, &sflag);
	if (ft_ac_launch(argc, argv, &sflag, &mlx))
		return (ft_exit(&mlx));
	ft_get_settings(&sflag, &mlx);
	if (sflag.save > 0)
		ft_render(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, sflag.rx, sflag.ry, "Cub3D");
	mlx_hook(mlx.win, 33, 1L << 17, ft_exit, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, ft_key_press, &mlx);
	mlx_hook(mlx.win, 3, 1L << 1, ft_key_release, &mlx);
	mlx_loop_hook(mlx.mlx, ft_render, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
