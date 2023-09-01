/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 15:44:47 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/14 10:31:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function write str in std_out and return ret
*/

#include "philo_bonus.h"

int	ft_print(char *str, int ret)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	return (ret);
}
