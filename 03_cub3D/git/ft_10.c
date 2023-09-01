/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:27:49 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:27:50 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_strdup_2(char *src, int k)
{
	char	*p;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	if (!(p = (char*)malloc(sizeof(char) * k)))
		return (NULL);
	while (i < k)
	{
		if ((i <= (int)ft_strlen(src)) && (src[i] == '1' ||
			src[i] == '0' || src[i] == '2'))
			p[i] = src[i];
		else
			p[i] = '1';
		i++;
	}
	free(src);
	src = NULL;
	return (p);
}

int			ft_prc_map_4(t_data *sflag)
{
	int		i;
	int		k;
	char	**arr;

	i = 0;
	k = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * (sflag->szmap + 1))))
		return (1);
	arr[sflag->szmap] = NULL;
	while (i < sflag->szmap)
	{
		k = (k > (int)ft_strlen(sflag->map[i])) ? k :
			(int)ft_strlen(sflag->map[i]);
		i++;
	}
	i = -1;
	while (++i < sflag->szmap)
		arr[i] = ft_strdup_2(sflag->map[i], k);
	free(sflag->map);
	sflag->map = arr;
	return (0);
}

int			ft_free_prc_map_2(char *line, t_data *sflag)
{
	free(line);
	line = NULL;
	sflag->fict = (sflag->fict == 1) ? 2 : sflag->fict;
	return (1);
}

int			ft_prc_map_2(int heig, char **line, t_data *sflag, t_mlx *mlx)
{
	int		str;
	int		chr;
	int		i;

	i = 0;
	str = -1;
	while (++str < heig && line[str])
	{
		chr = -1;
		if (i != 0 && i != 2)
			break ;
		if (!line[str][chr + 1] && sflag->fict == 1)
			sflag->fict = 2;
		while (line[str][++chr] || chr == 0)
		{
			if ((i = ft_first_flags(mlx, sflag, line[str], chr)) < 2)
				break ;
			if (chr == (int)ft_strlen(line[str]) &&
				ft_free_prc_map_2(line[str], sflag))
				break ;
		}
	}
	if (sflag->fict == -1 || i == 1)
		return (ft_free_3(line, str, heig));
	return (ft_prc_map_3(sflag));
}

int			ft_prc_map(t_data *sflag, t_mlx *mlx)
{
	int		i;
	char	**line;
	int		heig;
	int		k;

	i = 0;
	heig = ft_fileheight(sflag->map_fd);
	if (heig <= 0 || !(line = (char**)malloc(sizeof(char*) * heig)))
		return (print_error("Error: no memory allocated or file is empty.\n"));
	line[heig - 1] = NULL;
	close(sflag->map_fd);
	sflag->map_fd = open(sflag->map_name, O_RDONLY);
	while ((k = get_next_line(sflag->map_fd, &line[i])) != 0)
	{
		if (k == -1)
		{
			ft_free_2(line, i);
			return (print_error("Error: read file error.\n"));
		}
		i++;
	}
	if (ft_prc_map_2(heig, line, sflag, mlx) || ft_prc_map_4(sflag))
		return (1);
	free(line);
	return (0);
}
