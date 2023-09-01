/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:59:21 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/01 16:16:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string new_name)
{
	std::cout	<< "Constructor start "
				<< new_name
				<< ' '
				<< this
				<< std::endl;
	m_name = new_name;
}

Zombie::~Zombie()
{
	std::cout	<< "Destructor start. Name "
				<< m_name
				<< ' '
				<< this
				<< std::endl;
}

void	Zombie::anounce( void )
{
	std::cout << m_name << ' ' << "BraiiiiiiinnnzzzZ..." << std::endl;
}