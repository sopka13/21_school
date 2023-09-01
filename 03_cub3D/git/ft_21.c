/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_21.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:34:22 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:34:23 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					ft_header(int fd, int size, t_mlx *mlx)
{
	int				i;
	unsigned char	header[54];

	i = 0;
	while (i < 54)
	{
		header[i] = (unsigned char)(0);
		i++;
	}
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	ft_char(header + 2, size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	ft_char(header + 18, mlx->sflag->rx);
	ft_char(header + 22, mlx->sflag->ry);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

int					ft_pixel(t_mlx *mlx, int x, int y)
{
	char			*color;

	color = mlx->addr + (y * mlx->ll + x * (mlx->bpp / 8));
	return (*(int*)color);
}

int					ft_write_bmp(int fd, t_mlx *mlx)
{
	int				i;
	int				j;
	int				color;

	i = mlx->sflag->ry - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < mlx->sflag->rx)
		{
			color = ft_pixel(mlx, j, i);
			if (write(fd, &color, 3) < 0)
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

int					ft_save(t_mlx *mlx)
{
	int				filesize;
	int				fd;

	filesize = 54 + (4 * ((int)mlx->sflag->rx) * (int)mlx->sflag->ry);
	if ((fd = open("save.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666)) == -1)
		return (print_error(strerror(errno)));
	if (!ft_header(fd, filesize, mlx))
		return (print_error("Error write file\n"));
	if (!ft_write_bmp(fd, mlx))
		return (print_error("Error write file\n"));
	close(fd);
	return (1);
}
