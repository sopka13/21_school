/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_26.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:35:02 by eyohn             #+#    #+#             */
/*   Updated: 2021/02/13 14:35:04 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_3(char *str, int *i, int *m, int l)
{
	if (*i < l && str[*i] == '\n')
		*m = 1;
}

static int		ft_2(int fd, char *str, int *i, int *l)
{
	if (*i == 0)
	{
		if (*l > 0)
			ft_bzero(str, *l);
		if ((*l = read(fd, str, BUFFER_SIZE)) == -1)
			return (ft_free_gnl(str));
	}
	return (0);
}

static int		ft_4(char *str, int *i, int *l)
{
	if (*i == BUFFER_SIZE && *l == BUFFER_SIZE)
	{
		*i = 0;
		return (1);
	}
	if (str[*i] == '\n' && *i != *l)
		*i += 1;
	if (*l < BUFFER_SIZE && *i == *l)
		*i = 0;
	return (0);
}

static int		ft_1(char **line, char *out, int c)
{
	if (c == 1)
		return (1);
	*line = out;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static int	i;
	static int	l;
	static char	*str;
	char		*out;
	int			m;

	m = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(out = malloc(sizeof(char))))
		return (-1);
	out[0] = '\0';
	if (i == 0 && !(str = (char*)malloc(sizeof(char) * BUFFER_SIZE)))
		return (ft_free_gnl(out));
	while (1)
	{
		if (ft_2(fd, str, &i, &l) == -1)
			return (ft_free_gnl(out));
		while (i < l && str[i] != '\n')
			out = ft_strputend(out, str[i++]);
		ft_3(str, &i, &m, l);
		if (ft_1(line, out, ft_4(str, &i, &l)) == 1)
			continue;
		if (m == 0 || i == 0)
			free(str);
		return (m);
	}
}
