/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:27:15 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 12:10:49 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	std::string		m_type;
	ATarget();
	ATarget(const ATarget &other);
	const ATarget&	operator= (const ATarget &atarget);
public:
	ATarget(std::string type);
	virtual ~ATarget();

	const std::string&	getType() const;
	virtual ATarget*	clone() const = 0;
	void				getHitBySpell(const ASpell &aspel) const;
};