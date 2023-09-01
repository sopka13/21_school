/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:13:23 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 12:36:32 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock()
{}

Warlock::Warlock(const Warlock &other)
{
	*this = other;
}

Warlock& Warlock::operator= (const Warlock &warlock)
{
	if (this != &warlock)
	{
		m_title = warlock.m_title;
		m_name = warlock.m_name;
	}
	return (*this);
}

Warlock::Warlock(const std::string & name, const std::string & title):
	m_name(name),
	m_title(title)
{
	std::cout	<< this->getName()
				<< ": This looks like another boring day."
				<< std::endl;
}

Warlock::~Warlock()
{
	if (!m_spels.empty())
		m_spels.clear();
	std::cout	<< this->getName()
				<< ": My job here is done!"
				<< std::endl;
}

const std::string&	Warlock::getName() const
{
	return (m_name);
}

const std::string&	Warlock::getTitle() const
{
	return (m_title);
}

void				Warlock::setTitle(const std::string &new_title)
{
	m_title = new_title;
	return ;
}

void				Warlock::intriduce() const
{
	std::cout	<< this->getName()
				<< ": I am "
				<< this->getName()
				<< ", "
				<< this->getTitle()
				<< "!"
				<< std::endl;
}

void				Warlock::learnSpell(const ASpell* new_aspell)
{
	std::vector<ASpell *>::iterator	start = m_spels.begin();
	std::vector<ASpell *>::iterator	end = m_spels.end();
	while (start != end)
	{
		if ((*start)->getName() == new_aspell->getName())
			return ;
		start++;
	}
	m_spels.push_back(new_aspell->clone());
	return ;
}

void				Warlock::forgetSpell(const std::string &spell_name)
{
	std::vector<ASpell *>::iterator	start = m_spels.begin();
	std::vector<ASpell *>::iterator	end = m_spels.end();
	while (start != end)
	{
		if ((*start)->getName() == spell_name)
		{
			m_spels.erase(start);
			return ;
		}
		start++;
	}
	return ;
}

void				Warlock::lauchSpell(const std::string &spell_name, const ATarget& target)
{
	std::vector<ASpell *>::iterator	start = m_spels.begin();
	std::vector<ASpell *>::iterator	end = m_spels.end();
	while (start != end)
	{
		if ((*start)->getName() == spell_name)
		{
			(*start)->launch(target);
			return ;
		}
		start++;
	}
	return ;
}
