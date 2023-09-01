/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:43:10 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/25 16:33:21 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str);

char	main(void)
{
	char src[100] = "Goood";

	printf("%s\n", src);
	ft_str_is_alpha(&src);
	printf("%d\n", ft_str_is_alpha(src));
	return (0);
}
