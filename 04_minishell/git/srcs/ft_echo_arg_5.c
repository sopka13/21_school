/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_arg_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:51:43 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:49:48 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_echo_arg_if_2(char *str, int i)
{
	if ((i + 1 < (int)ft_strlen(str) && (ft_isdigit(str[i + 1]) ||
		!ft_valid_env_chr(str[i + 1]))) ||
		(i + 1 == (int)ft_strlen(str)))
		return (1);
	return (0);
}

static int	ft_echo_arg_if_3(t_vars *vars, t_temp_2 *temp)
{
	if ((int)ft_strlen(temp->name_env) == 0 ||
		!(temp->env_var = ft_get_envp(vars, temp->name_env)))
		return (1);
	return (0);
}

int			ft_echo_arg_5(t_vars *vars, char *str, t_temp_2 *temp)
{
	if (ft_echo_arg_if_2(str, temp->i))
	{
		if (ft_echo_arg_exep(vars, str, temp))
			return (-1);
		return (1);
	}
	if (ft_echo_arg_1(str, temp))
		return (-1);
	if (ft_echo_arg_if_3(vars, temp))
	{
		if (ft_echo_arg_2(temp))
			return (-1);
		return (1);
	}
	if (ft_echo_arg_3(temp))
		return (-1);
	return (0);
}
