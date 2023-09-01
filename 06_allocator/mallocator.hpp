/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocator.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:27:32 by eyohn             #+#    #+#             */
/*   Updated: 2021/09/03 14:31:16 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft {
	template <class T>
	class mallocator {
	public:
		mallocator();
		mallocator(const mallocator& other);
		template <class U>
		mallocator(const mallocator<U>& other) {

		}
		~mallocator();

		T*			address(&x) const;
		const T*	address(const &x) const;
		T*			allocate(size_t n, const T* hint= 0 );
		void		deallocate(T *p, size_t n);
		size_t		max_size() const;
		void		construct(T *p, const T &val);
		void		destroy(T* p);

	};

template <class T1, class T2>
bool		operator==(const mallocator<T1>& lhs, const mallocator<T2>& rhs){

}
		
template< class T1, class T2 >
bool		operator!=(const mallocator<T1>& lhs, const mallocator<T2>& rhs){
	
}
}