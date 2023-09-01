/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:54:42 by heula             #+#    #+#             */
/*   Updated: 2021/04/14 21:05:38 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/lem_in.h"


void	ft_lst_add_back_pn(t_step **lst, t_step *new)
{
	t_step	*back;
	
	if (*lst != NULL)
	{
		back = ft_lstlast_pn(*lst);
		back->next = new;
	}
	else
		*lst = new;
}
