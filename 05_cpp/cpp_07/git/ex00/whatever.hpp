/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:03:35 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/03 01:12:30 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _WHATEVER_HPP_
#define _WHATEVER_HPP_

#include <iostream>

template <typename T>
void	swap(T &first, T &second)
{
	T	temp;

	temp = first;
	first = second;
	second = temp;
	return ;
}

template <typename T>
void	swap(T *first, T *second)
{

	char	*temp = new char[sizeof(T)];

	// temp = first;
	for (unsigned long i = 0; i < sizeof(T); ++i)
		*(temp + i) = *(reinterpret_cast<char*>(first + i));
	// first = second;
	for (unsigned long i = 0; i < sizeof(T); ++i)
		*(reinterpret_cast<char*>(first + i)) = *(reinterpret_cast<char*>(second + i));
	// second = reinterpret_cast<T>temp;
	for (unsigned long i = 0; i < sizeof(T); ++i)
		*(reinterpret_cast<char*>(second + i)) = *(temp + i);

	delete[] temp;
	
	return ;
}

template <typename T>
T		min(T first, T second)
{
	if (first != second)
		if (first < second)
			return (first);
	return (second);
}

template <typename T>
T		max(T first, T second)
{
	if (first != second)
		if (first > second)
			return (first);
	return (second);
}

#endif