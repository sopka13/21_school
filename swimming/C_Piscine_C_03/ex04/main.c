/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:43:58 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/26 19:17:42 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);
int	ft(char *str, char *to_find);


int	main(void)
{
	char str[100] = "Hello World and happy people";
	char to_find[100] = "World";

	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}
