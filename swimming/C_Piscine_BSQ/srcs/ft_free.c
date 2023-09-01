/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:15:24 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 17:46:13 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_free(void)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(in_mas[i]);
		free(in_mas2[i]);
		i++;
	}
}