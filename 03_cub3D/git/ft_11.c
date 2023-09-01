/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_11.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:27:54 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:27:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_valid_map(t_data *sflag, t_mlx *mlx)
{
	if ((sflag->map_fd = open(sflag->map_name, O_RDONLY)) == -1)
		return (print_error(strerror(errno)));
	if (ft_prc_map(sflag, mlx))
		return (1);
	return (0);
}

int			ft_ac_launch(int argc, char **argv, t_data *sflag, t_mlx *mlx)
{
	if (argc <= 1)
		return (print_error("Error: Invalid number of arguments\n"));
	if (argc > 3)
		return (print_error("Error: Number of arguments exceeded\n"));
	if (ft_name_map(argc, argv, sflag) || ft_valid_map(sflag, mlx))
		return (print_error("Error: Invalid map name or map file\n"));
	if (sflag->s == NULL || sflag->we == NULL || sflag->no == NULL ||
		sflag->ea == NULL || sflag->so == NULL || sflag->cel == -1 ||
		sflag->flor == -1 || sflag->rx == 0 || sflag->ry == 0 ||
		sflag->cam.x_start == -1 || sflag->cam.y_start == -1)
		return (print_error("Error: not enough arguments\n"));
	return (0);
}

void		ft_get_settings(t_data *sflag, t_mlx *mlx)
{
	int		x;
	int		y;

	mlx_get_screen_size(mlx->mlx, &x, &y);
	if (sflag->rx > x)
		sflag->rx = x;
	if (sflag->ry > y)
		sflag->ry = y;
	if (mlx->sflag->plor == 'N' || mlx->sflag->plor == 'n')
		mlx->sflag->cam.alfa = 90;
	if (mlx->sflag->plor == 'S' || mlx->sflag->plor == 's')
		mlx->sflag->cam.alfa = 270;
	if (mlx->sflag->plor == 'W' || mlx->sflag->plor == 'w')
		mlx->sflag->cam.alfa = 180;
	if (mlx->sflag->plor == 'E' || mlx->sflag->plor == 'e')
		mlx->sflag->cam.alfa = 0;
}

int			ft_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		ft_exit(mlx);
	else if (keycode == 119)
		mlx->move.forward = 1;
	else if (keycode == 115)
		mlx->move.back = 1;
	else if (keycode == 97)
		mlx->move.left = 1;
	else if (keycode == 100)
		mlx->move.right = 1;
	else if (keycode == 65361)
		mlx->move.cam_l = 1;
	else if (keycode == 65363)
		mlx->move.cam_r = 1;
	return (0);
}
