/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:03:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/03 01:49:23 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	add(const int &i)
{
	std::cout << "func value = " << i << std::endl;
	return ;
}

int		main(void)
{
	int		leigth = 3;
	int		*arr = new int[leigth];

	for (int i = 0; i < leigth; ++i)
	{
		arr[i] = leigth - 1;
	}

	for (int i = 0; i < leigth; ++i)
	{
		std::cout << arr[i] << ' ' << std::endl;
	}

	iter(arr, leigth, add);

	for (int i = 0; i < leigth; ++i)
	{
		std::cout << arr[i] << ' ' << std::endl;
	}

	delete[] arr;
	
	return (0);
}

// class Awesome
// {
// public:
// 	Awesome( void ) : _n( 42 ) { return; }
// 	int get( void ) const { return this->_n; }
// private:
// 	int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template <typename T>
// void	print( T const & x )
// {
// 	std::cout << x << std::endl;
// 	return;
// };

// int main()
// {
// 	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// 	Awesome tab2[5];
// 	iter( tab, 5, print );
// 	iter( tab2, 5, print );
// 	return 0;
// }