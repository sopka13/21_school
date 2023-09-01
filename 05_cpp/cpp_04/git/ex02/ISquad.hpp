/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:29:47 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:45 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ISQUAD_HPP_
#define _ISQUAD_HPP_

#include "ISpaceMarine.hpp"

class ISquad
{
public:
	virtual	~ISquad() {};
	virtual int				getCount() const = 0;		//return number of unit in the squad
	virtual ISpaceMarine*	getUnit(int) const = 0;		//return pointer to the Nth unit
	virtual int				push(ISpaceMarine*) = 0;	//adds the XXX unit to the end of squad
};

#endif