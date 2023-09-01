/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_dc_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:40:55 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:53:09 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_file_desc_s_red_if_1(t_vars *vars, char *str, int *i)
{
	if ((str[*i] == '>' || str[*i] == '<' || (str[*i] == '>' &&
		*i < (int)ft_strlen(str) + 1 && str[*i + 1] == '>')) &&
		vars->flags->quote == 0 && vars->flags->squote == 0 &&
		vars->flags->backslash == 0)
		return (1);
	return (0);
}

int			ft_file_dc_s(t_vars *vars, char *str, char **line, int *i)
{
	int		ret;

	ft_event(vars, str[*i]);
	if (ft_file_desc_s_red_if_1(vars, str, i))
	{
		if ((ret = ft_open_desc(vars, i, str)) != 0)
			return (ret);
	}
	else
	{
		if (vars->flags->backslash == 0 || (vars->flags->backslash == 1 &&
			*i <= (int)ft_strlen(str) &&
			str[*i + 1] != '>' && str[*i + 1] != '<' && str[*i + 1] != '>'))
		{
			if (!(*line = ft_strputend(*line, str[*i])))
				return (ft_print(strerror(errno), -2));
		}
		else
		{
			if (*i < (int)ft_strlen(str) &&
				!(*line = ft_strputend(*line, str[++*i])))
				return (ft_print(strerror(errno), -2));
		}
	}
	return (0);
}
