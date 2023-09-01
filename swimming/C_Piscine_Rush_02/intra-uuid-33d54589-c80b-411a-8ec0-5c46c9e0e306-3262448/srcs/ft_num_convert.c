/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtrin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 22:42:44 by rtrin             #+#    #+#             */
/*   Updated: 2020/08/09 22:46:58 by rtrin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_clear_buf(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
		str[i++] = '\0';
}

void	ft_num_convert(int len, int p)
{
	char	buf[3];
	int		j;
	int		k;

	if (len > 0)
	{
		ft_clear_buf(buf, sizeof(buf));
		k = (len - 3) < 0 ? 0 : (len - 3);
		j = 0;
		while (k < len)
			buf[j++] = g_num_str[k++];
		if (ft_atoi(buf) == 0 && ft_strlen(buf) > 1)
			ft_num_convert(len - 3, p + 1);
		else
		{
			ft_num_convert(len - 3, p + 1);
			ft_wordify(ft_atoi(buf), p);
		}
	}
}
