/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_arg_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:57:13 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 18:00:47 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_echo_arg_start(t_vars *vars, t_temp_2 *temp)
{
	if (!(temp->line_out = ft_strdup("")))
		return (ft_print(strerror(errno), -2));
	if (!(temp->name_env = ft_strdup("")))
		return (ft_print(strerror(errno), -2));
	temp->i = -1;
	ft_init_flags(vars);
	return (0);
}
