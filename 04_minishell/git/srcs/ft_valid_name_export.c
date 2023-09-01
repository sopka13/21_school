/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_name_export.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:59:57 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:11:22 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_valid_name_export_2(char *str, char **name)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!ft_valid_env_chr(str[i]))
			break ;
		if (!(name[0] = ft_strputend(name[0], str[i])))
			return (ft_print(strerror(errno), -2));
	}
	return (i);
}

static int	ft_valid_name_eq(t_vars *vars, char **name, char *str, int i)
{
	if (!(name[0] = ft_strputend(name[0], str[i])))
		return (ft_print(strerror(errno), -2));
	while (str[++i])
	{
		ft_event(vars, str[i]);
		if (!(name[1] = ft_strputend(name[1], str[i])))
			return (ft_print(strerror(errno), -2));
	}
	return (0);
}

static int	ft_valid_name_pl(t_vars *vars, char **name, char *str, int i)
{
	if (!(name[0] = ft_strputend(name[0], str[++i])))
		return (ft_print(strerror(errno), -2));
	while (str[++i])
	{
		ft_event(vars, str[i]);
		if (!(name[1] = ft_strputend(name[1], str[i])))
			return (ft_print(strerror(errno), -2));
	}
	return (0);
}

int			ft_valid_name_export(t_vars *vars, char *str, char **name)
{
	int		i;

	if (!(name = ft_valid_name_export_1(name)))
		return (ft_print(strerror(errno), -2));
	if ((i = ft_valid_name_export_2(str, name)) < 0)
		return (i);
	if ((str[i] != '=' && (str[i] != '+' || (str[i] == '+' && !str[i + 1]) ||
		(str[i] == '+' && str[i + 1] != '=')) && str[i] != '\0') || i == 0)
		return (ft_export_in(vars, str, ": invalid identifier\n"));
	else
	{
		if (str[i] == '\0')
			return (0);
		if (str[i] == '=')
		{
			if ((i = ft_valid_name_eq(vars, name, str, i)) != 0)
				return (i);
		}
		else
		{
			if ((i = ft_valid_name_pl(vars, name, str, i)) != 0)
				return (i);
		}
	}
	return (0);
}
