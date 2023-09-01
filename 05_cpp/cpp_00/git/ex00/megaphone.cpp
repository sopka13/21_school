/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:01:34 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/24 14:56:16 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static int	ft_strlen(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			main(int argc, char **argv)
{
	int		i;
	int		k;

	i = 0;
	while (++i < argc)
	{
		k = -1;
		while (++k < ft_strlen(argv[i]))
		{
			if (islower(argv[i][k]))
				std::cout << (char)(argv[i][k] - 32);
			else
				std::cout << (char)argv[i][k];
		}
		std::cout << ' ';
	}
	std::cout << '\n';
	return (0);
}