/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:03:06 by eyohn             #+#    #+#             */
/*   Updated: 2021/08/03 01:12:31 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

class
Awesome {
public:
Awesome( int n ) : _n( n ) {}
bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
private:
int _n;
};

int		main(void)
{
	// // MIN / MAX
	// int		f = 1;
	// int		g = 100;
	// std::cout	<< "a = " 
	// 			<< f
	// 			<< " b = "
	// 			<< g
	// 			<< " min(a, b) = "
	// 			<< ::min(f, g)
	// 			<< " max(a, b) = "
	// 			<< ::max(f, g)
	// 			<< std::endl;

	// // SWAP
	// int		*q = new(int)(1);
	// int		*w = new(int)(3333);
	// std::cout	<< "a = " 
	// 			<< *q
	// 			<< " b = "
	// 			<< *w
	// 			<< " swap(a, b); ";
	// ::swap(q, w);
	// std::cout	<< "a = " 
	// 			<< *q
	// 			<< " b = "
	// 			<< *w
	// 			<< std::endl;
	// delete q;
	// delete w;

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	Awesome f(3);
	Awesome g(5);
	std::cout << (f < g) << std::endl;
	::swap(&f, &g);
	std::cout << (f < g) << std::endl;

	return (0);
}