/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:20:34 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 17:03:26 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Start exiting the program
**	return (1) - not work
**	return (2) - success
**	return (-1) - error
*/

#include "../minishell.h"

static int	ft_check_exit_arg(char *arg)
{
	int		i;

	i = -1;
	while (arg[++i])
		if ((!ft_isdigit(arg[i]) && arg[i] != '+' && arg[i] != '-') ||
			(i != 0 && (arg[i] == '+' || arg[i] == '-')) ||
			((arg[i] == '+' || arg[i] == '-') && !arg[i + 1]))
			return (1);
	return (0);
}

static int	ft_exit_2_else(t_vars *vars, char **args)
{
	if (ft_check_exit_arg(vars->args[1]))
	{
		vars->flags->status = 2;
		return (ft_print("exit: need a numeric argument", 2));
	}
	else
	{
		if ((vars->flags->status = ft_atoi_exit_status(vars, args[1])) == 0 &&
			vars->flags->error == 1)
		{
			vars->flags->status = 2;
			return (ft_print("exit: need a numeric argument", 2));
		}
	}
	return (0);
}

int			ft_exit_2(t_vars *vars, char **args)
{
	int		ret;

	vars->flags->error = 0;
	if (ft_strcmp(args[0], "exit") || vars == NULL)
		return (1);
	write(1, "exit\n", 6);
	if ((ret = ft_repare_fd(vars)) == -2)
		return (-1);
	if (vars->args[1])
	{
		if (vars->args[2])
		{
			vars->flags->status = 1;
			return (ft_print("exit: too many arguments", 2));
		}
		else if ((ret = ft_exit_2_else(vars, args)) != 0)
			return (ret);
	}
	ft_exit(vars);
	return (2);
}
