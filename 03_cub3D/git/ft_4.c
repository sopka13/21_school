/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:26:38 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:26:39 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_get_texture(t_texture *a, t_mlx *mlx, char *line)
{
	if (a->img != 0)
		return (1);
	a->img = mlx_xpm_file_to_image(mlx->mlx, line, &a->width, &a->height);
	if (a->img != 0)
	{
		a->addr = mlx_get_data_addr(a->img, &a->bpp, &a->ll, &a->endian);
		return (0);
	}
	return (print_error("File of texture missed or have error\n"));
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)s1 > *(unsigned char*)s2)
			return (1);
		else if (*(unsigned char*)s1 < *(unsigned char*)s2)
			return (-1);
		else if (*(unsigned char*)s1 == 0 || *(unsigned char*)s2 == 0)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	k;

	i = 0;
	k = 0;
	if (!little[i])
		return ((char*)big);
	while (big[i])
	{
		k = 0;
		while (big[i + k] == little[k] && little[k] && i + k < len)
			k++;
		if (!little[k])
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}

void		init_sflag(t_data *sflag)
{
	sflag->save = 0;
	sflag->map_name = NULL;
	sflag->map_fd = 0;
	sflag->no = NULL;
	sflag->so = NULL;
	sflag->we = NULL;
	sflag->ea = NULL;
	sflag->s = NULL;
	sflag->cel = -1;
	sflag->flor = -1;
	sflag->rx = 0;
	sflag->ry = 0;
	sflag->map = NULL;
	sflag->szmap = 0;
	sflag->plor = '\0';
	sflag->fict = 0;
	sflag->cam.x_max = 0;
	sflag->cam.y_max = 0;
	sflag->cam.x_min = 0;
	sflag->cam.y_min = 0;
	sflag->cam.x_start = -1;
	sflag->cam.y_start = -1;
	sflag->cam.alfa = 0;
	sflag->i1 = 0;
}
