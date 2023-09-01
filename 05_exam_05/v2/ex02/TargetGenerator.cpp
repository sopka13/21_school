/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:45:43 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 15:50:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void			TargetGenerator::learnTargetType(ATarget* new_target)
{
	std::vector<ATarget *>::iterator	start = m_container.begin();
	std::vector<ATarget *>::iterator	end = m_container.end();
	while (start != end)
	{
		if ((*start)->getType() == new_target->getType())
			return ;
		start++;
	}
	m_container.push_back(new_target);
	return ;
}

void			TargetGenerator::forgetTargetType(std::string const & target_name)
{
	std::vector<ATarget *>::iterator	start = m_container.begin();
	std::vector<ATarget *>::iterator	end = m_container.end();
	while (start != end)
	{
		if ((*start)->getType() == target_name)
		{
			m_container.erase(start);
			return ;
		}
		start++;
	}
	return ;
}

ATarget*		TargetGenerator::createTarget(std::string const & target_name)
{
	std::vector<ATarget *>::iterator	start = m_container.begin();
	std::vector<ATarget *>::iterator	end = m_container.end();
	while (start != end)
	{
		if ((*start)->getType() == target_name)
			return (*start);
		start++;
	}
	return (NULL);
}