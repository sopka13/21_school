/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:07:58 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 21:46:03 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Clearing the struct before are new input
**	return (0) - not used
*/

#include "../minishell.h"

int			ft_clean_vars(t_vars *vars)
{
	ft_free_com_l(vars);
	if (vars->args != 0x0)
	{
		ft_free_ss(vars->args);
		vars->args = NULL;
	}
	return (0);
}
