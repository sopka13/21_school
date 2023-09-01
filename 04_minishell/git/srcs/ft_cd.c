/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:48:50 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 20:25:13 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Change current dirrectory
** 	return (1) - Not work
** 	return (2) - Success
** 	return (-1/-2) - Error
*/

#include "../minishell.h"

static char	*ft_get_env_value(char *str)
{
	char	*value;
	int		i;

	i = -1;
	while (str[++i] && str[i] != '=')
		;
	if (!(value = ft_strdup("")))
	{
		ft_print(strerror(errno), -2);
		return (NULL);
	}
	while (str[++i])
	{
		if (!(value = ft_strputend(value, str[i])))
		{
			ft_print(strerror(errno), -2);
			return (NULL);
		}
	}
	return (value);
}

static int	ft_check_other_args(t_vars *vars, char **args)
{
	char	*str;
	int		ret;

	if (args[1] != NULL && !ft_strcmp(args[1], "-"))
	{
		if (!(str = ft_get_envp(vars, "OLDPWD=")))
		{
			write(1, "cd: The OLDPWD environment variable not found\n", 46);
			return (2);
		}
		if (!(str = ft_get_env_value(str)))
			return (-2);
		if ((ret = chdir(str)) == -1)
			return (ft_print(strerror(errno), -1));
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
	}
	if (args[1] != NULL && ft_strcmp(args[1], "-") &&
		(ret = chdir(args[1])) == -1)
	{
		vars->flags->status = 1;
		return (ft_print(strerror(errno), -1));
	}
	return (0);
}

int			ft_cd(t_vars *vars, char **args)
{
	int		ret;
	char	buff[BUFSIZ];
	char	*str;
	char	*str_cur;

	if (ft_strcmp(args[0], "cd"))
		return (1);
	if (args[1] && args[2])
		return (ft_print("Too much argements", -1));
	if (!(str_cur = getcwd(buff, BUFSIZ)))
		return (ft_print(strerror(errno), -2));
	if (args[1] == NULL && (ret = chdir(vars->home)) == -1)
		return (ft_print(strerror(errno), -1));
	if ((ret = ft_check_other_args(vars, args)) != 0)
		return (ret);
	if (!(str_cur = ft_strjoin("OLDPWD=", str_cur)))
		return (ft_print(strerror(errno), -2));
	if ((ret = ft_change_env(vars, str_cur)) == -2)
		return (-2);
	if (getcwd(buff, BUFSIZ) == NULL || !(str = ft_strjoin("PWD=", buff)))
		return (ft_print(strerror(errno), -2));
	if (ft_change_env(vars, str))
		return (-2);
	return (2);
}
