/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:29:22 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 19:54:10 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_input(int a)
{
	char	in[10];
	int		str_1;

	str_1 = read(a, in, 10);
	if (str_1 >= 4)
	{
		if (in[0] > '0' && in[0] <= '9')
			ft_atoi(in);
		else
			error = 1;
	}
	else if (str_1 < 4)
		error = 1;
	*in_mas = ft_write_in();
	printf("Input ok \n");
}
