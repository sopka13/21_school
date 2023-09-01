/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 22:57:41 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 22:57:42 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_not_equal(t_vars *vars, char *str, t_temp_2 *temp)
{
	if (vars->flags->backslash == 1 && temp->i < (int)ft_strlen(str) &&
		str[temp->i + 1] != '\'' && str[temp->i + 1] != '\"' &&
		str[temp->i + 1] != ' ' && ((vars->flags->squote == 0 &&
		(vars->flags->quote == 1 &&
		temp->i < (int)ft_strlen(str) && !ft_isalpha(str[temp->i + 1]))) ||
		(vars->flags->squote == 0 && vars->flags->quote == 0)))
		temp->i += 1;
	if (!(temp->line_out = ft_strputend(temp->line_out, str[temp->i])))
		return (ft_ret_null(strerror(errno), -2));
	return (temp->line_out);
}
