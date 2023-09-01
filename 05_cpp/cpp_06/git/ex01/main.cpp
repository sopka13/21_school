/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 09:34:00 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/02 10:18:24 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.hpp"

uintptr_t	serialise(Data *ptr)
{
	uintptr_t	data;

	data = 0;
	data = ptr->x;
	data = data << 32;
	data += ptr->y;
	return (data);
}

Data		*deserialise(uintptr_t raw)
{
	Data		*ret = new(Data);
	uintptr_t	temp_1;
	
	temp_1 = raw >> 32;
	ret->x = (int)temp_1;
	temp_1 = raw << 32;
	temp_1 = temp_1 >> 32;
	ret->y = (int)temp_1;
	return (ret);
}

int		main(void)
{
	// std::cout << sizeof(Data) << std::endl;
	// std::cout << sizeof(uintptr_t) << std::endl;

	Data		data_1;
	Data		*data_2;
	uintptr_t	ret;

	data_1.x = 999999;
	data_1.y = -2345;

	ret = serialise(&data_1);
	data_2 = deserialise(ret);

	std::cout << data_2->x << std::endl;
	std::cout << data_2->y << std::endl;

	delete data_2;

	return (0);
}