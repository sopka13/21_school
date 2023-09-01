/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:07:43 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/26 23:49:34 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():												//Constructor
	fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int new_fixed_point_value)				//Constructor with int
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point_value = new_fixed_point_value << s_number_of_fract;
}

Fixed::Fixed(const float new_fixed_point_value)				//Constructor with float
{
	std::cout << "Float constructor called" << std::endl;

	float temp = (1 << s_number_of_fract) * new_fixed_point_value;
	fixed_point_value = roundf(temp);
}

Fixed::~Fixed()												//Destructor
{
	std::cout << "Destructor called" << '\t' << std::endl;
}

Fixed::Fixed(const Fixed &fixed)							//Copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &fixed)
		return (*this);

	fixed_point_value = fixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	fixed_point_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixed_point_value / (1 << this->s_number_of_fract));
}

int Fixed::toInt(void) const
{
	return (this->fixed_point_value >> this->s_number_of_fract);
}

std::ostream &operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
