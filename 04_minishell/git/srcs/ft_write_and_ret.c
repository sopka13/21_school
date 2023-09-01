/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_and_ret.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 01:04:31 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/02 01:04:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_write_and_ret(char *str_1, char *str_2, int ret)
{
	write(1, str_1, ft_strlen(str_1));
	write(1, str_2, ft_strlen(str_2));
	return (ret);
}
