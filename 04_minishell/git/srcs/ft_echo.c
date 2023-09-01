/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:41:27 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 20:25:11 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Write str in stdout
** 	return (1) - Not work
** 	return (2) - Success
** 	return (-1) - Error
*/

#include "../minishell.h"

static int	ft_echo_get_str(char **args, int i, char **buff)
{
	char	*buff_1;

	if (!(buff_1 = ft_strjoin(*buff, args[i])))
		return (ft_print(strerror(errno), -2));
	free(*buff);
	*buff = buff_1;
	if (args[i + 1] && (int)ft_strlen(*buff) != 0)
	{
		if (!(buff_1 = ft_strjoin(*buff, " ")))
			return (ft_print(strerror(errno), -2));
		free(*buff);
		*buff = buff_1;
	}
	return (0);
}

int			ft_echo(t_vars *vars, char **args)
{
	int		i;
	int		ret;
	char	*buff;

	if (ft_strcmp(args[0], "echo") || vars == NULL)
		return (1);
	i = 0;
	if (args[1] != NULL)
		while (!(ft_strncmp(args[i + 1], "-n", (ret =
			(ft_strlen(args[i + 1]) > 2) ? ft_strlen(args[i + 1]) : 2))))
			i++;
	buff = ft_strdup("");
	while (args[++i])
	{
		if ((ret = ft_echo_get_str(args, i, &buff)) < 0)
			return (ret);
	}
	if ((ret = write(1, buff, ft_strlen(buff))) == -1)
		return (-1);
	if ((args[1] && ft_strcmp(args[1], "-n")) || !args[1])
		if ((ret = write(1, "\n", 1)) == -1)
			return (-1);
	free(buff);
	return (2);
}
