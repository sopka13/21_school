/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 20:20:24 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/07 21:34:43 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*f1;

	if ((f1 = (t_btree*)malloc(sizeof(*f1))) != 0)
	{
		f1->left = NULL;
		f1->right = NULL;
		f1->item = item;
		return (f1);
	}
	return (0);
}
