/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:15:50 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 12:10:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	ASpell();
	ASpell(const ASpell &other);
	const ASpell&	operator= (const ASpell &aspel);
protected:
	std::string		m_name;
	std::string		m_effects;
public:
	ASpell(std::string name, std::string effects);
	virtual ~ASpell();

	std::string		getName() const;
	std::string		getEffects() const;
	virtual ASpell*	clone() const = 0;
	void			launch(const ATarget &target);
};