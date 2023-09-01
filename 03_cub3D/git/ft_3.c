/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:26:27 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:26:29 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int			print_error(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
	return (1);
}

char		*ft_strdup(const char *src)
{
	char	*p;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * i + 1);
	if (!p)
		return (NULL);
	while (i >= 0)
	{
		p[i] = src[i];
		i--;
	}
	p[ft_strlen(src)] = '\0';
	return (p);
}

void		init_mlx(t_mlx *mlx, t_data *sflag)
{
	mlx->mlx = mlx_init();
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->bpp = 0;
	mlx->ll = 0;
	mlx->endian = 0;
	ft_bzero(&mlx->north, sizeof(mlx->north));
	ft_bzero(&mlx->south, sizeof(mlx->south));
	ft_bzero(&mlx->west, sizeof(mlx->west));
	ft_bzero(&mlx->east, sizeof(mlx->east));
	ft_bzero(&mlx->sprite, sizeof(mlx->sprite));
	ft_bzero(&mlx->move, sizeof(mlx->move));
	mlx->sflag = sflag;
}
