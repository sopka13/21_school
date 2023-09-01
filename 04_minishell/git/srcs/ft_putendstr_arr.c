/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendstr_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:28:56 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 22:30:13 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds str to the end of arr
** 	return (**arr) - Success
** 	return (NULL) -Error
*/

#include "../minishell.h"

char		**ft_putendstr_arr(char **arr, char *str)
{
	char	**mass;
	int		i;

	if (!arr || !str)
		return (NULL);
	i = ft_size_arr(arr);
	if (!(mass = ft_realloc_arr(arr, i + 1, sizeof(char*))))
		return (NULL);
	mass[i] = str;
	return (mass);
}
