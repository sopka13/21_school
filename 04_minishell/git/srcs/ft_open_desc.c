/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_desc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:54:18 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 17:01:42 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function handle redirect input/output from/in file
*/

#include "../minishell.h"

int			ft_open_desc(t_vars *vars, int *i, char *str)
{
	int		ret;

	if (str[*i] == '<')
	{
		if ((ret = ft_open_desc_1(vars, i, str)) != 0)
			return (ret);
	}
	else if (str[*i] == '>' && *i < (int)ft_strlen(str) && str[*i + 1] != '>')
	{
		if ((ret = ft_open_desc_2(vars, i, str)) != 0)
			return (ret);
	}
	else
	{
		if ((ret = ft_open_desc_3(vars, i, str)) != 0)
			return (ret);
	}
	return (0);
}
