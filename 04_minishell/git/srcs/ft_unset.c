/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:47:23 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 14:39:31 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Equates to zero variables
** 	return (1) - Not work
** 	return (2) - Success
** 	return (-1) - Error
*/

#include "../minishell.h"

int			ft_unset(t_vars *vars, char **args)
{
	int		i;

	if (ft_strcmp(args[0], "unset"))
		return (1);
	if (!(args[1]))
		return (2);
	i = -1;
	while (vars->envp[++i])
	{
		if (!(ft_strncmp(vars->envp[i], args[1], ft_strlen(args[1]))) &&
			(vars->envp[i][ft_strlen(args[1])] == '=' ||
			vars->envp[i][ft_strlen(args[1])] == '\0'))
		{
			if (!(vars->envp = ft_rem_elem_arr(vars->envp, vars->envp[i])))
				return (ft_print(strerror(errno), -2));
			break ;
		}
	}
	return (2);
}
