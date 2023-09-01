/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_com_if_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 23:07:34 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/03 23:27:47 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			ft_get_com_if_4(char a, t_temp_1 *tp)
{
	if ((int)ft_strlen(tp->strk[tp->i]) == 0 ||
		(!ft_only_space(tp->strk[tp->i], -1) &&
		a != ' ' && tp->i + 1 < tp->num) ||
		(!ft_only_space(tp->strk[tp->i], -1) &&
		(a == '&' || a == '|') && tp->i + 1 == tp->num))
		return (1);
	return (0);
}
