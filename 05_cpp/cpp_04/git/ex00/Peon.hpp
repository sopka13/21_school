/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:23:15 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:51 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _PEON_HPP_
#define _PEON_HPP_

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string name);
	~Peon();
	Peon(const Peon &other);

	void		getPolymorphed() const;
};


#endif