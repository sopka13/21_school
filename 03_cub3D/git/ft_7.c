/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:27:18 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:27:20 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_atoi_n(char *str, int *rgb, int n)
{
	int		i;
	int		k;
	int		l;

	i = 0;
	k = -1;
	while (++k < n)
	{
		l = 0;
		while (str[i] && i < (int)ft_strlen(str) && !(ft_isdigit(str[i])))
		{
			if (str[i] != ' ' && str[i] != '\t' && str[i] != '.' &&
			str[i] != ',' && str[i] != ':' && str[i] != ';' && str[i] != 'x')
				return (1);
			i++;
		}
		while (str[i] && i < (int)ft_strlen(str) && ft_isdigit(str[i]))
		{
			rgb[k] = str[i] - '0' + (rgb[k] * 10);
			i++;
			if (++l > 5)
				return (1);
		}
	}
	return (0);
}

int			ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int			ft_c_flag(char *line, t_data *sflag)
{
	int		i;
	char	*str;
	int		rgb[3];

	i = 0;
	while (i < 3)
		rgb[i++] = 0;
	str = ft_strtrim(line, "Cc \t");
	if (ft_atoi_n(str, rgb, 3))
	{
		free(str);
		str = NULL;
		return (1);
	}
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
	{
		free(str);
		str = NULL;
		return (1);
	}
	sflag->cel = ft_create_trgb(0, rgb[0], rgb[1], rgb[2]);
	free(str);
	str = NULL;
	return (0);
}

int			ft_f_flag(char *line, t_data *sflag)
{
	int		i;
	char	*str;
	int		rgb[3];

	i = 0;
	while (i < 3)
		rgb[i++] = 0;
	str = ft_strtrim(line, "Ff \t");
	if (ft_atoi_n(str, rgb, 3))
	{
		free(str);
		str = NULL;
		return (1);
	}
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
	{
		free(str);
		str = NULL;
		return (1);
	}
	sflag->flor = ft_create_trgb(0, rgb[0], rgb[1], rgb[2]);
	free(str);
	str = NULL;
	return (0);
}
