/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:03:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/03 00:29:27 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int		main(void)
{
	//Default ctor
	Array<int>	arr_1;
	std::cout << arr_1.size() << std::endl;
	try
	{
		std::cout << arr_1.operator[](10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	// Ctor with value
	Array<char> arr_2(10);
	std::cout << arr_2.size() << std::endl;
	try
	{
		for (int i = 0; i < 10; ++i)
			*(arr_2.operator[](i)) = i + 60;
		for (int i = 0; i < 10; ++i)
			std::cout	<< "i = "
						<< i
						<< " value = "
						<< *(arr_2.operator[](i))
						<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}