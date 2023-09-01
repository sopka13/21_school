/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:56:23 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 15:18:56 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"
#include <vector>

class SpellBook
{
	std::vector<ASpell *>	m_book;

	SpellBook(const SpellBook &other);
	const SpellBook	&operator= (const SpellBook &spellbook);
public:
	SpellBook();
	~SpellBook();

	void			learnSpell(ASpell*);
	void			forgetSpell(std::string const &);
	ASpell*			createSpell(std::string const &);
};