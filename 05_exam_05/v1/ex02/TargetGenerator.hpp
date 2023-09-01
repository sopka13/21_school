/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:30:33 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 15:43:11 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ATarget.hpp"
#include <vector>

class TargetGenerator
{
	std::vector<ATarget *>	m_container;

	TargetGenerator(const TargetGenerator &other);
	const TargetGenerator	&operator= (const TargetGenerator &spellbook);
public:
	TargetGenerator();
	~TargetGenerator();

	void		learnTargetType(ATarget*);
	void		forgetTargetType(std::string const &);
	ATarget*	createTarget(std::string const &);
};