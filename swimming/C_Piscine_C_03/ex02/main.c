/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:43:58 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/26 15:08:04 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	ft_strcat(char *dest, char *src);

int	main(void)
{
	char dest[100] = "Hello";
	char src[100] = "World";

	ft_strcat(dest,src);
	printf("%s\n", dest);
	return (0);
}
