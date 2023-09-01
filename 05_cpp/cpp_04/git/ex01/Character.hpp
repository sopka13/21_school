/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:05:48 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 22:00:49 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
private:
	std::string		m_name;
	unsigned int	m_AP;
	AWeapon			*m_weapon;
	Character();

public:
	Character(std::string const & name);
	Character(const Character &other);
	~Character();

	Character	&operator= (const Character &character);
	void		recoverAP();
	void		equip(AWeapon*);
	void		attack(Enemy*);
	std::string const	getName() const;
	int					getAP() const;
	std::string const	*getWeaponName() const;
};

std::ostream &operator<< (std::ostream &out, const Character &fix);

#endif