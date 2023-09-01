/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:29:53 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:46 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ASSAULTTERMINATOR_HPP_
#define _ASSAULTTERMINATOR_HPP_

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(const AssaultTerminator &other);
	~AssaultTerminator();

	AssaultTerminator &operator= (const AssaultTerminator &assaultterminator);
	AssaultTerminator*		clone () const;
	void					battleCry() const;
	void					rangedAttack() const;
	void					meleeAttack() const;
};

#endif