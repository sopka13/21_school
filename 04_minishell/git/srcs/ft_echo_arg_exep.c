/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_arg_exep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:57:22 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:50:04 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_echo_arg_exeption_1(t_temp_2 *temp, char **name_env,
			char **line_out_temp)
{
	free(*name_env);
	free(temp->line_out);
	temp->line_out = *line_out_temp;
	temp->i += 1;
}

int			ft_echo_arg_exep(t_vars *vars, char *str, t_temp_2 *temp)
{
	char	*name_env;
	char	*line_out_temp;

	if (str[temp->i + 1] == '?')
	{
		name_env = ft_itoa(vars->flags->status);
		if (!(line_out_temp = ft_strjoin(temp->line_out, name_env)))
			return (ft_print(strerror(errno), -2));
		ft_echo_arg_exeption_1(temp, &name_env, &line_out_temp);
	}
	else if (ft_isdigit(str[temp->i + 1]))
	{
		if (ft_atoi(&str[temp->i + 1]) < vars->argc)
		{
			if (!(line_out_temp = ft_strjoin(temp->line_out,
				vars->argv[ft_atoi(&str[temp->i + 1])])))
				return (ft_print(strerror(errno), -2));
			free(temp->line_out);
			temp->line_out = line_out_temp;
		}
		temp->i += 1;
	}
	else if (!(temp->line_out = ft_strputend(temp->line_out, str[temp->i])))
		return (ft_print(strerror(errno), -2));
	return (0);
}
