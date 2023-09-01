/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:41:22 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 15:50:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ATarget.hpp"
#include <iostream>
#include <vector>

class TargetGenerator
{
	std::vector<ATarget *>		m_container;

	TargetGenerator(const TargetGenerator &other);
	TargetGenerator&	operator= (const TargetGenerator &targetgenerator);
public:
	TargetGenerator();
	~TargetGenerator();

	void			learnTargetType(ATarget*);
	void			forgetTargetType(std::string const &);
	ATarget*		createTarget(std::string const &);
};