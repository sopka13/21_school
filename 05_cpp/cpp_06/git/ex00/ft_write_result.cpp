/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_result.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:38:51 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/01 10:17:52 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

void	ft_write_result(Scalar &data)
{
	std::cout	<< "char: "
				<< data.getChar()
				<< "\nint: ";
	data.getInt();
	std::cout	<< "\nfloat: ";
	data.getFloat();
	std::cout	<< "\ndouble: ";
	data.getDouble();
	std::cout	<< std::endl;
	return ;
}