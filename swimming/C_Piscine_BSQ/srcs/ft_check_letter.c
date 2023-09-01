/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:51:53 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 17:28:13 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void ft_check_letter(void)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (i < num)
	{
		k = 0;
		while (in_mas[i][k])
		{
			if (in_mas[i][k] != s1 && in_mas[i][k] != s2 && in_mas[i][k] != '\n')
			{
				error = 1;
			}
			k++;
		}
		i++;
	}
	printf("Check letter ok \n");
}
