/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_9.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:27:43 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:27:45 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_fict_2(t_data *sflag, int i, int k)
{
	if ((sflag->map[i][k] == SPASE || sflag->map[i][k] == SPRITE) &&
	((i == 0 || k > (int)ft_strlen(sflag->map[i - 1]) || (sflag->map[i - 1][k]
	!= WALL && sflag->map[i - 1][k] != SPASE && sflag->map[i - 1][k] != SPRITE
	&& !ft_plor_emul(sflag->map[i - 1][k]))) || (i == (sflag->szmap) || k
	> (int)ft_strlen(sflag->map[i + 1]) || (sflag->map[i + 1][k] != WALL &&
	sflag->map[i + 1][k] != SPASE && sflag->map[i + 1][k] != SPRITE &&
	!ft_plor_emul(sflag->map[i + 1][k]))) || (k == 0 || (sflag->map[i][k - 1]
	!= WALL && sflag->map[i][k - 1] != SPASE && sflag->map[i][k - 1] != SPRITE
	&& !ft_plor_emul(sflag->map[i][k - 1]))) ||
	(k == (int)ft_strlen(sflag->map[i]) || (sflag->map[i][k + 1] != WALL &&
	sflag->map[i][k + 1] != SPASE && sflag->map[i][k + 1] != SPRITE &&
	!ft_plor_emul(sflag->map[i][k + 1])))))
		return (1);
	return (0);
}

void		ft_fict_3(t_data *sflag, int i, int k)
{
	if (sflag->cam.y_min == 0)
	{
		sflag->cam.y_min = i;
		sflag->cam.y_max = i;
		sflag->cam.x_min = k;
		sflag->cam.x_max = k;
	}
	sflag->cam.y_min = (i < sflag->cam.y_min) ? i : sflag->cam.y_min;
	sflag->cam.y_max = (i > sflag->cam.y_max) ? i : sflag->cam.y_max;
	sflag->cam.x_min = (k < sflag->cam.x_min) ? k : sflag->cam.x_min;
	sflag->cam.x_max = (k > sflag->cam.x_max) ? k : sflag->cam.x_max;
}

int			ft_prc_map_3(t_data *sflag)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (i < sflag->szmap - 1)
	{
		k = 0;
		while (sflag->map[i][k])
		{
			if (!sflag->plor && ft_plor_emul(sflag->map[i][k]))
				ft_fict_1(sflag, i, k);
			if (sflag->plor && ft_plor_emul(sflag->map[i][k]))
				return (1);
			if (ft_fict_2(sflag, i, k))
				return (1);
			if (sflag->map[i][k] == SPASE || sflag->map[i][k] == SPRITE)
				ft_fict_3(sflag, i, k);
			k++;
		}
		i++;
	}
	return (0);
}

int			ft_first_flags(t_mlx *mlx, t_data *sflag, char *a, int chr)
{
	if (a[chr] == 'N' || a[chr] == 'n')
		return (ft_no_flag(a, sflag, mlx));
	else if (a[chr] == 'S' || a[chr] == 's')
	{
		if (((chr + 1) <= (int)ft_strlen(a)) && (a[chr + 1] == 'O'
			|| a[chr + 1] == 'o'))
			return (ft_so_flag(a, sflag, mlx));
		else
			return (ft_s_flag(a, sflag, mlx));
	}
	else if (a[chr] == 'W' || a[chr] == 'w')
		return (ft_we_flag(a, sflag, mlx));
	else if (a[chr] == 'E' || a[chr] == 'e')
		return (ft_ea_flag(a, sflag, mlx));
	else if (a[chr] == 'C' || a[chr] == 'c')
		return (ft_c_flag(a, sflag));
	else if (a[chr] == 'F' || a[chr] == 'f')
		return (ft_f_flag(a, sflag));
	else if (a[chr] == 'R' || a[chr] == 'r')
		return (ft_r_flag(a, sflag));
	else if (ft_isdigit(a[chr]))
		return (ft_map_flag(a, sflag));
	return (2);
}
