/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_desc_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:12:42 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 16:06:23 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Open file and dup stdin, handle '<' character
*/

#include "../minishell.h"

static char	*ft_open_desc_1_nq(t_vars *vars, char *str, int *i)
{
	char	*file;

	if (!(file = ft_strdup("")))
		return (ft_ret_null(strerror(errno), -2));
	while (*i < (int)ft_strlen(str) && (vars->flags->quote != 0 ||
			vars->flags->squote != 0))
	{
		if (vars->flags->backslash == 0 || vars->flags->squote == 1)
			if (!(file = ft_strputend(file, str[*i])))
				return (ft_ret_null(strerror(errno), -2));
		*i += 1;
		ft_event(vars, str[*i]);
	}
	if (!(file = ft_strputend(file, str[*i])))
		return (ft_ret_null(strerror(errno), -2));
	*i += 1;
	return (file);
}

static char	*ft_open_desc_1_q(t_vars *vars, char *str, int *i)
{
	char	*file;

	if (!(file = ft_strdup("")))
		return (ft_ret_null(strerror(errno), -2));
	while (*i < (int)ft_strlen(str) && str[*i] != ' ' &&
			str[*i] != '\t' && str[*i] != '\n' && str[*i] != '>' &&
			str[*i] != '<' && !(str[*i] == '>' &&
			*i < (int)ft_strlen(str) + 1 && str[*i + 1] == '>') &&
			vars->flags->quote == 0 && vars->flags->squote == 0)
	{
		if (vars->flags->backslash == 0)
			if (!(file = ft_strputend(file, str[*i])))
				return (ft_ret_null(strerror(errno), -2));
		*i += 1;
		ft_event(vars, str[*i]);
	}
	return (file);
}

static char	*ft_open_desc_1_name(t_vars *vars, char *str, int *i)
{
	if (vars->flags->quote != 0 || vars->flags->squote != 0)
		return (ft_open_desc_1_nq(vars, str, i));
	else
		return (ft_open_desc_1_q(vars, str, i));
}

int			ft_open_desc_1(t_vars *vars, int *i, char *str)
{
	char	*file;
	int		fd;

	*i += 1;
	while (str[*i] == ' ' || str[*i] == '\t')
		*i += 1;
	ft_event(vars, str[*i]);
	if (!(file = ft_open_desc_1_name(vars, str, i)))
		return (-2);
	*i -= 1;
	if (ft_strlen(file) == 0)
		return (ft_open_desc_synerr(vars));
	if (!(file = ft_strtrim(file, "\'\"")))
		return (ft_print(strerror(errno), -2));
	if (!(file = ft_strtrim(file, " \t")))
		return (ft_print(strerror(errno), -2));
	if (ft_strlen(file) == 0)
		return (ft_print("File is missing", -1));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_non_file(vars));
	if (dup2(fd, 0) == -1)
		return (ft_print(strerror(errno), -2));
	free(file);
	return (0);
}
