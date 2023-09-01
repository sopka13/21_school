/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:27:22 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 22:27:47 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Realloc memory for array
** 	return (NULL) - Error
** 	return (**arr) - Success
*/

#include "../minishell.h"

char		**ft_realloc_arr(char **arr, int n, int size)
{
	char	**mass;
	int		i;
	int		k;

	if (!arr || n == 0 || size == 0 ||
		!(mass = (char**)ft_calloc(n + 1, size)))
		return (NULL);
	mass[n] = NULL;
	i = ft_size_arr(arr);
	k = -1;
	while (++k < i)
		mass[k] = arr[k];
	while (k < i)
		free(arr[k++]);
	free(arr);
	return (mass);
}
