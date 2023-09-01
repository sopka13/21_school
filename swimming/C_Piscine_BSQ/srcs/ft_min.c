/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:27:25 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/11 15:54:36 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if ((b < a && b < c) || (b < a && b <= c) || (b < c && b <= a))
		return (b);
	else if ((c < a && c < b) || (c < a && c <= b) || (c < b && c <= a))
		return (c);
	else
		return (a);
}
