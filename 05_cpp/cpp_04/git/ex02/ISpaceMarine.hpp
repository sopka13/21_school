/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:29:50 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 14:46:24 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ISPACEMARINE_HPP_
#define _ISPACEMARINE_HPP_

#include <iostream>

class ISpaceMarine
{
public:
	virtual ~ISpaceMarine() {};
	virtual ISpaceMarine*	clone () const = 0;			//return a copy of the current object
	virtual void			battleCry() const = 0;
	virtual void			rangedAttack() const = 0;
	virtual void			meleeAttack() const = 0;
};

#endif