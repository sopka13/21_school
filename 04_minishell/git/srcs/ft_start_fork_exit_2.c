/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_fork_exit_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:18:00 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 22:19:16 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_start_fork_exit_2(t_vars *vars)
{
	if (ft_repare_fd(vars) == -2)
		return (-2);
	return (ft_print(strerror(errno), -2));
}
