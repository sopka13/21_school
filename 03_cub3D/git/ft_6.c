/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:27:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:27:08 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_so_flag(char *line, t_data *sflag, t_mlx *mlx)
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
	sflag->so = ft_strtrim(str, "SOso \t");
	if (ft_get_texture(&mlx->south, mlx, sflag->so))
		return (1);
	return (0);
}

int			ft_s_flag(char *line, t_data *sflag, t_mlx *mlx)
{
	int		leit;
	char	*str;

	str = ft_strtrim(line, " \t");
	leit = (int)ft_strlen(str);
	if (leit < 5)
	{
		free(str);
		str = NULL;
		return (1);
	}
	sflag->s = ft_strtrim(str, "Ss \t");
	if (ft_get_texture(&mlx->sprite, mlx, sflag->s))
		return (1);
	return (0);
}

int			ft_we_flag(char *line, t_data *sflag, t_mlx *mlx)
{
	int		i;
	int		leit;
	char	*str;

	i = 0;
	str = ft_strtrim(line, " \t");
	leit = (int)ft_strlen(str);
	if (leit < 6 || (str[i + 1] != 'E' && str[i + 1] != 'e'))
	{
		free(str);
		str = NULL;
		return (1);
	}
	sflag->we = ft_strtrim(str, "WEwe \t");
	if (ft_get_texture(&mlx->west, mlx, sflag->we))
		return (1);
	return (0);
}

int			ft_ea_flag(char *line, t_data *sflag, t_mlx *mlx)
{
	int		i;
	int		leit;
	char	*str;

	i = 0;
	str = ft_strtrim(line, " \t");
	leit = (int)ft_strlen(str);
	if (leit < 6 || (str[i + 1] != 'A' && str[i + 1] != 'a'))
	{
		free(str);
		str = NULL;
		return (1);
	}
	sflag->ea = ft_strtrim(str, "EAea \t");
	if (ft_get_texture(&mlx->east, mlx, sflag->ea))
		return (1);
	return (0);
}
