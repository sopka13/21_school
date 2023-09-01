/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:28:10 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 15:34:43 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{}

void			SpellBook::learnSpell(ASpell* new_spell)
{
	std::vector<ASpell *>::iterator	start = m_spels.begin();
	std::vector<ASpell *>::iterator	end = m_spels.end();
	while (start != end)
	{
		if ((*start)->getName() == new_spell->getName())
			return ;
		start++;
	}
	m_spels.push_back(new_spell->clone());
	return ;
}

void			SpellBook::forgetSpell(std::string const & name_spell)
{
	std::vector<ASpell *>::iterator	start = m_spels.begin();
	std::vector<ASpell *>::iterator	end = m_spels.end();
	while (start != end)
	{
		if ((*start)->getName() == name_spell)
		{
			m_spels.erase(start);
			return ;
		}
		start++;
	}
	return ;
}

ASpell*			SpellBook::createSpell(std::string const & name_spell)
{
	std::vector<ASpell *>::iterator	start = m_spels.begin();
	std::vector<ASpell *>::iterator	end = m_spels.end();
	while (start != end)
	{
		if ((*start)->getName() == name_spell)
			return (*start);
		start++;
	}
	return (NULL);
}