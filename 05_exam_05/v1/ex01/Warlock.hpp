/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:10:58 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/10 12:36:33 by eyohn            ###   ########.fr       */
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
	Warlock& operator= (const Warlock &warlock);
public:
	Warlock(const std::string & name, const std::string & title);
	~Warlock();
	
	const std::string&	getName() const;
	const std::string&	getTitle() const;
	void				setTitle(const std::string &new_title);
	void				intriduce() const;

	void				learnSpell(const ASpell* new_aspell);
	void				forgetSpell(const std::string &spell_name);
	void				lauchSpell(const std::string &spell_name, const ATarget& target);
};