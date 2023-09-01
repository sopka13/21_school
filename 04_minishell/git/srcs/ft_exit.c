/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <900prod@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:45:14 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 18:03:11 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Exit function
** free allocated memory and return tty settings
*/

#include "../minishell.h"

void		ft_exit(t_vars *vars)
{
	int		ret;

	ft_free_com_l(vars);
	if (vars->home != NULL)
		free(vars->home);
	if (vars->path != NULL)
		ft_free_ss(vars->path);
	if (vars->envp != NULL)
		ft_free_ss(vars->envp);
	if (vars->args != NULL)
		ft_free_ss(vars->args);
	if ((ret = isatty(0)) == 1)
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &vars->termos->old);
	exit(vars->flags->status);
}
