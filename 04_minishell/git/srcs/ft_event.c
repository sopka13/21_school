/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:57:28 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 23:06:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** If a = ' or " this function sets the squote/quote flag to 1, or 0
** if we have this character second time
*/

#include "../minishell.h"

int			ft_event(t_vars *vars, char a)
{
	if (a == '\\' && vars->flags->squote == 0)
		vars->flags->backslash = (vars->flags->backslash == 0) ? 1 : 0;
	if (a == '\'' && vars->flags->quote == 0 && vars->flags->backslash == 0)
		vars->flags->squote = (vars->flags->squote == 1) ? 0 : 1;
	if (a == '\"' && vars->flags->squote == 0 && vars->flags->backslash == 0)
		vars->flags->quote = (vars->flags->quote == 1) ? 0 : 1;
	if (a == '&' && vars->flags->squote == 0 && vars->flags->quote == 0)
		vars->flags->and = (vars->flags->and == 0) ? 1 : 2;
	if (a != '&' && vars->flags->and == 1)
		vars->flags->and = 0;
	if (a != ' ' && a != '\t' && a != '\n' && vars->flags->and == 2)
		vars->flags->and = 0;
	if (a != '\\')
		vars->flags->backslash = 0;
	return (0);
}
