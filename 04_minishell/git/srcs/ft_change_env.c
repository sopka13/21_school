/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:50:29 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:41:25 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Change env vars
** 	return (0) - Success
** 	return (-1/-2) - Error
*/

#include "../minishell.h"

static int	ft_name_env(char *env)
{
	int		i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (i);
}

int			ft_change_env(t_vars *vars, char *env)
{
	int		i;
	int		num;

	i = -1;
	num = ft_name_env(env);
	while (vars->envp[++i])
	{
		if (!(ft_strncmp(vars->envp[i], env, num)))
		{
			free(vars->envp[i]);
			if (!(vars->envp[i] = env))
				return (ft_print(strerror(errno), -2));
			break ;
		}
	}
	if (vars->envp[i] == NULL)
		if (!(vars->envp = ft_putendstr_arr(vars->envp, env)))
			return (ft_print(strerror(errno), -2));
	return (0);
}
