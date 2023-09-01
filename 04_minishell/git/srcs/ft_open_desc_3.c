/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_desc_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 10:10:15 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 19:13:00 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Open file and dup stdin, handle '>>' character
*/

#include "../minishell.h"

static char	*ft_open_desc_3_nq(t_vars *vars, char *str, int *i)
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

static char	*ft_open_desc_3_q(t_vars *vars, char *str, int *i)
{
	char	*file;

	if (!(file = ft_strdup("")))
		return (ft_ret_null(strerror(errno), -2));
	while (*i < (int)ft_strlen(str) && str[*i] != ' ' &&
			str[*i] != '\t' && str[*i] != '\n' && str[*i] != '<' &&
			str[*i] != '>' && !(str[*i] == '>' &&
			*i < ((int)ft_strlen(str) + 1) && str[*i + 1] == '>') &&
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

static char	*ft_open_desc_3_name(t_vars *vars, char *str, int *i)
{
	if (vars->flags->quote != 0 || vars->flags->squote != 0)
		return (ft_open_desc_3_nq(vars, str, i));
	else
		return (ft_open_desc_3_q(vars, str, i));
}

int			ft_open_desc_3(t_vars *vars, int *i, char *str)
{
	char	*file;
	int		fd;
	int		ret;

	*i += 2;
	while (str[*i] == ' ' || str[*i] == '\t')
		*i += 1;
	ft_event(vars, str[*i]);
	if (!(file = ft_open_desc_3_name(vars, str, i)))
		return (-2);
	*i -= 1;
	if (ft_strlen(file) == 0)
		return (ft_open_desc_synerr(vars));
	if (!(file = ft_strtrim(file, "\'\" \t")))
		return (ft_print(strerror(errno), -2));
	if (ft_strlen(file) == 0)
		return (ft_print("File is missing", -1));
	if ((fd = open(file, O_CREAT | O_RDWR | O_APPEND, 0666)) == -1 ||
		(ret = dup2(fd, 1)) == -1)
		return (ft_print(strerror(errno), -2));
	vars->flags->std_out = 1;
	free(file);
	return (0);
}
