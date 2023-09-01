/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_elem_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:26:18 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 14:39:32 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Remove str from arr
** 	return (**arr) - Success
** 	return (NULL) - Error
*/

#include "../minishell.h"

static int	ft_write_data_in_arr(char **arr, char **arr_1, char const *str)
{
	int		i;
	int		k;

	i = -1;
	k = 0;
	while (arr[++i])
	{
		if (((!(ft_strcmp(arr[i], str)) ||
			(!ft_strncmp(arr[i], str, (ft_strlen(str) - 1)) &&
			ft_if_have_equal(str) && arr[i][ft_strlen(str) - 1] == '=')) &&
			(int)ft_strlen(str) != 0) ||
			((int)ft_strlen(str) == 0 && (int)ft_strlen(arr[i]) == 0))
		{
			free(arr[i]);
			continue;
		}
		if (!(arr_1[k++] = ft_strdup(arr[i])))
			return (ft_print(strerror(errno), -2));
		free(arr[i]);
	}
	free(arr);
	return (0);
}

char		**ft_rem_elem_arr(char **arr, char const *str)
{
	int		size;
	char	**arr_1;
	int		i;

	size = ft_size_arr(arr);
	i = -1;
	while (arr[++i])
		if (((!(ft_strcmp(arr[i], str)) ||
			(!ft_strncmp(arr[i], str, (ft_strlen(str) - 1)) &&
			ft_if_have_equal(str) && arr[i][ft_strlen(str) - 1] == '=')) &&
			(int)ft_strlen(str) != 0) ||
			((int)ft_strlen(str) == 0 && (int)ft_strlen(arr[i]) == 0))
			break ;
	if (i == size)
		return (arr);
	if (!(arr_1 = (char**)ft_calloc(size, sizeof(char*))))
	{
		ft_print(strerror(errno), -2);
		return (NULL);
	}
	arr_1[size - 1] = NULL;
	if ((i = ft_write_data_in_arr(arr, arr_1, str)) < 0)
		return (NULL);
	return (arr_1);
}
