/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 08:25:56 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/27 08:39:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdio.h>

int ft_strlen(char *str);

int	main(void)
{
	char str[100] = "Hello World";
	int a;

	a = ft_strlen(str);
	printf("%d\n", a);
}
