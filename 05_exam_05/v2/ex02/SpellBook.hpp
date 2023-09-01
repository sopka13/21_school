/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:24:27 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 15:34:46 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ASpell.hpp"
#include <vector>

class SpellBook
{
	std::vector<ASpell *>	m_spels;

	SpellBook(const SpellBook &other);
	SpellBook&	operator= (const SpellBook $spellbook);
public:
	SpellBook();
	~SpellBook();

	void			learnSpell(ASpell*);
	void			forgetSpell(std::string const &);
	ASpell*			createSpell(std::string const &);
};