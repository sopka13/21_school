/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_arg_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:58:00 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 22:58:01 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_echo_arg_3(t_temp_2 *temp)
{
	char	*str_temp;

	free(temp->name_env);
	temp->name_env = ft_get_var_value(temp->env_var);
	if (!(str_temp = ft_strjoin(temp->line_out, temp->name_env)))
		return (ft_print(strerror(errno), -2));
	free(temp->line_out);
	temp->line_out = str_temp;
	free(temp->name_env);
	if (!(temp->name_env = ft_strdup("")))
		return (ft_print(strerror(errno), -2));
	return (0);
}
