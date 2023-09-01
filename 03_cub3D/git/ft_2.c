/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:26:16 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:26:19 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_exit(t_mlx *mlx)
{
	if (mlx->sflag->map_name != NULL)
		free(mlx->sflag->map_name);
	close(mlx->sflag->map_fd);
	while (--mlx->sflag->szmap >= 0)
	{
		if (mlx->sflag->map[mlx->sflag->szmap] != NULL)
			free(mlx->sflag->map[mlx->sflag->szmap]);
	}
	if (mlx->sflag->map != NULL)
		free(mlx->sflag->map);
	if (mlx->sflag->no != NULL)
		free(mlx->sflag->no);
	if (mlx->sflag->so != NULL)
		free(mlx->sflag->so);
	if (mlx->sflag->s != NULL)
		free(mlx->sflag->s);
	if (mlx->sflag->we != NULL)
		free(mlx->sflag->we);
	if (mlx->sflag->ea != NULL)
		free(mlx->sflag->ea);
	if (mlx->mlx != 0 && mlx->win != 0)
		mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->mlx);
	exit(0);
	return (0);
}

int			ft_free_2(char **line, int i)
{
	int		k;

	k = 0;
	if (!line)
		return (1);
	while (k < i + 1)
	{
		if (line[k])
		{
			free(line[k]);
			line[k] = NULL;
		}
		k++;
	}
	free(line);
	line = NULL;
	return (1);
}

char		*ft_strputend(char *a, char b)
{
	char	*c;
	int		i;

	i = 0;
	if (!a)
		return (NULL);
	if (!(c = (char*)malloc((int)ft_strlen(a) + 2)))
		return (NULL);
	while (a[i])
	{
		c[i] = a[i];
		i++;
	}
	c[i++] = b;
	c[i] = '\0';
	free(a);
	a = NULL;
	return (c);
}

int			ft_free_3(char **line, int str, int heig)
{
	while (str < heig)
		free(line[str++]);
	free(line);
	return (1);
}
