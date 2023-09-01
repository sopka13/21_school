/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:27:25 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/06 20:29:30 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int					ft_list_size(t_list *begin_list);
void				ft_list_push_front(t_list **begin_list, void *data);
t_list				*ft_create_elem(void *data);

#endif
