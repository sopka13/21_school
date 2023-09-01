/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:45:24 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/03 00:29:05 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <iostream>

template <typename T>
class Array
{
	T				*m_arr;
	unsigned int	m_size;
	class	ArrOut : public std::exception {
		const char* what() const throw(){
			return ("Array out of bounds");
		}
	};
public:
	Array() : m_arr(NULL), m_size(0) {}
	Array(unsigned int n) : m_size(n) { m_arr = new T[n]; }
	Array(const Array &other) : m_arr(NULL), m_size(0) { *this = other; }
	~Array() { if (m_arr) delete[] m_arr; }

	T*			operator[] (int index)
	{
		if (index < 0 || index > static_cast<int>(m_size - 1))
			throw ArrOut();
		return (&m_arr[index]);
	}
	const Array	&operator= (const Array &array)
	{
		if (m_arr)
			delete[] m_arr;
		m_size = array.m_size;
		m_arr = new T[m_size];
		for (int i = 0; i < m_size; ++i)
			m_arr[i] = array.m_arr[i];
		return (*this);
	}
	unsigned int	size(void) const { return (m_size); }
};

#endif