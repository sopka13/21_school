/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:55:05 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/01 22:55:09 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function check last segment str and return 1 if have character other
** 	than space and tab
** 	return (1) - Have
** 	return (0) - Dont have
*/

#include "../minishell.h"

int			ft_only_space(char *str, int i)
{
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
	return (0);
}
