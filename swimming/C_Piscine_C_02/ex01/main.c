/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:43:10 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/25 14:43:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *a, char *b, unsigned int n);

int		main(void)

{
	char dest[100] = "Baaaaad";
	char src[100] = "Goood";
	unsigned int n;
	char *c;
	char *d;

	n = 3;
	c = dest;
	d = src;
	printf("%s\n", dest);
	ft_strncpy(c, d, n);
	printf("%s\n", dest);
	return (0);
}
