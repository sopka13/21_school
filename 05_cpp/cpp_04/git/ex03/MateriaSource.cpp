/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:00:00 by eyohn             #+#    #+#             */
/*   Updated: 2021/07/08 20:18:48 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	bzero_materia_source();
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	free_materia_source();
	bzero_materia_source();
	for (int i = 0; i < MAX_OBJ; ++i)
	{
		if (other.m_objects[i])
			m_objects[i] = other.m_objects[i]->clone();
	}
	return ;
}

MateriaSource::~MateriaSource()
{
	free_materia_source();
}

MateriaSource&	MateriaSource::operator= (const MateriaSource &materiasource)
{
	if (this == &materiasource)
		return (*this);
	free_materia_source();
	bzero_materia_source();
	for (int i = 0; i < MAX_OBJ; ++i)
	{
		if (materiasource.m_objects[i])
			m_objects[i] = materiasource.m_objects[i]->clone();
	}
	return (*this);
}

void	MateriaSource::LearnMateria(AMateria *new_materia)
{
	for (int i = 0; i < MAX_OBJ; ++i)
	{
		if (!m_objects[i])
		{
			m_objects[i] = new_materia;
			break ;
		}
	}
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_OBJ; ++i)
	{
		if (m_objects[i]->getType() == type)
			return (m_objects[i]->clone());
	}
	return (0);
}

void	MateriaSource::free_materia_source()
{
	for (int i = 0; i < MAX_OBJ; ++i)
	{
		if (m_objects[i])
		{
			delete m_objects[i];
			m_objects[i] = NULL;
		}
	}
	return ;
}

void	MateriaSource::bzero_materia_source()
{
	for (int i = 0; i < MAX_OBJ; ++i)
	{
		m_objects[i] = NULL;
	}
	return ;
}