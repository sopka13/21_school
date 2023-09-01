/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:27:27 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:27:37 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_r_flag(char *line, t_data *sflag)
{
	int		i;
	char	*str;
	int		rgb[2];

	i = 0;
	while (i < 2)
		rgb[i++] = 0;
	str = ft_strtrim(line, "Rr \t");
	if (ft_atoi_n(str, rgb, 2))
	{
		free(str);
		str = NULL;
		return (1);
	}
	if (rgb[0] > 9999 || rgb[1] > 9999 || rgb[0] <= 2 || rgb[1] <= 2)
	{
		free(str);
		str = NULL;
		return (1);
	}
	sflag->rx = rgb[0];
	sflag->ry = rgb[1];
	free(str);
	str = NULL;
	return (0);
}

void		ft_free_map_flag(char **map, int szmap)
{
	int		i;

	i = 0;
	while (i < szmap)
	{
		free(map[i]);
		map[i++] = NULL;
	}
	free(map);
}

int			ft_map_flag(char *line, t_data *sflag)
{
	int		i;
	char	**arr;

	if (sflag->s == NULL || sflag->we == NULL || sflag->no == NULL ||
		sflag->ea == NULL || sflag->so == NULL || sflag->cel == -1 ||
		sflag->flor == -1 || sflag->rx == 0 || sflag->ry == 0)
		return (print_error("Error: not enough arguments\n"));
	i = -1;
	if (sflag->fict == 2 && sflag->szmap > 0)
		sflag->fict = -1;
	if (!(arr = (char**)malloc(sizeof(char*) * (sflag->szmap + 1))))
		return (1);
	while (++i < sflag->szmap)
		arr[i] = ft_strdup(sflag->map[i]);
	arr[i] = ft_strdup(line);
	if (sflag->map && sflag->szmap > 0)
		ft_free_map_flag(sflag->map, sflag->szmap);
	sflag->map = arr;
	sflag->szmap++;
	sflag->fict = (sflag->fict == 0) ? 1 : sflag->fict;
	free(line);
	line = NULL;
	return (0);
}

int			ft_plor_emul(char a)
{
	if (a == 'N' || a == 'n' || a == 'W' || a == 'w' ||
		a == 'S' || a == 's' || a == 'E' || a == 'e')
		return (1);
	return (0);
}

void		ft_fict_1(t_data *sflag, int i, int k)
{
	sflag->plor = sflag->map[i][k];
	sflag->cam.y_start = i + 0.5;
	sflag->cam.x_start = k + 0.5;
	sflag->map[i][k] = '0';
}
