/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:56:45 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 23:07:01 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocate memory for array and wrie all value
*/

#include "../minishell.h"

char		**ft_envp(char **envp)
{
	char	**arr;
	int		i;
	int		size;

	size = ft_size_arr(envp);
	if (!(arr = (char**)ft_calloc(size + 1, sizeof(char*))))
	{
		ft_print(strerror(errno), -2);
		return (NULL);
	}
	arr[size] = NULL;
	i = -1;
	while (envp[++i])
	{
		if (!(arr[i] = ft_strdup(envp[i])))
		{
			ft_print(strerror(errno), -2);
			return (NULL);
		}
	}
	return (arr);
}
