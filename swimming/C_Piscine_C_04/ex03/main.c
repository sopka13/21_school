/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:35:25 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/28 09:59:48 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int	main()
{
	char str[100] = "  -00120";
	char str1[100] = "   ---+--+1234";
	char str2[100] = "abc12345";
    printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
	printf("%d\n", ft_atoi(str1));
	printf("%d\n", ft_atoi(str2));
}
