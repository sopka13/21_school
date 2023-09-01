/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 08:49:09 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/06 12:16:02 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int main(void)
{
	t_list **head;

	t_list *list = ft_create_elem("test");
	printf("%s\n", list -> data);
	printf("%p\n", list -> next);
	head = &list;
	ft_list_push_front(head, "test1");
	printf("%s\n", (*head) -> data);
    printf("%p\n", (*head) -> next);
	return (0);
}
