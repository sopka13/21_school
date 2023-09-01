/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:52:50 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 14:55:58 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	// Fwoosh(std::string name, std::string effects);
	// Fwoosh(const Fwoosh &other);
	const Fwoosh&	operator= (const Fwoosh &fwoosh);
public:
	Fwoosh();
	virtual ~Fwoosh();

	virtual	Fwoosh*	clone() const;
};