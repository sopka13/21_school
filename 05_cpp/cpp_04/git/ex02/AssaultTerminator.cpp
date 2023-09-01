/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:29:52 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 15:02:04 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout	<< "* teleports from space *"
				<< std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &other)
{
	*this = other;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout	<< "I'll be back..."
				<< std::endl;
}

AssaultTerminator& AssaultTerminator::operator= (const AssaultTerminator &assaultterminator)
{
	if (this == &assaultterminator)
		return (*this);
	return (*this);
}

AssaultTerminator*	AssaultTerminator::clone () const
{
	return (new AssaultTerminator());
}

void		AssaultTerminator::battleCry() const
{
	std::cout	<< "This code is unclean. PURIFY IT!"
				<< std::endl;
}

void		AssaultTerminator::rangedAttack() const
{
	std::cout	<< "* does nothing *"
				<< std::endl;
}

void		AssaultTerminator::meleeAttack() const
{
	std::cout	<< "* attacks with chainfists *"
				<< std::endl;
}
