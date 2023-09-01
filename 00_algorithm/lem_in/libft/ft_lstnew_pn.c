/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:14:30 by heula             #+#    #+#             */
/*   Updated: 2021/04/14 21:04:57 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


t_step	*ft_lstnew_pn(int index, char old, int prev_room)
{

	t_step	*new;

	new = (t_step *)ft_malloc(sizeof(t_step));
	new->room = index;
	new->old_ch = old;
	new->prev_room = prev_room;
	new->next = NULL;

	return (new);
}
