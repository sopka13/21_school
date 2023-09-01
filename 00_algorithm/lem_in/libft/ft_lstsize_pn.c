/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:30:47 by heula             #+#    #+#             */
/*   Updated: 2020/11/19 22:39:23 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize_pn(t_step *lst)
{
	t_step	*move;
	int		size;

	size = 1;
	move = lst;
	if (!lst)
		return (0);
	while (move->next != NULL)
	{
		size++;
		move = move->next;
	}
	return (size);
}
