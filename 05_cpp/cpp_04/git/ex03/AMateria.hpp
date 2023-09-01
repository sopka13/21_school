/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:34:36 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 20:17:34 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _AMATERIA_HPP_
#define _AMATERIA_HPP_

#include <iostream>
class AMateria;
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string		_type;
	unsigned int	_xp;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	virtual ~AMateria();

	AMateria			&operator= (const AMateria &amateria);
	std::string const	& getType() const;		//Returns the materia type
	unsigned int		getXP() const;			//Returns the Materia's XP

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif