/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_arg_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:58:09 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 22:58:10 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_echo_arg_2(t_temp_2 *temp)
{
	free(temp->name_env);
	if (!(temp->name_env = ft_strdup("")))
		return (ft_print(strerror(errno), -2));
	return (0);
}
