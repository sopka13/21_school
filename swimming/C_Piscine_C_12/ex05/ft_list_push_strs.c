/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:34:44 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/06 20:49:11 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*nlist;
	int		i;

	i = 0;
	nlist = 0;
	printf("%s\n", strs[i]);
	while (i < size)
	{
		list = ft_create_elem(strs[i]);
		if (list == 0)
			return (0);
		else
		{
			list->next = nlist;
			list->data = (void*)strs[i];
			nlist = list;
			i++;
		}
	}
	return (list);
}
