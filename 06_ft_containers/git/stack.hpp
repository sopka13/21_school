/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:53 by eyohn             #+#    #+#             */
/*   Updated: 2022/01/16 23:23:54 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef Container		container_type;

	protected:
		container_type		c;
	public:
		explicit stack( const container_type& cont = container_type() ) : c(cont) {}
		stack(const stack& other) : c(other.c) {}
		// ~stack();


		stack&						operator=( const stack& other ){
			c = other.c;
			return *this;
		}
		bool						empty() const{
			return c.empty();
		}
		size_t						size() const{
			return c.size();
		}
		T&							top(){
			return c.back();
		}
		const T&					top() const{
			return c.back();
		}
		void						push( const T& value ){
			return c.push_back(value);
		}
		void						pop(){
			return c.pop_back();
		}
	
		template<class _T, class _Container>
		friend bool operator==( ft::stack<_T, _Container>& lhs, ft::stack<_T, _Container>& rhs );
		template<class _T, class _Container>
		friend bool operator!=( ft::stack<_T, _Container>& lhs, ft::stack<_T, _Container>& rhs );
		template<class _T, class _Container>
		friend bool operator<( ft::stack<_T, _Container>& lhs, ft::stack<_T, _Container>& rhs );
		template<class _T, class _Container>
		friend bool operator<=( ft::stack<_T, _Container>& lhs, ft::stack<_T, _Container>& rhs );
		template<class _T, class _Container>
		friend bool operator>( ft::stack<_T, _Container>& lhs, ft::stack<_T, _Container>& rhs );
		template<class _T, class _Container>
		friend bool operator>=( ft::stack<_T, _Container>& lhs, ft::stack<_T, _Container>& rhs );
	};

	template<class T, class Container>
	bool operator==( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs.c == rhs.c);
	}

	template<class T, class Container>
	bool operator!=( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs.c != rhs.c);
	}

	template<class T, class Container>
	bool operator<( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs.c < rhs.c);
	}

	template<class T, class Container>
	bool operator<=( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs.c <= rhs.c);
	}

	template<class T, class Container>
	bool operator>( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs.c > rhs.c);
	}

	template<class T, class Container>
	bool operator>=( ft::stack<T, Container>& lhs, ft::stack<T, Container>& rhs ){
		return (lhs.c >= rhs.c);
	}

}