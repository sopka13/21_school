/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:56:18 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 20:24:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Every env vars write in std_out
** 	return (1) - not work
** 	return (2) - success
** 	return (-1) - error
*/

#include "../minishell.h"

int			ft_env(t_vars *vars, char **args)
{
	int		i;
	int		ret;

	if (ft_strcmp(args[0], "env"))
		return (1);
	i = -1;
	while (vars->envp[++i])
	{
		if (ft_if_have_equal(vars->envp[i]))
			if ((ret = write(1, vars->envp[i], ft_strlen(vars->envp[i]))) == -1
				|| (ret = write(1, "\n", 1)) == -1)
				return (ft_print(strerror(errno), -2));
	}
	return (2);
}
