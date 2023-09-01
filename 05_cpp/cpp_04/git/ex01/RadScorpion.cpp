/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:03:28 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout	<< "* click click click *"
				<< " (" << this << ")" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout	<< "* SPROTCH *"
				<< " (" << this << ")" << std::endl;
}