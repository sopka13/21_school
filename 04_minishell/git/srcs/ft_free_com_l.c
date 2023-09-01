/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_com_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:03:56 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 23:04:10 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function clear com_l list
*/

#include "../minishell.h"

void		ft_free_com_l(t_vars *vars)
{
	int		i;
	int		l;

	i = -1;
	if (vars->com_l != NULL)
	{
		while (vars->com_l[++i])
		{
			l = -1;
			if (vars->com_l[i]->command != NULL)
			{
				while (vars->com_l[i]->command[++l])
					free(vars->com_l[i]->command[l]);
				free(vars->com_l[i]->command);
				vars->com_l[i]->command = NULL;
			}
			free(vars->com_l[i]);
			vars->com_l[i] = NULL;
		}
		free(vars->com_l);
		vars->com_l = NULL;
	}
}
