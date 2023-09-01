/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:24:38 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/04 20:32:08 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Return number of elements of arr
** 	return (int) - Success
** 	return (-1) - Error
*/

#include "../minishell.h"

int			ft_size_arr(char **arr)
{
	int		i;

	if (!arr)
		return (-1);
	i = -1;
	while (arr[++i])
		;
	return (i);
}
