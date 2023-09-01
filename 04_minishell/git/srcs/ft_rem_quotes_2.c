/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_quotes_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:12:46 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 00:24:30 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_rem_quotes_2(t_vars *vars, int *i, int *k)
{
	ft_event(vars, vars->args[*i][*k]);
	if (vars->flags->backslash == 1 && vars->args[*i][*k + 1] != '\'' &&
		vars->args[*i][*k + 1] != '\"')
		ft_event(vars, vars->args[*i][*k]);
}
