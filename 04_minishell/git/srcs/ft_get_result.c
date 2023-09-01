/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 23:02:58 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 18:17:08 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Split every command with '|' character and start execute function
**	return (1) - Error
**	return (0) - Success
*/

#include "../minishell.h"

int			ft_get_result(t_vars *vars)
{
	int		i;
	int		k;
	int		ret;
	char	**pipe;
	char	buff[BUFSIZ + 1];

	i = -1;
	while (vars->com_l[++i])
	{
		k = -1;
		while (++k <= vars->com_l[i]->num)
		{
			if (!(vars->pwd = getcwd(buff, BUFSIZ)))
				return (ft_print(strerror(errno), -2));
			vars->flags->std_out = 0;
			if (!(pipe =
				ft_get_command(vars, vars->com_l[i]->command[k], '|')))
				break ;
			ret = ft_start_fork(vars, pipe, 0);
			ft_free_ss(pipe);
			if (ret < 0)
				return (((-1) * ret) - 1);
		}
	}
	return (0);
}
