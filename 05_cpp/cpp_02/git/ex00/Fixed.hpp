/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:07:55 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/26 16:16:02 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>

class Fixed
{
	int					fixed_point_value;
	static const int	s_number_of_fract = 8;
public:
	Fixed();
	Fixed(int new_fixed_point_value);
	~Fixed();
	Fixed(const Fixed &other);
	Fixed &operator = (const Fixed &fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif