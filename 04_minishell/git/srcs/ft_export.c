/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 01:06:13 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 14:39:32 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Add env var in envp arr
** 	return (1) - Not work
** 	return (2) - Success
** 	return (-1/-2) - Error
*/

#include "../minishell.h"

static int	ft_parse_export(char *str)
{
	if (str[0] >= '0' && str[0] <= '9')
		return (1);
	return (0);
}

static int	ft_export_no_arg(t_vars *vars)
{
	char	*name;
	int		i;

	i = -1;
	while (vars->envp[++i])
	{
		if (!(name = ft_strjoin("declare -x ", vars->envp[i])))
			return (ft_print(strerror(errno), -2));
		ft_write_and_ret(name, "\n", 0);
		free(name);
	}
	return (2);
}

static int	ft_add_name_env(t_vars *vars, char **name)
{
	char	*new_env;

	if (ft_strlen(name[1]) != 0)
		return (0);
	if ((new_env = ft_get_envp(vars, name[0])) != NULL &&
		ft_strlen(new_env) && new_env[ft_strlen(name[0])] == '=')
		return (0);
	if ((vars->envp = ft_rem_elem_arr(vars->envp, name[0])) == NULL ||
		!(vars->envp = ft_putendstr_arr(vars->envp, name[0])))
		return (ft_print(strerror(errno), -2));
	return (0);
	free(name[0]);
	free(name[1]);
}

int			ft_export(t_vars *vars, char **args)
{
	int		i;
	int		ret;
	char	*name[3];

	i = -1;
	if (ft_strcmp(args[0], "export"))
		return (1);
	if (!args[1])
		return (ft_export_no_arg(vars));
	while (args[++i + 1])
	{
		if (ft_parse_export(args[i + 1]))
			return (ft_export_in(vars, args[i + 1], ": invalid identifier\n"));
		if ((ret = ft_valid_name_export(vars, args[i + 1], name)) == -2)
			return (ret);
		if (ret == -1)
			continue;
		if (ft_if_have_equal(name[0]) &&
			(ret = ft_export_s(vars, args, name, i)) != 0)
			return (ret);
		else if ((ret = ft_add_name_env(vars, name)) != 0)
			return (ret);
	}
	return (2);
}
