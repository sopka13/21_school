/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:00:08 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 14:43:22 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	std::string		m_type;
public:
	ATarget();
	ATarget(const std::string &type);
	ATarget(const ATarget &other);
	virtual ~ATarget();

	ATarget&			operator= (const ATarget &atarget);
	const std::string	getType() const;
	virtual ATarget*	clone() const = 0;
	void				getHitBySpell(const ASpell& spell) const;
};
