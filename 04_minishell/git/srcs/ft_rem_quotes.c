/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:15:13 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:05:29 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function remove quotes and singlequotes
** 	return (0) - Success
** 	return (-1/-2) - Error
*/

#include "../minishell.h"

static int	ft_if_rem_quotes(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
	}
	return (0);
}

static char	*ft_rem_quotes_write_sec(t_vars *vars, char *str, int *i, int *k)
{
	int		l;
	char	*str_1;
	char	*str_2;

	l = 0;
	if (!(str_1 = ft_strdup("")))
		return (ft_ret_null(strerror(errno), -2));
	while (vars->flags->quote == 1 || vars->flags->squote == 1)
	{
		if (vars->args[*i][*k + 1] && l++ == 0)
		{
			ft_event(vars, vars->args[*i][++*k]);
			if (vars->flags->quote == 0 && vars->flags->squote == 0)
				break ;
		}
		if (!(str_1 = ft_strputend(str_1, vars->args[*i][*k])))
			return (ft_ret_null(strerror(errno), -2));
		if (vars->args[*i][++*k])
			ft_event(vars, vars->args[*i][*k]);
	}
	if (!(str_2 = ft_strjoin(str, str_1)))
		return (ft_ret_null(strerror(errno), -2));
	free(str_1);
	free(str);
	return (str_2);
}

int			ft_rem_quotes(t_vars *vars)
{
	int		i;
	int		k;
	char	*str;

	i = -1;
	while (vars->args[++i])
		if (ft_if_rem_quotes(vars->args[i]))
		{
			if (!(str = ft_rem_quotes_1(vars, str, &k)))
				return (-2);
			while (vars->args[i][++k])
			{
				ft_rem_quotes_2(vars, &i, &k);
				if (vars->flags->quote == 1 || vars->flags->squote == 1)
				{
					if (!(str = ft_rem_quotes_write_sec(vars, str, &i, &k)))
						return (-2);
					continue;
				}
				if (!(str = ft_rem_quotes_3(vars, str, &i, &k)))
					return (-2);
			}
			ft_rem_quotes_4(vars, str, i);
		}
	return (0);
}
