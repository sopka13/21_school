/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_strt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:51:18 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 17:01:28 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Consideration of conditions and change descriptors
*/

#include "../minishell.h"

int			ft_check_strt(t_vars *vars, int const num, char **pipe_str)
{
	int		ret;

	if ((ret = ft_file_desc(vars, pipe_str[num])) != 0)
		return (ret);
	if (pipe_str[num + 1] && (ret = dup2(vars->flags->fd[1], 1)) == -1)
		return (ft_print(strerror(errno), -2));
	vars->flags->error = 0;
	return (0);
}
