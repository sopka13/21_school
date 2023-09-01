/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:35:30 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 16:07:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(const TargetGenerator &other)
{
	*this = other;
}

const TargetGenerator&  TargetGenerator::operator= (const TargetGenerator &targetgenerator)
{
	if (this != &targetgenerator)
		return (*this);
	return (*this);
}

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
	std::cout << "dtor TargetGenerator" << std::endl;
	if (!m_container.empty())
		m_container.clear();
	return ;
}

void		TargetGenerator::learnTargetType(ATarget* new_target)
{
	std::vector<ATarget *>::iterator	start = m_container.begin();
	std::vector<ATarget *>::iterator	end = m_container.end();
	while (start != end)
	{
		if ((*start)->getType() == new_target->getType())
			return ;
		start++;
	}
	m_container.push_back(new_target->clone());
	return ;
}

void		TargetGenerator::forgetTargetType(std::string const & name_target)
{
	std::vector<ATarget *>::iterator	start = m_container.begin();
	std::vector<ATarget *>::iterator	end = m_container.end();
	while (start != end)
	{
		if ((*start)->getType() == name_target)
		{
			m_container.erase(start);
			return ;
		}
		start++;
	}
	return ;
}

ATarget*	TargetGenerator::createTarget(std::string const & name_target)
{
	std::vector<ATarget *>::iterator	start = m_container.begin();
	std::vector<ATarget *>::iterator	end = m_container.end();
	while (start != end)
	{
		if ((*start)->getType() == name_target)
			return (*start);
		start++;
	}
	return (NULL);
}