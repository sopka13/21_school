/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:02:30 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/07 13:24:05 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _AWEAPON_HPP_
#define _AWEAPON_HPP_

#include <iostream>
#include <string>

class AWeapon
{
protected:
	std::string		m_name;
	unsigned int	m_apcost;
	unsigned int	m_damage;

public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(const AWeapon &other);
	virtual ~AWeapon();

	std::string const	*getName() const;
	int					getAPCost() const;
	int					getDamage() const;
	virtual void		attack() const = 0;
	AWeapon				&operator= (const AWeapon &aweapon);
};

std::ostream &operator<< (std::ostream &out, const AWeapon &fix);

#endif