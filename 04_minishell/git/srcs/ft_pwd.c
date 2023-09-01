/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:28:28 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 10:43:06 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Handle pwd command
** 	return (1) - not work
** 	return (0) - success
** 	return (-1) - error
*/

#include "../minishell.h"

int			ft_pwd(t_vars *vars, char **args)
{
	char	buf[BUFSIZ];
	char	*adress;
	int		ret;

	if (ft_strcmp(args[0], "pwd") || vars == NULL)
		return (1);
	if (!(adress = getcwd(buf, BUFSIZ)))
		return (ft_print(strerror(errno), -1));
	if ((ret = write(1, buf, ft_strlen(adress))) == -1 ||
		(ret = write(1, "\n", 1)) == -1)
		return (ft_print(strerror(errno), -2));
	return (2);
}
