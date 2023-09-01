/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_get_com.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:07:49 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:27:57 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_start_get_com(t_vars *vars, char *str, t_temp_1 *tp)
{
	if ((int)ft_strlen(str) == 0)
		return (ft_get_com_syntax_err_1(vars));
	tp->i = -1;
	tp->k = -1;
	return (0);
}
