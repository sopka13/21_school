/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:59:03 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/06 20:21:18 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc(sizeof(*list));
	if (list == NULL)
		return (0);
	else
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}
