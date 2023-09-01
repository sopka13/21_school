/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:25:08 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:50 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SORCERER_HPP_
#define _SORCERER_HPP_

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
	std::string		m_name;
	std::string		m_title;
	Sorcerer();
public:
	Sorcerer(std::string name, std::string title);
	virtual ~Sorcerer();
	Sorcerer(const Sorcerer &other);

	Sorcerer		&operator= (const Sorcerer &sorcerer);
	std::string		introduce() const;
	void			polymorph(Victim const &) const;
};

std::ostream	&operator<< (std::ostream &out, const Sorcerer &fix);

#endif