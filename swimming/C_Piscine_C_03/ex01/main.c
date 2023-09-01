/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:43:58 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/26 14:27:23 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char a[100] = "ABCDDa";
	char b[100] = "ABCDEb";
	unsigned int n;
	char *s1;
	char *s2;

	s1 = a;
	s2 = b;
	n = 5;
	printf("%d\n", ft_strncmp(s1, s2, n));
	return (0);
}
