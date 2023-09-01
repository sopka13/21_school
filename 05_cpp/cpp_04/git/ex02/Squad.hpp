/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:29:59 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:45 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _SQUAD_HPP_
#define _SQUAD_HPP_

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
	unsigned int	m_count;
	ISpaceMarine	**m_squad;
	void			delete_squad();
public:
	Squad();
	Squad(const Squad &other);
	~Squad();

	Squad			&operator= (const Squad &squad);
	int				getCount() const;		//return number of unit in the squad
	ISpaceMarine*	getUnit(int) const;		//return pointer to the Nth unit
	int				push(ISpaceMarine*);	//adds the XXX unit to the end of squad
};

#endif