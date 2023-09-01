/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:48:39 by eyohn             #+#    #+#             */
/*   Updated: 2022/01/16 23:51:55 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Implement the following containers and turn in the necessary files
**	<container>.hpp
**	• You must also provide a main.cpp which tests everything for your evaluations.
**	(you need to go further than the example!)
**	• You must produce one binary with only your containers and one with the same
**	testing with STL containers.
**	• Compare outputs and timing (you can be up to 20 times slower).
**	• member functions, Non-member and overloads are expected.
**	• respect the naming, take care to details.
**	• You must use std::allocator.
**	• You must justify your inner data structure for each container (using a simple
**	array for a map is not ok).
**	• If the container has an iterator system, you must implement it.
**	• iterators_traits, reverse_iterator, enable_if, is_integral,
**	equal/lexicographical compare, std::ft::pair, std::make_ft::pair, must be reimplemented.
**	• You can use https://www.cplusplus.com/ and https://cppreference.com/ as
**	references.
**	• You cannot implement more public functions than the ones offered in the standard
**	containers. Everything else must be private or protected. Each public function/-
**	variable must be justified.
**	• For non-member overloads, the keyword friend is allowed. Each use of friend must
**	be justified and will be checked during evaluation.
**	You must turn in the following containers and their associated functions:
**	• Vector
**	• Map
**	• Stack
**	Your stack will use your vector class as default underlaying container, it must
**	still be compatible with others containers like the STL one.
**	STL containers are forbidden.
**	You are allowed to use the STD library.
*/

#include <iostream>
#include <string>
#include <deque>
#include <list>

// #if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
// 	namespace ft = std;
// #else
// 	#include "map.hpp"
// 	#include "stack.hpp"
// 	#include "vector.hpp"
// #endif

#include "map.hpp"
#include "source.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include <stdio.h>

int		main(void) {

	std::cout << "\n ### ### ### ### ### ### ### ### ### ### ### ### ### ###" << std::endl;
	std::cout <<   " ### ### ### ### ###  MAP test start ### ### ### ### ###" << std::endl;
	std::cout <<   " ### ### ### ### ### ### ### ### ### ### ### ### ### ###" << std::endl;
	//------Constructors------
	{
		std::cout << "\n ### ### ### ### ### Constructors test start ### ### ### ### ### " << std::endl;

		ft::map<int, int> map_01;									// first

		// fff<int, int> p = map_01;

		std::cout << "Size 1 = " << map_01.size() << std::endl;
		map_01.insert(ft::make_pair(4, 12));
		std::cout << "Size 1 = " << map_01.size() << std::endl;

		ft::map<int, int> map_02(map_01);							// second
		
		std::cout << "Size 1 = " << map_01.size() << std::endl;
		std::cout << "Size 2 = " << map_02.size() << std::endl;
		map_02.insert(ft::make_pair(0, 33));
		std::cout << "first = " << (*(map_01.begin())).first << " second = " << (*(map_01.begin())).second << std::endl;
		std::cout << "first = " << (*(map_02.begin())).first << " second = " << (*(map_02.begin())).second << std::endl;
		ft::pair<int, int> p_1(1, 12);
		ft::pair<int, int> p_2(2, 12);
		ft::pair<int, int> p_3(3, 12);
		ft::pair<int, int> p_4(4, 12);
		ft::pair<int, int> p_5(5, 12);
		map_02.insert(p_1);
		map_02.insert(p_2);
		map_02.insert(p_3);
		map_02.insert(p_4);
		map_02.insert(p_5);
		ft::map<int, int>::iterator begin = map_02.begin();
		ft::map<int, int>::iterator end = map_02.end();
		while (begin != end){
			std::cout << begin->first << " => " << begin->second << std::endl;
			begin++;
		}
		begin = map_02.begin();
		begin++;

		ft::map<int, int>	map_03(begin, end);						// third

		ft::map<int, int>::iterator begin_2 = map_03.begin();
		ft::map<int, int>::iterator end_2 = map_03.end();
		while (begin_2 != end_2){
			std::cout << begin_2->first << " => " << begin_2->second << std::endl;
			begin_2++;
		}

		ft::map<int, int>	map_04;
		std::cout << "Size 4 = " << map_04.size() << std::endl;
		map_04 = map_03;											// last
		std::cout << "Size 4 = " << map_04.size() << std::endl;
	}
	//------Destructor--------
	{
		std::cout << "\n ### ### ### ### ### Destructor test start ### ### ### ### ### " << std::endl;

		ft::map<int, int> map_01;
		ft::pair<const int, int> p1(1, 11);
		ft::pair<const int, int> p2(2, 12);
		ft::pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);
	}
	//------Element access----
	{
		std::cout << "\n ### ### ### ### ### Element access test start ### ### ### ### ###" << std::endl;
		
		ft::map<int, int> map_02;

		ft::pair<int, int> p_1(1, 11);
		ft::pair<int, int> p_2(2, 12);
		ft::pair<int, int> p_3(3, 13);
		ft::pair<int, int> p_4(4, 14);
		ft::pair<int, int> p_5(5, 15);
		map_02.insert(p_1);
		map_02.insert(p_2);
		map_02.insert(p_3);
		map_02.insert(p_4);
		map_02.insert(p_5);

		int kk = map_02.at(3);						// first
		std::cout << "Value = " << kk << std::endl;

		const int oo = map_02.at(1);				// second
		std::cout << "Value = " << oo << std::endl;

		ft::map<int, int> map_03(map_02);

		ft::map<char,std::string> mymap;

		mymap['a']="an element";					// third
		mymap['b']="another element";
		mymap['c']=mymap['b'];

		std::cout << "mymap['a'] is " << mymap['a'] << '\n';
		std::cout << "mymap['b'] is " << mymap['b'] << '\n';
		std::cout << "mymap['c'] is " << mymap['c'] << '\n';
		std::cout << "mymap['d'] is " << mymap['d'] << '\n';	// third++

		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	}
	//------Modifiers---------
	{
		std::cout << "\n ### ### ### ### ### Modifiers test start ### ### ### ### ###" << std::endl;

		ft::map<int, int> map_01;
		ft::pair<const int, int> p1(1, 11);
		ft::pair<const int, int> p2(2, 12);
		ft::pair<const int, int> p3(3, 13);
		map_01.insert(p1);											// first
		map_01.insert(p2);
		map_01.insert(p3);
		map_01.insert(ft::make_pair(5, 15));
		map_01.insert(ft::make_pair(6, 16));
		map_01.insert(ft::make_pair(0, 10));
		
		std::cout << "Container size  = " << map_01.size() << std::endl;

		ft::map<int, int>::iterator		begin = map_01.begin();
		ft::map<int, int>::iterator		end = map_01.end();
		while (begin != end){
			std::cout << begin->first << " -> " << begin->second << std::endl;
			begin++;
		}

		ft::map<int, int>::iterator		hint = map_01.find(3);
		map_01.insert(hint, ft::make_pair(4, 14));					// second

		std::cout << "Container size after second  = " << map_01.size() << std::endl;

		begin = map_01.begin();
		end = map_01.end();
		while (begin != end){
			std::cout << begin->first << " -> " << begin->second << std::endl;
			begin++;
		}

		hint++;
		std::cout << "Elem after hint  = " << hint->first << " ->" << hint->second << std::endl;

		ft::map<int, int>	map_02;
		map_02.insert(hint, map_01.end());							// third
		std::cout << "Container size after insert with two iterators = " << map_02.size() << std::endl;

		ft::map<int, int>::iterator		begin_2 = map_02.begin();
		ft::map<int, int>::iterator		end_2 = map_02.end();
		while (begin_2 != end_2){
			std::cout << begin_2->first << " -> " << begin_2->second << std::endl;
			begin_2++;
		}

		map_02.erase(map_02.begin());								// fourth
		std::cout << "Container size after erase first elem = " << map_02.size() << std::endl;

		begin_2 = map_02.begin();
		end_2 = map_02.end();
		while (begin_2 != end_2){
			std::cout << begin_2->first << " -> " << begin_2->second << std::endl;
			begin_2++;
		}

		ft::map<int, int>::iterator		begin_03 = map_01.find(4);
		map_01.erase(begin_03, map_01.end());							// fifth
		std::cout << "Container size after erase with two iterators = " << map_01.size() << std::endl;

		begin = map_01.begin();
		end = map_01.end();
		while (begin != end){
			std::cout << begin->first << " -> " << begin->second << std::endl;
			begin++;
		}

		map_01.erase(0);												// sixth
		std::cout << "Container size after erase with key = " << map_01.size() << std::endl;
		begin = map_01.begin();
		end = map_01.end();
		while (begin != end){
			std::cout << begin->first << " -> " << begin->second << std::endl;
			begin++;
		}

		map_01.swap(map_02);											// seventh
		std::cout	<< "Container size after swap map_01 = " << map_01.size()
					<< " and map_02 = " << map_02.size() << " elements:" << std::endl;
		
		begin = map_01.begin();
		end = map_01.end();
		while (begin != end){
			std::cout << begin->first << " -> " << begin->second << std::endl;
			begin++;
		}

		std::cout << "And elements in map_02:" << std::endl;

		begin_2 = map_02.begin();
		end_2 = map_02.end();
		while (begin_2 != end_2){
			std::cout << begin_2->first << " -> " << begin_2->second << std::endl;
			begin_2++;
		}

		map_01.clear();													// eighth
		map_02.clear();
		std::cout << "Size contaners after clear: map_01 = " << map_01.size()
					<< "; map_02 = " << map_02.size() << std::endl;
	}
	//------Iterators---------
	{
		std::cout << "\n ### ### ### ### ### Iterators test start ### ### ### ### ###" << std::endl;

		ft::map<int, int> map_01;
		ft::pair<const int, int> p1(1, 11);
		ft::pair<const int, int> p2(9, 12);
		ft::pair<const int, int> p3(-3, 13);
		ft::pair<const int, int> p4(0, 14);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);
		map_01.insert(p4);

		// for (int i = 0; i < 100; ++i){
		// 	ft::pair<const int, int> p(rand(), i);
		// 	map_01.insert(p);
		// }
		// printf("Current size: %lu\n", map_01.size());

		std::cout << "Use iterator:" << std::endl;
		ft::map<int, int>::iterator					it_01 = map_01.begin();
		ft::map<int, int>::iterator					it_02 = map_01.end();
		// it_01->first = 933;
		// it_01->second = 933;
		while (it_01 != it_02){
			std::cout << it_01->first << " => " << it_01->second << std::endl;
			it_01++;
		}

		std::cout << "Use const_iterator:" << std::endl;
		ft::map<int, int>::const_iterator			it_03 = map_01.begin();
		ft::map<int, int>::const_iterator			it_04 = map_01.end();
		// it_03->first = 933;
		// it_03->second = 933;
		while (it_03 != it_04){
			std::cout << it_03->first << " => " << it_03->second << std::endl;
			it_03++;
		}

		std::cout << "Use reverse_iterator:" << std::endl;
		ft::map<int, int>::reverse_iterator			it_05 = map_01.rbegin();
		ft::map<int, int>::reverse_iterator			it_06 = map_01.rend();
		// it_05->first = 933;
		// it_05->second = 933;
		while (it_05 != it_06){
			std::cout << it_05->first << " => " << it_05->second << std::endl;
			it_05++;
		}

		std::cout << "Use const_reverse_iterator:" << std::endl;
		ft::map<int, int>::const_reverse_iterator	it_07 = map_01.rbegin();
		ft::map<int, int>::const_reverse_iterator	it_08 = map_01.rend();
		// it_07->first = 933;
		// it_07->second = 933;
		while (it_07 != it_08){
			std::cout << it_07->first << " => " << it_07->second << std::endl;
			it_07++;
		}

		std::cout << "Check compare '==' :" << std::endl;
		std::cout << (int)(it_01 == it_02) << std::endl;
		std::cout << (int)(it_03 == it_04) << std::endl;
		std::cout << (int)(it_05 == it_06) << std::endl;
		std::cout << (int)(it_07 == it_08) << std::endl;

		std::cout << "Check compare '>=' :" << std::endl;
		std::cout << (int)(it_01 >= it_02) << std::endl;
		std::cout << (int)(it_03 >= it_04) << std::endl;
		std::cout << (int)(it_05 >= it_06) << std::endl;
		std::cout << (int)(it_07 >= it_08) << std::endl;

		std::cout << "Check compare '>' :" << std::endl;
		std::cout << (int)(it_01 > it_02) << std::endl;
		std::cout << (int)(it_03 > it_04) << std::endl;
		std::cout << (int)(it_05 > it_06) << std::endl;
		std::cout << (int)(it_07 > it_08) << std::endl;

		std::cout << "Check compare '<=' :" << std::endl;
		std::cout << (int)(it_01 <= it_02) << std::endl;
		std::cout << (int)(it_03 <= it_04) << std::endl;
		std::cout << (int)(it_05 <= it_06) << std::endl;
		std::cout << (int)(it_07 <= it_08) << std::endl;

		std::cout << "Check compare '<' :" << std::endl;
		std::cout << (int)(it_01 < it_02) << std::endl;
		std::cout << (int)(it_03 < it_04) << std::endl;
		std::cout << (int)(it_05 < it_06) << std::endl;
		std::cout << (int)(it_07 < it_08) << std::endl;

		std::cout << "Compare iterator and const_iterator :" << std::endl;
		std::cout << (int)(it_01 == it_03) << std::endl;
		std::cout << (int)(it_07 == it_06) << std::endl;

		// std::cout << (int)(it_01 == it_03) << std::endl;
		// std::cout << (int)(it_01 == it_05) << std::endl;
		// std::cout << (int)(it_01 == it_07) << std::endl;
		// std::cout << (int)(it_03 == it_05) << std::endl;
		// std::cout << (int)(it_03 == it_07) << std::endl;
		// std::cout << (int)(it_05 == it_07) << std::endl;
	}
	//------Observers---------
	{
		std::cout << "\n ### ### ### ### ### Observers test start ### ### ### ### ###" << std::endl;

		ft::map<int, int> map_01;
		ft::pair<const int, int> p1(1, 11);
		ft::pair<const int, int> p2(2, 12);
		ft::pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);

		ft::map<int, int>::key_compare my_compare = map_01.key_comp();
		int max_elem = 3;
		ft::map<int, int>::iterator it = map_01.begin();
		do {
			std::cout << it->first << " => " << it->second << std::endl;
		} while (my_compare((*it++).first, max_elem));

		ft::pair<const int, int> max_elem_1 = *map_01.rbegin();
		it = map_01.begin();
		do {
			std::cout << it->first << " => " << it->second << std::endl;
		} while (map_01.value_comp()(*it++, max_elem_1));
	}
	//------Capacity----------
	{
		std::cout << "\n ### ### ### ### ### Capacity test start ### ### ### ### ###" << std::endl;

		ft::map<int, int> map_01;
		std::cout << "Map empty: " <<		map_01.empty() << std::endl;
		std::cout << "Map size: " <<		map_01.size() << std::endl;
		std::cout << "Map max_size: " <<	map_01.max_size() << std::endl;
		ft::pair<const int, int> p1(1, 11);
		ft::pair<const int, int> p2(2, 12);
		ft::pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);
		std::cout << "Map empty: " <<		map_01.empty() << std::endl;
		std::cout << "Map size: " <<		map_01.size() << std::endl;
		std::cout << "Map max_size: " <<	map_01.max_size() << std::endl;
	}
	//------Operations--------
	{
		std::cout << "\n ### ### ### ### ### Operations test start ### ### ### ### ###" << std::endl;

		ft::map<int, int> map_01;
		ft::pair<const int, int> p1(1, 11);
		ft::pair<const int, int> p2(2, 12);
		ft::pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);

		ft::map<int, int>::iterator						it_01 = map_01.find(2);
		std::cout << "Find in map result for iterator: " << it_01->first << " - > " << it_01->second << std::endl;

		ft::map<int, int>::const_iterator		it_02 = map_01.find(2);
		std::cout << "Find in map result for const_iterator: " << it_01->first << " - > " << it_01->second << std::endl;
		
		size_t									val_01 = map_01.count(2);
		std::cout << "Result cout function: " << val_01 << std::endl;
		
		// ft::map<int, int>::iterator				it_03 = map_01.lower_bound(2);
		// ft::map<int, int>::const_iterator		it_04 = map_01.lower_bound(2);
		// ft::map<int, int>::iterator				it_05 = map_01.upper_bound(2);
		// ft::map<int, int>::const_iterator		it_06 = map_01.upper_bound(2);

		ft::map<char,int> mymap;
		ft::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)

		// print content:
		ft::map<char,int>::iterator it = mymap.begin();
		ft::map<char,int>::iterator end = mymap.end();
		for ( ; it != end; it++)
			std::cout << it->first << " => " << it->second << '\n';

		// ft::ft::pair<iterator,iterator>				p_01 = map_01.equal_range(2);
		// ft::ft::pair<const_iterator,const_iterator>	p_02 = map_01.equal_range(2);


		std::cout << "Result for equal range function:" << std::endl;
		ft::map<char,int> mymap_2;

		mymap_2['a']=10;
		mymap_2['b']=20;
		mymap_2['c']=30;

		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = mymap_2.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
	//------Operators---------
	{
		std::cout << "\n ### ### ### ### ### Operators test start ### ### ### ### ###" << std::endl;

		ft::map<int, int> map_01;
		ft::map<int, int> map_02;
		ft::pair<const int, int> p1(1, 11);
		ft::pair<const int, int> p2(2, 12);
		ft::pair<const int, int> p3(3, 13);
		map_01.insert(p1);
		map_01.insert(p2);
		map_01.insert(p3);
		ft::pair<const int, int> p11(1, 11);
		ft::pair<const int, int> p21(2, 12);
		ft::pair<const int, int> p31(3, 13);
		map_02.insert(p11);
		map_02.insert(p21);
		map_02.insert(p31);

		std::cout << "Comapare '==' : " << (map_01 == map_02) << std::endl;
		std::cout << "Comapare '!=' : " << (map_01 != map_02) << std::endl;
		std::cout << "Comapare '<' : " << (map_01 < map_02) << std::endl;
		std::cout << "Comapare '<=' : " << (map_01 <= map_02) << std::endl;
		std::cout << "Comapare '>' : " << (map_01 > map_02) << std::endl;
		std::cout << "Comapare '>=' : " << (map_01 >= map_02) << std::endl;
	}
	//------Allocator---------
	{
		std::cout << "\n ### ### ### ### ### Allocator test start ### ### ### ### ###" << std::endl;

		int psize;
		ft::map<char,int> mymap;
		ft::map<char,int>::value_type* p;

		// allocate an array of 5 elements using mymap's allocator:
		p = mymap.get_allocator().allocate(5);

		// assign some values to array
		psize = sizeof(ft::map<char,int>::value_type) * 5;

		std::cout << "The allocated array has a size of " << psize << " bytes.\n";

		mymap.get_allocator().deallocate(p,5);
	}

	std::cout << "\n ### ### ### ### ### ### ### ### ### #### ### ### ### ###" << std::endl;
	std::cout <<   " ### ### ### ### ### STACK test start ### ### ### ### ###" << std::endl;
	std::cout <<   " ### ### ### ### ### ### ### ### ### #### ### ### ### ###" << std::endl;
	//------Member functions------
	{
		std::cout << "\n ### ### ### ### ### Member functions test start ### ### ### ### ### " << std::endl;
		// constructor
		ft::stack<int>		st_01;
		ft::stack<int>		st_02(std::list<int>);
		ft::stack<int>		st_03(std::deque<int>);

		// empty
		std::cout << "Empty func st_01 = " << st_01.empty() << std::endl;
	
		// size
		std::cout << "Size stack st_01 = " << st_01.size() << std::endl;

		// push
		st_01.push(1);
		st_01.push(2);
		st_01.push(3);
		std::cout << "Size stack st_01 = " << st_01.size() << std::endl;

		// top
		std::cout << "Top stack st_01 = " << st_01.top() << std::endl;

		// pop
		st_01.pop();
		st_01.pop();
		std::cout << "Size stack st_01 = " << st_01.size() << std::endl;
	}
	//------Non-member function overloads------
	{
		std::cout << "\n ### ### ### ### ### Non-member functions test start ### ### ### ### ### " << std::endl;
		ft::stack<int>		st_01;
		ft::stack<int>		st_02;
		st_01.push(5);
		st_02.push(5);

		std::cout << "Operation == : " << (st_01 == st_02) << std::endl;
		std::cout << "Operation != : " << (st_01 != st_02) << std::endl;
		std::cout << "Operation < : " << (st_01 < st_02) << std::endl;
		std::cout << "Operation <= : " << (st_01 <= st_02) << std::endl;
		std::cout << "Operation > : " << (st_01 > st_02) << std::endl;
		std::cout << "Operation >= : " << (st_01 >= st_02) << std::endl;
	}
	
	std::cout << "\n ### ### ### ### ### ### ### ### ### # ### ### ### ### ###" << std::endl;
	std::cout <<   " ### ### ### ### ### VECTOR test start ### ### ### ### ###" << std::endl;
	std::cout <<   " ### ### ### ### ### ### ### ### ### # ### ### ### ### ###" << std::endl;
	//------Member functions------
	{
		std::cout << "\n ### ### ### ### ### Member functions test start ### ### ### ### ### " << std::endl;
		// Constructors
		ft::vector<int>	vtr_01;
		std::cout << "Size vector vtr_01 = " << vtr_01.size() << std::endl;

		ft::vector<std::string>	vtr_02(10, "Hi");
		std::cout << "Size vector vtr_02 = " << vtr_02.size() << std::endl;
		ft::vector<std::string>::iterator	it_01 = vtr_02.begin();
		ft::vector<std::string>::iterator	it_02 = vtr_02.end();
		while (it_01 != it_02){
			std::cout << *it_01 << std::endl;
			it_01++;
		}

		it_01 = vtr_02.begin();
		it_01++;
		it_02--;
		ft::vector<std::string>	vtr_03(it_01, it_02);
		std::cout << "Size vector vtr_03 = " << vtr_03.size() << std::endl;
		ft::vector<std::string>::iterator	it_03 = vtr_03.begin();
		ft::vector<std::string>::iterator	it_04 = vtr_03.end();
		while (it_03 != it_04){
			std::cout << *it_03 << std::endl;
			it_03++;
		}

		ft::vector<std::string>	vtr_04(vtr_02);
		std::cout << "Size vector vtr_04 = " << vtr_04.size() << std::endl;
		ft::vector<std::string>::iterator	it_05 = vtr_04.begin();
		ft::vector<std::string>::iterator	it_06 = vtr_04.end();
		while (it_05 != it_06){
			std::cout << *it_05 << std::endl;
			it_05++;
		}

		// operator=
		ft::vector<std::string>		vtr_05;
		std::cout << "Size vector vtr_05 = " << vtr_05.size() << std::endl;
		vtr_05 = vtr_04;
		std::cout << "Size vector after operator = vtr_05 = " << vtr_05.size() << std::endl;
	}
	//------Iterators------
	{
		std::cout << "\n ### ### ### ### ### Iterators test start ### ### ### ### ### " << std::endl;
		ft::vector<int>		vec_01;
		for (int i = 0; i < 20; ++i)
			vec_01.push_back(i);
		
		ft::vector<int>::iterator	begin = vec_01.begin();
		ft::vector<int>::iterator	end = vec_01.end();
		ft::vector<int>::const_iterator	end_2 = vec_01.begin();
		while (begin != end){
			std::cout << *begin << std::endl;
			begin++;
		}

		// operators:
		std::cout << "Operator == " << (int)(begin == end) << std::endl;
		std::cout << "Operator != " << (int)(begin != end) << std::endl;
		std::cout << "Operator <= " << (int)(begin <= end) << std::endl;
		std::cout << "Operator < " << (int)(begin < end) << std::endl;
		std::cout << "Operator >= " << (int)(begin >= end) << std::endl;
		std::cout << "Operator > " << (int)(begin > end) << std::endl;
		std::cout << "Compare iterator and const_iterator = " << (int)(end == end_2) << std::endl;

		ft::vector<int>::reverse_iterator	rbeg = vec_01.rbegin();
		ft::vector<int>::reverse_iterator	rend = vec_01.rend();
		ft::vector<int>::const_reverse_iterator	rend_2 = vec_01.rbegin();
		while (rbeg != rend){
			std::cout << *rbeg << std::endl;
			rbeg++;
		}

		// operators:
		std::cout << "Operator == " << (int)(rbeg == rend) << std::endl;
		std::cout << "Operator != " << (int)(rbeg != rend) << std::endl;
		std::cout << "Operator <= " << (int)(rbeg <= rend) << std::endl;
		std::cout << "Operator < " << (int)(rbeg < rend) << std::endl;
		std::cout << "Operator >= " << (int)(rbeg >= rend) << std::endl;
		std::cout << "Operator > " << (int)(rbeg > rend) << std::endl;
		std::cout << "Compare iterator and const_iterator = " << (int)(rend == rend_2) << std::endl;
	}
	//------Capacity------
	{
		std::cout << "\n ### ### ### ### ### Capacity test start ### ### ### ### ### " << std::endl;
		ft::vector<int> vec_01;

		// resize
		for (size_t i = 1; i < 10; i++) vec_01.push_back(i);

		vec_01.resize(5);
		vec_01.resize(8,100);
		vec_01.resize(12);
		for (size_t i = 0; i < vec_01.size(); i++)
			std::cout << ' ' << vec_01[i];
		
		// size
		std::cout << "Size vector vec_01 = " << vec_01.size() << std::endl;

		// max_size
		std::cout << "Max_size vector vec_01 = " << vec_01.max_size() << std::endl;

		// resize
		vec_01.resize(5);
		std::cout << "Size vector after resize vec_01 = " << vec_01.size() << std::endl;

		// capacity
		std::cout << "Capasity vector vec_01 = " << vec_01.capacity() << std::endl;

		// empty
		std::cout << "Empty vector vec_01 = " << vec_01.empty() << std::endl;

		// reserve
		vec_01.reserve(20);
		std::cout << "Capasity vector adter reserve vec_01 = " << vec_01.capacity() << std::endl;
	}
	//------Element access------
	{
		std::cout << "\n ### ### ### ### ### Element access test start ### ### ### ### ### " << std::endl;
		ft::vector<int> vec_01;

		// operator[]
		for (size_t i = 1; i < 10; i++) vec_01.push_back(i);
		for (size_t i = 0; i < vec_01.size(); i++)
			std::cout << ' ' << vec_01[i];

		// at
		std::cout << "at operation on vec_01 = " << vec_01.at(2) << std::endl;

		// front
		std::cout << "front operation on vec_01 = " << vec_01.front() << std::endl;

		// back
		std::cout << "back operation on vec_01 = " << vec_01.back() << std::endl;

	}
	//------Modifiers------
	{
		std::cout << "\n ### ### ### ### ### Modifiers test start ### ### ### ### ### " << std::endl;
		ft::vector<char> vec_01;
		for (size_t i = 1; i < 10; i++) vec_01.push_back(i);

		// assign
		vec_01.assign(12, 'H');
		std::cout << "Vector contain after assign operation:" << std::endl;
		for (size_t i = 0; i < vec_01.size(); i++)
			std::cout << ' ' << vec_01[i];

		// push_back
		vec_01.push_back('Z');
		std::cout << "Vector contain after push_back operation:" << std::endl;
		for (size_t i = 0; i < vec_01.size(); i++)
			std::cout << ' ' << vec_01[i];

		// pop_back
		vec_01.pop_back();
		std::cout << "Vector contain after pop_back operation:" << std::endl;
		for (size_t i = 0; i < vec_01.size(); i++)
			std::cout << ' ' << vec_01[i];

		// insert
		ft::vector<char>::iterator it = vec_01.begin();
		vec_01.insert(it, 'X');
		std::cout << "Vector contain after insert operation:" << std::endl;
		for (size_t i = 0; i < vec_01.size(); i++)
			std::cout << ' ' << vec_01[i];

		// erase
		ft::vector<char>::iterator itt = vec_01.begin();
		vec_01.erase(itt);
		std::cout << "Vector contain after erase operation:" << std::endl;
		for (size_t i = 0; i < vec_01.size(); i++)
			std::cout << ' ' << vec_01[i];

		// swap
		ft::vector<char> vec_02;
		for (size_t i = 1; i < 10; i++) vec_02.push_back('A' + i);
		ft::vector<char>::iterator	itr = vec_02.begin();
		itr++;
		std::cout << "Iteraror before swap = " << *itr << std::endl;
		// for (size_t i = 0; i < vec_02.size(); i++)
		// 	std::cout << ' ' << vec_02[i];
		vec_01.swap(vec_02);
		std::cout << "Iteraror after swap = " << *itr << std::endl;
		std::cout << "Vector contain after swap operation:" << std::endl;
		for (size_t i = 0; i < vec_01.size(); i++)
			std::cout << ' ' << vec_01[i];
		// std::cout << "Vector contain after swap operation:" << std::endl;
		// for (size_t i = 0; i < vec_02.size(); i++)
		// 	std::cout << ' ' << vec_02[i];

		// clear
		vec_01.clear();
		std::cout << "Size vector after clear operation:" << vec_01.size() << std::endl;
	
	}
	//------Allocator------
	{
		std::cout << "\n ### ### ### ### ### Allocator test start ### ### ### ### ### " << std::endl;
		ft::vector<int>	myvector;
		int*			p;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (size_t i = 0; i < 5; i++) myvector.get_allocator().construct(&p[i],i);

		std::cout << "The allocated array contains:";
		for (size_t i = 0; i < 5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		// destroy and deallocate:
		for (size_t i = 0; i < 5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	}
	//------Non-member function overloads------
	{
		std::cout << "\n ### ### ### ### ### Non-member function overloads test start ### ### ### ### ### " << std::endl;
		ft::vector<int>	vec_01;
		ft::vector<int>	vec_02;
		vec_01.push_back(2);
		vec_02.push_back(1);

		std::cout << "Operator == : " << (vec_01 == vec_02) << std::endl;
		std::cout << "Operator != : " << (vec_01 != vec_02) << std::endl;
		std::cout << "Operator < : " << (vec_01 < vec_02) << std::endl;
		std::cout << "Operator <= : " << (vec_01 <= vec_02) << std::endl;
		std::cout << "Operator > : " << (vec_01 > vec_02) << std::endl;
		std::cout << "Operator >= : " << (vec_01 >= vec_02) << std::endl;
	}
	//------Template specializations------
	{
		std::cout << "\n ### ### ### ### ### Template specializations test start ### ### ### ### ### " << std::endl;
		ft::vector<bool>	vec_01;
		vec_01.push_back(true);
		
		std::cout << "Size vector vec_01 = " << vec_01.size() << std::endl;
	}
	
	// Speed test map
	std::map<int, int>	map_01;
	ft::map<int, int>	map_02;

	std::clock_t start;
	double duration;
	start = std::clock();

	for (int i = 0; i < 100000; ++i)
		map_01.insert(std::make_pair(i, i));

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "Speed for original map = " << duration << std::endl;

	start = std::clock();

	for (int i = 0; i < 100000; ++i)
		map_02.insert(ft::make_pair(i, i));

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "Speed for my map = " << duration << std::endl;

	// Speed test vector
	std::vector<int>	vec_01;
	ft::vector<int>		vec_02;

	start = std::clock();

	for (int i = 0; i < 100000; ++i)
		vec_01.push_back(i);

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "Speed for original vector = " << duration << std::endl;

	start = std::clock();

	for (int i = 0; i < 100000; ++i)
		vec_02.push_back(i);

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "Speed for my vector = " << duration << std::endl;

	// while (1);
	return 0;
}








// #include <stdlib.h>

// #define MAX_RAM 4294967296 //4194304
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	std::cout << "step 1 ok" << std::endl;

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	// ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
// 	ft::map<int, int> map_int;
	

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 		std::cout << "i1 = "<< i << "; COUNT = " << COUNT << std::endl;
// 	}

// 	std::cout << "step 2 ok" << std::endl;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	std::cout << "step 3 ok" << std::endl;

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	std::cout << "step 4 ok" << std::endl;

// 	// clock_t start, end;
// 	// start = clock();

// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 		// if (!(i % 10000)){
// 			// end = clock();
// 			std::cout << "i = "<< i << "; COUNT = " << COUNT << std::endl;
// 		// 	printf("%.4f\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));
// 		// }
// 	}

// 	std::cout << "step 5 ok" << std::endl;

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	std::cout << "step 6 ok" << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++){
// 		iterable_stack.push(letter);
// 		std::cout << " Letter = " << letter << std::endl;
// 	}

// 	std::cout << "step 7 ok" << std::endl;

// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }
