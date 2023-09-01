/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:29:22 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/12 23:07:23 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_input(int a)
{
	char	in[F_STR_SIZE];
	int		str_1;

	str_1 = 0;
	while (read(a, &in[str_1], 1))
	{
		if (in[str_1] == '\n')
			break ;
		str_1++;
	}
	if (str_1 >= 4)
	{
		if (in[0] > '0' && in[0] <= '9')
			ft_atoi(in, (str_1 - 1));
		else
			return (1);
	}
	else if (str_1 < 4)
		return (1);
	*g_map = ft_write_in();
	return (0);
}
