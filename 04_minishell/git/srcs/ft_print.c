/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:29:42 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 22:30:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Write wait string and print passing string
** 	return (a)
*/

#include "../minishell.h"

int			ft_print(char *str, int a)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	return (a);
}
