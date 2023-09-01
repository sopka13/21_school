/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:51:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 15:00:23 by eyohn            ###   ########.fr       */
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
	ASpell&				operator= (const ASpell &aspell);
protected:
	std::string		m_name;
	std::string		m_effects;
public:
	ASpell(const std::string &name, const std::string &effects);
	virtual ~ASpell();

	const std::string	&getName() const;
	const std::string	&getEffects() const;
	virtual ASpell*		clone() const = 0;
	void				launch(const ATarget& target);
};
