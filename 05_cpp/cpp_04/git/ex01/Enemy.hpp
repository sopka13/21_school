/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 09:23:00 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 21:31:26 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _ENEMY_HPP_
#define _ENEMY_HPP_

#include <iostream>

class Enemy
{
protected:
	std::string		m_type;
	unsigned int	m_hp;

public:
	Enemy(int hp, std::string const &type);
	virtual ~Enemy();
	Enemy(const Enemy &other);

	Enemy				&operator= (const Enemy &enemy);
	std::string const	getType() const;
	int					getHP() const;
	virtual void		takeDamage(unsigned int);
};

std::ostream &operator<< (std::ostream &out, const Enemy &fix);

#endif