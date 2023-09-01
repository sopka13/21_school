/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:28:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/01 16:16:58 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

static std::string toString(int a)
{
	std::ostringstream oss;
	oss << a;
	return (oss.str());
}

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];\
	for (int i(0); i < N; ++i)
	{
		horde[i].m_name = name + ' ' + toString(i);
		horde[i].anounce();
	}
	return (horde);
}