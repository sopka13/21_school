/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:04:52 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/02 16:06:14 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar()
{}

Scalar::Scalar(std::string str)
{
	m_double = atof(str.c_str());
}

Scalar::Scalar(const Scalar &other)
{
	*this = other;
}

Scalar::~Scalar() {}

const Scalar &	Scalar::operator= (const Scalar &scalar)
{
	if (this != &scalar)
	{
		m_char = scalar.m_char;
		m_double = scalar.m_double;
		m_float = scalar.m_float;
		m_int = scalar.m_int;
	}
	return (*this);
}

std::string		Scalar::getChar()
{
	m_char = static_cast<char>(m_double);
	if (m_double > static_cast<double>(CHAR_MAX) ||
		m_double < static_cast<double>(CHAR_MIN) ||
		isnanf(m_double))
		return ("impossible");
	else if (isprint(m_char))
	{
		std::string temp = "";
		temp = temp + m_char;
		return (temp);
	}
	else
		return ("Non displayable");
}

void			Scalar::getInt()
{
	m_int = static_cast<int>(m_double);
	if (m_double > static_cast<double>(INT_MAX) ||
		m_double < static_cast<double>(INT_MIN) ||
		isnanf(m_double))
		std::cout << "impossible";
	else
		std::cout << m_int;
}

void			Scalar::getFloat()
{
	m_float = static_cast<float>(m_double);
	if (isinff(m_float) == 1)
		std::cout << "+inf";
	else if (isinff(m_float) == -1)
		std::cout << "-inf";
	else if(isnanf(m_float))
		std::cout << "nan";
	else
	{
		std::cout << m_float;
		if (!(m_float - static_cast<float>(static_cast<int>(m_float))))
			std::cout << ".0";
		std::cout << "f";
	}
}
void			Scalar::getDouble()
{
	if (isinff(m_double) == 1)
		std::cout << "+inf";
	else if (isinff(m_double) == -1)
		std::cout << "-inf";
	else if(isnanf(m_double))
		std::cout << "nan";
	else
	{
		std::cout << m_double;
		if (!(m_double - static_cast<double>(static_cast<int>(m_double))))
			std::cout << ".0";
	}
}