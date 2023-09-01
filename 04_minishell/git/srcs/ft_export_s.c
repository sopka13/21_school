/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 01:03:33 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 13:58:26 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_export_s(t_vars *vars, char **args, char **name, int i)
{
	char	*name_env;
	char	*new_env;

	if (ft_strlen(args[i + 1]) > (ft_strlen(name[0]) + ft_strlen(name[1])))
	{
		if ((name_env = ft_get_envp(vars, name[0])) != NULL)
		{
			new_env = ft_strjoin(name_env, name[1]);
			if ((vars->envp = ft_rem_elem_arr(vars->envp, name[0])) == NULL ||
				!(vars->envp = ft_putendstr_arr(vars->envp, new_env)))
				return (ft_print(strerror(errno), -2));
			free(name[0]);
			free(name[1]);
			return (2);
		}
	}
	else
	{
		if ((vars->envp = ft_rem_elem_arr(vars->envp, name[0])) == NULL)
			return (ft_print(strerror(errno), -2));
		if (!(name_env = ft_strjoin(name[0], name[1])) ||
			!(vars->envp = ft_putendstr_arr(vars->envp, name_env)))
			return (ft_print(strerror(errno), -2));
	}
	return (0);
}
