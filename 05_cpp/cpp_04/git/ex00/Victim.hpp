/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:24:05 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:49 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _VICTIM_HPP_
#define _VICTIM_HPP_

#include <iostream>

class Victim
{
protected:
	std::string		m_name;
public:
	Victim(std::string	name);
	~Victim();
	Victim(const Victim &other);

	Victim			&operator = (const Victim &victim);
	std::string		introduce() const;
	virtual void	getPolymorphed() const;
};

std::ostream &operator<< (std::ostream &out, const Victim &fix);

#endif