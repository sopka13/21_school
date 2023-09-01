/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:56:01 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:53:25 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function count sections betwen the 'a' character in str
** 	return number of sections
*/

#include "../minishell.h"

static int	ft_num_1(t_vars *vars, char *str, char a, int i)
{
	if (vars->flags->squote == 0 && vars->flags->quote == 0 &&
		vars->flags->backslash == 0 && ((a != '&' && i < (int)ft_strlen(str) &&
		str[i + 1] == '\0' && str[i] != a) || (a == '&' && str[i] == '&' &&
		i != 0 && str[i - 1] != '&' && i + 1 < (int)ft_strlen(str) &&
		str[i + 1] == '&') || (a == '&' && i < (int)ft_strlen(str) &&
		str[i + 1] == '\0' && str[i] != '&')))
		return (1);
	return (0);
}

static int	ft_num_2(t_vars *vars, char *str, char a, int i)
{
	if (vars->flags->squote == 0 && vars->flags->quote == 0 &&
		vars->flags->backslash == 0 && ((a == '&' && str[i] == '&' &&
		i + 1 < (int)ft_strlen(str) && str[i + 1] != '&') ||
		(a == '&' && str[i] == '&' && i + 1 < (int)ft_strlen(str) &&
		str[i + 1] == '&' && i + 2 < (int)ft_strlen(str) &&
		str[i + 2] == '&') || (a != '&' && str[i] == a && a != ' ' &&
		a != '\t' && i + 1 < (int)ft_strlen(str) && str[i + 1] == a)))
		return (1);
	return (0);
}

static int	ft_num_3(t_vars *vars, char *str, char a, int i)
{
	if ((a == '&' && str[i] == '&' && i + 1 < (int)ft_strlen(str) &&
		str[i + 1] == '&' && vars->flags->squote == 0 &&
		vars->flags->quote == 0) || (vars->flags->backslash == 1 &&
		i + 1 < (int)ft_strlen(str) && str[i + 2] != '\0'))
		return (1);
	return (0);
}

int			ft_num(t_vars *vars, char *str, char a)
{
	int		i;
	int		n;

	i = -1;
	n = 0;
	while (str[++i])
	{
		ft_event(vars, str[i]);
		if (ft_num_1(vars, str, a, i))
			n++;
		if (vars->flags->backslash == 1 && i + 1 == (int)ft_strlen(str))
			n++;
		if (ft_num_if_1(vars, str, a, i))
		{
			n++;
			if (!ft_only_space(str, i))
				break ;
		}
		if (ft_num_2(vars, str, a, i))
			return (-1);
		if (ft_num_3(vars, str, a, i))
			ft_event(vars, str[i++]);
	}
	return (n = (n == 0) ? 1 : n);
}
