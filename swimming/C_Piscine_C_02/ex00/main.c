/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:43:10 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/25 14:43:10 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *a, char *b);

int		main(void)
{
	char dest[100] = "Baaaaaaad';
	char src[100] = "Good";
	char *c;
	char *d;

	c = dest;
	d = src;
	printf("%s\n", dest);
	ft_strcpy(c, d);
	printf("%s\n", dest);
	return (0);
}
