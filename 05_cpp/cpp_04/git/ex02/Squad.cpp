/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:29:58 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 14:56:45 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad():
	m_count(0),
	m_squad(NULL)
{
}

Squad::Squad(const Squad &other):
	m_count(other.m_count)
{
	delete_squad();
	if (!other.m_squad || !other.m_count)
		return ;
	m_squad = new ISpaceMarine*[other.m_count];
	for (unsigned int i = 0; i < other.m_count; ++i)
	{
		m_squad[i] = other.m_squad[i]->clone();
	}
}

Squad::~Squad()
{
	delete_squad();
}

Squad&	Squad::operator= (const Squad &squad)
{
	if (this == &squad)
		return (*this);

	delete_squad();
	if (!squad.m_squad || !squad.m_count)
		return (*this);
	m_squad = new ISpaceMarine*[squad.m_count];
	for (unsigned int i = 0; i < squad.m_count; ++i)
	{
		m_squad[i] = squad.m_squad[i]->clone();
	}
	return (*this);
}

int		Squad::getCount() const
{
	return (m_count);
}

ISpaceMarine*	Squad::getUnit(int i) const
{
	if (i < 0)
		return (NULL);
	if ((unsigned int)i >= m_count)
		return (NULL);
	return (m_squad[i]);
}

int		Squad::push(ISpaceMarine *novobranec)
{
	ISpaceMarine **temp;

	if (!novobranec)
		return (m_count);
	for (unsigned int i = 0; i < m_count; ++i)
	{
		if (m_squad[i] == novobranec)
			return (m_count);
	}
	temp = new ISpaceMarine*[m_count + 1];
	for (unsigned int i = 0; i < m_count; ++i)
	{
		temp[i] = m_squad[i];
	}
	temp[m_count] = novobranec;
	delete[] m_squad;
	m_squad = temp;
	m_count += 1;
	return (m_count);
}

void	Squad::delete_squad()
{
	if (!m_squad)
		return ;
	for (unsigned int i = 0; i < m_count; ++i)
	{
		delete m_squad[i];
	}
	delete[] m_squad;
	m_squad = NULL;
	return ;
}