/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 22:43:43 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 15:45:50 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Search str in envitonment vars and return a pointer to the found string
** 	return (NULL) - no maches found
** 	return (...) - string found
*/

#include "../minishell.h"

char		*ft_get_envp(t_vars *vars, char *str)
{
	char	**env;
	char	*thisenv;

	env = vars->envp;
	while (*env != 0)
	{
		thisenv = *env;
		if (!ft_strncmp(thisenv, str, ft_strlen(str)))
			return (*env);
		env++;
	}
	return (NULL);
}
