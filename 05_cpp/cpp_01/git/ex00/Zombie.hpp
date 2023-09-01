/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:59:13 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/01 15:42:30 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ZOMBIE_HPP_
#define _ZONBIE_HPP_

#include <iostream>

class	Zombie
{
	std::string		m_name;
public:
	Zombie(std::string new_name = "no name");
	~Zombie();

	void	anounce( void );
};

Zombie*		newZombie( std::string name );
void		randomChump( std::string name );

#endif
