/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:34:47 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/06 20:34:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <iostream>
#include <algorithm>

class notFound : public std::exception {
	const char* what() const throw() {
		return ("Element not found");
	}
};

template <typename T>
void	easyfind(T first, int second)
{
	typename T::iterator	is_it;
	if ((is_it = std::find(first.begin(), first.end(), second)) != first.end())
		std::cout << "I found this element: " << *is_it << std::endl;
	else
		throw notFound();
}

#endif