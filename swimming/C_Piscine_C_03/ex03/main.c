/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:43:58 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/26 15:21:00 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char dest[100] = "Hello";
	char src[100] = "World";
	unsigned int nb;

	nb = 7;
	ft_strncat(dest, src, nb);
	printf("%s\n", dest);
	return (0);
}
