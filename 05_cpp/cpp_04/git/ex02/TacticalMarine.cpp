/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:29:55 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 15:02:04 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout	<< "Tactical Marine ready for battle!"
				<< std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &other)
{
	*this = other;
}

TacticalMarine::~TacticalMarine()
{
	std::cout	<< "Aaargh..."
				<< std::endl;
}

TacticalMarine& TacticalMarine::operator= (const TacticalMarine &tacticalmarine)
{
	if (this == &tacticalmarine)
		return (*this);
	return (*this);
}

TacticalMarine*	TacticalMarine::clone () const
{
	return (new TacticalMarine());
}

void		TacticalMarine::battleCry() const
{
	std::cout	<< "For the holy PLOT!"
				<< std::endl;
}

void		TacticalMarine::rangedAttack() const
{
	std::cout	<< "* attacks with a bolter *"
				<< std::endl;
}

void		TacticalMarine::meleeAttack() const
{
	std::cout	<< "* attacks with a chainsword *"
				<< std::endl;
}