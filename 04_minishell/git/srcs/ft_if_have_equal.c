/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_have_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:56:59 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/05 13:52:01 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Search '=' in str
** 	return (0) - Not found
** 	return (1) - Found
*/

#include "../minishell.h"

int			ft_if_have_equal(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '=')
			return (1);
	return (0);
}
