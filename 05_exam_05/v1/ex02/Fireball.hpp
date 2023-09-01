/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:45:58 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 14:55:47 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell
{
	// Fireball(std::string name, std::string effects);
	// Fireball(const Fireball &other);
	const Fireball&	operator= (const Fireball &fwoosh);
public:
	Fireball();
	virtual ~Fireball();

	virtual	Fireball*	clone() const;
};