/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:01:15 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 16:07:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(const SpellBook &other)
{
	*this = other;
}

const SpellBook&	SpellBook::operator= (const SpellBook &spellbook)
{
	if (this != &spellbook)
		return (*this);
	return (*this);
}

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	std::cout << "dtor SpellBook" << std::endl;
}

void			SpellBook::learnSpell(ASpell* new_spell)
{
	std::vector<ASpell *>::iterator start = m_book.begin();
	std::vector<ASpell *>::iterator end = m_book.end();
	while (start != end)
	{
		if ((*start)->getName() == new_spell->getName())
			return ;
		start++;
	}
	m_book.push_back(new_spell->clone());
	return ;
}

void			SpellBook::forgetSpell(std::string const & name_spell)
{
	std::vector<ASpell *>::iterator start = m_book.begin();
	std::vector<ASpell *>::iterator end = m_book.end();
	while (start != end)
	{
		if ((*start)->getName() == name_spell)
		{
			m_book.erase(start);
			return ;
		}
		start++;
	}
	return ;
}

ASpell*			SpellBook::createSpell(std::string const & name_spell)
{
	std::vector<ASpell *>::iterator start = m_book.begin();
	std::vector<ASpell *>::iterator end = m_book.end();
	while (start != end)
	{
		if ((*start)->getName() == name_spell)
			return (*start);
		start++;
	}
	return (NULL);
}