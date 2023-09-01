/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:10:23 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/11 13:37:01 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	std::string				m_name;
	std::string				m_title;
	std::vector<ASpell *>	m_spels;

	Warlock();
	Warlock(const Warlock &other);
	Warlock&	operator= (const Warlock &warlock);
public:
	Warlock(const std::string &name, const std::string &title);
	~Warlock();

	const std::string	&getName() const;
	const std::string	&getTitle() const;
	void				setTitle(const std::string &new_title);
	void				introduce() const;
	void				learnSpell(const ASpell *new_spell);
	void				forgetSpell(const std::string &name_spell);
	void				launchSpell(const std::string &name_spell, const ATarget &target);
};