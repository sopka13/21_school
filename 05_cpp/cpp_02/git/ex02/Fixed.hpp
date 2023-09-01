/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:07:55 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/04 16:44:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>
#include <cmath>

class Fixed
{
	int					fixed_point_value;
	static const int	s_number_of_fract = 8;
public:
	Fixed();														//default constructor
	Fixed(const int new_fixed_point_value);							//constructor with int value
	Fixed(const float new_fixed_point_value);						//constructor with float value
	~Fixed();														//destructor
	Fixed(const Fixed &other);										//copy constructor
	Fixed &operator = (const Fixed &fixed);							//overload to the = operator

	int		getRawBits(void) const;									//return point_value
	void	setRawBits(int const raw);								//set point_value with raw

	float	toFloat(void) const;									//convert point_value to float
	int		toInt(void) const;										//convert point_value to int

	static float	min(const Fixed &one, const Fixed &two);
	static float	max(const Fixed &one, const Fixed &two);

	friend bool operator> (const Fixed &one, const Fixed &two);
	friend bool operator< (const Fixed &one, const Fixed &two);
	friend bool operator>= (const Fixed &one, const Fixed &two);
	friend bool operator<= (const Fixed &one, const Fixed &two);
	friend bool operator== (const Fixed &one, const Fixed &two);
	friend bool operator!= (const Fixed &one, const Fixed &two);

	friend Fixed operator+ (const Fixed &one, const Fixed &two);
	friend Fixed operator- (const Fixed &one, const Fixed &two);
	friend Fixed operator* (const Fixed &one, const Fixed &two);
	friend Fixed operator/ (const Fixed &one, const Fixed &two);

	Fixed &operator++();
	Fixed &operator--();

	Fixed operator++(int);
	Fixed operator--(int);
};

std::ostream &operator<< (std::ostream &out, const Fixed &fixed);	//overload to the << operator


#endif