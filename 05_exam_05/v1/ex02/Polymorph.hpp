/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:49:11 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 14:56:09 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	// Polymorph(std::string name, std::string effects);
	// Polymorph(const Polymorph &other);
	const Polymorph&	operator= (const Polymorph &fwoosh);
public:
	Polymorph();
	virtual ~Polymorph();

	virtual	Polymorph*	clone() const;
};