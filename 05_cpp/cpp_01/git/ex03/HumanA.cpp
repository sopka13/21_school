/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:27:32 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/01 17:25:15 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA()
{
	m_name = "Noname";
	return ;
}

HumanA::HumanA(std::string name, Weapon &arm)
{
	m_name = name;
	m_armor = &arm;
	return ;
}

void	HumanA::attack()
{
	std::cout	<< m_name
				<< " attack with his "
				<< m_armor->getType()
				<< std::endl;
	return ;
}