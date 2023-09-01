/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 09:11:21 by rtrin             #+#    #+#             */
/*   Updated: 2020/08/09 22:59:31 by rtrin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_validate_number(void)
{
	int		i;
	int		k;
	char	str[g_num_len];

	if (g_num_len == 0)
		g_num_len = ft_strlen(g_num_str);
	i = 0;
	k = 0;
	while (i < g_num_len && g_num_str[i] == '0' && g_num_str[i + 1] == '0')
		i++;
	while (i < g_num_len && g_err == 0)
	{
		if (ft_is_dec(g_num_str[i]))
			str[k++] = g_num_str[i++];
		else
			g_err = 1;
	}
	g_num_len = k;
	g_num_str = str;
}
