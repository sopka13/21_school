/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 23:13:29 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/09 13:45:22 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int		main(void)
{
	Span sp = Span(5);
	
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	srand(time(NULL));
	Span	arr(10000);
	for (int i = 0; i < 10000; ++i)
		arr.addNumber(rand());
	std::cout << arr.longestSpan() << std::endl;
	std::cout << arr.shortestSpan() << std::endl;

	int		arr_1[3] = { 1, 2, 3 };
	Span	arr_2(5);
	arr_2.addNumber(arr_1, 3);
	for (int i = 0; i < 3; ++i)
		std::cout << arr_2[i] << std::endl;
}