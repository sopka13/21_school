/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:26:55 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:26:58 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_save_flag(char *a, t_data *sflag)
{
	if (ft_strncmp(a, "--save", 6))
		return (1);
	sflag->save = 1;
	return (0);
}

int			ft_if(char **argv, t_data *sflag, int i)
{
	if (i == 1)
		return ((ft_save_flag(argv[1], sflag) || ((int)ft_strlen(argv[2]) < 5)
		|| !ft_strnstr(argv[2], ".cub", MAXLNAME)));
	else if (i == 2)
		return (ft_save_flag(argv[2], sflag) || ((int)ft_strlen(argv[1]) < 5) ||
		!ft_strnstr(argv[1], ".cub", MAXLNAME));
	else if (i == 3)
		return (((int)ft_strlen(argv[1]) < 5) ||
		!ft_strnstr(argv[1], ".cub", MAXLNAME));
	else
		return (0);
}

int			ft_name_map(int argc, char **argv, t_data *sflag)
{
	int		a;

	a = 0;
	if (argc == 3)
	{
		a = ft_if(argv, sflag, 1);
		if (a == 0)
			if (!(sflag->map_name = ft_strdup(argv[2])))
				return (1);
	}
	if (a == 1)
	{
		a = ft_if(argv, sflag, 2);
		if (a == 0)
			if (!(sflag->map_name = ft_strdup(argv[1])))
				return (1);
	}
	if (argc == 2)
	{
		a = ft_if(argv, sflag, 3);
		if (a == 0)
			if (!(sflag->map_name = ft_strdup(argv[1])))
				return (1);
	}
	return (a);
}

int			ft_fileheight(int fd)
{
	char	a;
	int		k;

	k = 0;
	while (read(fd, &a, 1))
	{
		if (a == '\n')
			k++;
	}
	if (k != 0)
		k++;
	return (k);
}

int			ft_no_flag(char *line, t_data *sflag, t_mlx *mlx)
{
	int		i;
	int		leit;
	char	*str;

	i = 0;
	str = ft_strtrim(line, " \t");
	leit = (int)ft_strlen(str);
	if (leit < 6 || (str[i + 1] != 'O' && str[i + 1] != 'o'))
	{
		free(str);
		str = NULL;
		return (1);
	}
	sflag->no = ft_strtrim(str, "NOno \t");
	if (ft_get_texture(&mlx->north, mlx, sflag->no))
		return (1);
	return (0);
}
