/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_have_tilda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:57:35 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 22:57:36 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_if_have_tilda(t_vars *vars, char *str, int i)
{
	if (str[i] == '~' && (i == 0 || str[i - 1] == ' ' ||
		str[i - 1] == '\t') && vars->flags->squote == 0 &&
		vars->flags->backslash == 0 && vars->flags->quote == 0 &&
		(ft_strlen(str) == 1 || (str[i + 1] && (str[i + 1] == '/' ||
		str[i + 1] == ' ' || str[i + 1] == '\t')) || !str[i + 1]))
		return (1);
	return (0);
}
