/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rem_quotes_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:12:35 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/02 20:14:25 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_rem_quotes_1(t_vars *vars, char *str, int *k)
{
	*k = -1;
	ft_init_flags(vars);
	if (!(str = ft_strdup("")))
		return (ft_ret_null(strerror(errno), -2));
	return (str);
}
