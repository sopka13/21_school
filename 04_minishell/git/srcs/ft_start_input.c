/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:48:24 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 15:45:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prepares vars for work
** 	return (1) - Error
** 	return (0) - Success
*/

#include "../minishell.h"

int			ft_start_input(t_vars *vars)
{
	char	*name;
	char	*name_1;
	int		ret;

	name = NULL;
	name_1 = NULL;
	if (!(name_1 = ft_strdup(ft_get_envp(vars, "PATH="))) ||
		!(name = ft_strtrim(name_1, "PATH=\"")) ||
		!(vars->path = ft_split(name, ':')))
		vars->path = NULL;
	ft_free_s(name);
	ft_free_s(name_1);
	ft_clean_vars(vars);
	if (vars->home == 0 &&
		(!(vars->home = ft_strdup(ft_get_envp(vars, "HOME="))) ||
		!(vars->home = ft_strtrim(vars->home, "HOME=\"")) ||
		!(name = ft_strjoin(vars->home, FNAME_HIST))))
		return (ft_print(strerror(errno), 1));
	ft_init_flags(vars);
	if ((ret = isatty(0)) == 1)
		write(1, STR, ft_strlen(STR));
	ft_bzero(&vars->str, sizeof(vars->str));
	return (0);
}
