/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:22:06 by eyohn             #+#    #+#             */
/*   Updated: 2020/08/01 09:15:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src);

int		main(void)
{
	char *a;
	char *src = "Hello";

	printf("%p\n", src);
	a = ft_strdup(src);
	printf("%p\n", a);
	return (0);
}
