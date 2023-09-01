/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 20:54:27 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/09 13:45:22 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <algorithm>

Span::Span():
	m_ints(NULL),
	m_size(0),
	m_count(0)
{}

Span::Span(unsigned int n):
	m_size(n),
	m_count(0)
{
	if (!n)
	{
		m_ints = NULL;
		return ;
	}
	m_ints = new int[n];
	return ;
}

Span::Span(const Span &other)
{
	if (m_ints)
		delete[] m_ints;
	m_size = other.m_size;
	m_count = other.m_count;
	m_ints = new int[m_size];
	for (unsigned int i = 0; i < m_size; ++i)
		m_ints[i] = other.m_ints[i];
	return ;
}

Span::~Span()
{
	if (m_ints)
		delete[] m_ints;
}

const Span		Span::operator= (const Span &span)
{
	if (m_ints)
		delete[] m_ints;
	m_size = span.m_size;
	m_count = span.m_count;
	m_ints = new int[m_size];
	for (unsigned int i = 0; i < m_size; ++i)
		m_ints[i] = span.m_ints[i];
	return (*this);
}

unsigned int	Span::getSize()
{
	return (m_size);
}

void			Span::addNumber(int num)
{
	if (m_count >= m_size)
		throw outOfRange();
	m_ints[m_count] = num;
	m_count++;
}

void			Span::addNumber(int *num, unsigned int size)
{
	if (m_size - m_count < size)
		throw outOfRange();
	for (unsigned int i = 0; i < size; ++i)
	{
		m_ints[m_count + i] = num[i];
	}
	m_count += size;
}

unsigned int	Span::shortestSpan()
{
	if (m_count <= 1)
		throw arrIsSmall();
	unsigned int temp = abs(m_ints[0] - m_ints[1]);
	for (unsigned int i = 0; i < m_count; ++i)
	{
		for (unsigned int k = 0; k < m_count; ++k)
		{
			if (k == i)
				continue;
			if (static_cast<unsigned int>(abs(m_ints[i] - m_ints[k])) < temp)
				temp = abs(m_ints[i] - m_ints[k]);
		}
	}
	return (temp);
}

unsigned int	Span::longestSpan()
{
	if (m_count <= 1)
		throw arrIsSmall();
	// unsigned int temp = abs(m_ints[0] - m_ints[1]);
	// for (unsigned int i = 0; i < m_count; ++i)
	// {
	// 	for (unsigned int k = 0; k < m_count; ++k)
	// 	{
	// 		if (k == i)
	// 			continue;
	// 		if (static_cast<unsigned int>(abs(m_ints[i] - m_ints[k])) > temp)
	// 			temp = abs(m_ints[i] - m_ints[k]);
	// 	}
	// }
	// return (temp);
	return (std::max_element(m_ints, m_ints + m_count) - std::min_element(m_ints, m_ints + m_count));
}

int				Span::operator[] (int num)
{
	if (num < 0 || static_cast<unsigned int>(num) < m_count)
		return (m_ints[num]);
	throw outOfRange();
}