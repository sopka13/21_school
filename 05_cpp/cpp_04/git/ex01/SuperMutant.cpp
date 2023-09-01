/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:58:22 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 21:31:29 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout	<< "Gaaah. Me want smash heads!"
				<< std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout	<< "Aaarg..."
				<< " (" << this << ")" << std::endl;
}

void	SuperMutant::takeDamage(unsigned int m)
{
	if ((m - 3) > m_hp)
		m_hp = 0;
	else
		m_hp -= (m - 3);
	return ;
}