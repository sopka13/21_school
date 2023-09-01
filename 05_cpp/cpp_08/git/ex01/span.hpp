/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 20:35:33 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/09 13:45:21 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <iostream>
#include <math.h>

class Span
{
	int				*m_ints;
	unsigned int	m_size;
	unsigned int	m_count;
	class	outOfRange : public std::exception {
		const char* what() const throw() {
			return ("Array is full");
		}
	};
	class	arrIsSmall : public std::exception {
		const char* what() const throw() {
			return ("Array is small");
		}
	};
public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	~Span();

	const Span		operator= (const Span &span);
	unsigned int	getSize();

	void			addNumber(int num);
	void			addNumber(int *num, unsigned int size);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	int				operator[] (int num);
};


#endif