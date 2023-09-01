/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:43:10 by eyohn             #+#    #+#             */
/*   Updated: 2020/07/25 17:05:38 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char src[100] = "123432464";

	printf("%s\n", src);
	ft_str_is_numeric(src);
	printf("%d\n", ft_str_is_numeric(src));
	return (0);
}
