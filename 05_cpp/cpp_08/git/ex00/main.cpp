/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:34:27 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/09 13:45:23 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <deque>

int		main(void)
{
	srand(time(NULL));

	std::deque<int>	arr_1;
	std::deque<int>::iterator iter_1 = arr_1.begin();
	
	// std::vector<int> arr_1;
	// std::vector<int>::iterator iter_1 = arr_1.begin();

	for(int i = 0; i < 10; ++i)
		arr_1.push_back(rand() % (i + 1));		//add numbers to end of the array
	
	std::cout << "start" << std::endl;
	unsigned int	search_value = rand() % 10;
	std::cout << "I'm looking to the number " << search_value << " in array" << std::endl;
	try
	{
		::easyfind(arr_1, search_value);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Value in arr: ";
	while(iter_1 != arr_1.end())
	{
		std::cout << *iter_1 << " ";
		iter_1++;
	}
	std::cout << std::endl;

	return (0);
}