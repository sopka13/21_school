/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:36:43 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:20:31 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		offset(int i, char *str)
{
	char		*temp;

	temp = ft_strdup(str + i + 1);
	if (temp == NULL)
		return (-1);
	ft_bzero(str, BUFFER_SIZE * 2);
	for(int k = 0; k < (int)ft_strlen(temp); k++)
		str[k] = temp[k];
	free(temp);

	return (1);
}

static int		fail(char *str)
{
	ft_bzero(str, BUFFER_SIZE * 2);
	return (-1);
}

static int		cutter(char **line, char* str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n'){
		*line = ft_substr(str, 0, i);
		if (*line == NULL)
			return (fail(str));
	} else if (str[i] == '\0') {
		*line = ft_strdup(str);
		if (*line == NULL)
			return (fail(str));
		ft_bzero(str, BUFFER_SIZE * 2);
		return (0);
	}
	return (offset(i, str));
}

int				get_next_line(int fd, char **line)
{
	static char	str[BUFFER_SIZE * 2];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			n;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	while (!(ft_strchr(str, '\n')) &&
		(n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = '\0';
		temp = ft_strjoin(str, buf);
		if (!temp)
			return (fail(str));
		ft_bzero(str, BUFFER_SIZE * 2);
		for(int k = 0; k < (int)ft_strlen(temp); k++)
			str[k] = temp[k];
		free(temp);
	}
	return (cutter(line, str));
}
