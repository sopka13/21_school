/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:52:44 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/06 20:41:26 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *list;
	t_list *f;

	f = *begin_list;
	list = malloc(sizeof(*list));
	if (list == NULL)
		return (0);
	else
	{
		list->data = data;
		list->next = NULL;
	}
	while (f->next != NULL)
	{
		f = f->next;
	}
	f->next = list;
	return (f);
}
