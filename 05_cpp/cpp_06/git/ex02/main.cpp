/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 09:34:00 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/02 11:34:21 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.hpp"

Base	*generate(void)
{
	srand(time(NULL));

	std::cout << (rand() % 3 + 1) << std::endl;

	switch ((rand() % 3 + 1))
	{
	case 1:
	{
		std::cout << "Create A class" << std::endl;
		return (new(A));
	}
	case 2:
	{
		std::cout << "Create B class" << std::endl;
		return (new(B));
	}
	case 3:
	{
		std::cout << "Create C class" << std::endl;
		return (new(C));
	}
	default:
		return (NULL);
	}
}

void	identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "Is A class" << std::endl;
		return;
	}

	B *b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "Is B class" << std::endl;
		return;
	}

	C *c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "Is C class" << std::endl;
		return;
	}
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Is A class " << &a << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			std::cout << "Is B class " << &b << std::endl;
			return;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				std::cout << "Is C class " << &c << std::endl;
				return;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	return;
}

int		main(void)
{
	Base	*obj = generate();

	identify(obj);
	identify(*obj);

	delete obj;

	return (0);
}