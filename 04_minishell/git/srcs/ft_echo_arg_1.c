/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_arg_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:58:15 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 00:22:53 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_echo_arg_1(char *str, t_temp_2 *temp)
{
	while (ft_valid_env_chr(str[++temp->i]))
		if (!(temp->name_env = ft_strputend(temp->name_env, str[temp->i])))
			return (ft_print(strerror(errno), -2));
	temp->i -= 1;
	if (!(temp->name_env = ft_strputend(temp->name_env, '=')))
		return (ft_print(strerror(errno), -2));
	return (0);
}
