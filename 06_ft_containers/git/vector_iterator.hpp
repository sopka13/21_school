/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:47:53 by eyohn             #+#    #+#             */
/*   Updated: 2022/01/16 17:36:45 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft{
	template< class T >
	class iterator{
		T*		_ptr;

	public:
		iterator(): _ptr(NULL){}
		iterator(T* pointer) : _ptr(pointer){}
		iterator(const iterator& other) { _ptr = other._ptr; }
		// operator=(iterator& other) : _ptr(other._ptr) { return *this; }
		~iterator(){}

		T*				operator->(){
			return _ptr;
		}
		iterator&		operator=(const iterator& other) {
			this->_ptr = other._ptr;
			return *this;
		}
		iterator&		operator++() {
			_ptr++;
			return (*this);
		}
		iterator		operator++(int) {
			iterator tmp(_ptr);
			operator++();
			return (tmp);
		}
		iterator&		operator--() {
			_ptr--;
			return (*this);
		}
		iterator		operator--(int) {
			iterator	tmp(_ptr);
			operator--();
			return (tmp);
		}
		T&				operator*() {
			return *_ptr;
		}
		iterator		operator[](int n) {
			return _ptr[n];
		}
		iterator		operator+(int n) {
			return iterator(_ptr + n);
		}
		iterator&		operator+=(int n) {
			_ptr += n;
			return *this;
		}
		iterator		operator-(int n) {
			return iterator(_ptr - n);
		}
		iterator&		operator-=(int n) {
			_ptr -= n;
			return *this;
		}
		
		template <typename AT1, typename AT2>
		friend bool			operator==(iterator<AT1> x, iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator!=(iterator<AT1> x, iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator<(iterator<AT1> x, iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator<=(iterator<AT1> x, iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator>(iterator<AT1> x, iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator>=(iterator<AT1> x, iterator<AT2> y);
	};
	template <typename AT1, typename AT2>
	bool			operator==(iterator<AT1> x, iterator<AT2> y) {
		return (x._ptr == y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator!=(iterator<AT1> x, iterator<AT2> y) {
		return (x._ptr != y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator<(iterator<AT1> x, iterator<AT2> y) {
		return (x._ptr < y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator<=(iterator<AT1> x, iterator<AT2> y) {
		return (x._ptr <= y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator>(iterator<AT1> x, iterator<AT2> y) {
		return (x._ptr > y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator>=(iterator<AT1> x, iterator<AT2> y) {
		return (x._ptr >= y._ptr);
	}

	template< class T >
	class const_iterator{
		const T*		_ptr;

	public:
		const_iterator(): _ptr(NULL){}
		const_iterator(T* pointer) : _ptr(pointer){}
		const_iterator(const const_iterator& other) : _ptr(other._ptr){}
		~const_iterator(){}

		const_iterator&		operator=(const const_iterator& other) {
			this->_ptr = other._ptr;
			return *this;
		}
		const_iterator&		operator++() {
			_ptr++;
			return (*this);
		}
		const_iterator		operator++(int) {
			const_iterator tmp(_ptr);
			operator++();
			return (tmp);
		}
		const_iterator&		operator--() {
			_ptr--;
			return (*this);
		}
		const_iterator		operator--(int) {
			const_iterator	tmp(_ptr);
			operator--();
			return (tmp);
		}
		const T&			operator*() {
			return *_ptr;
		}
		const_iterator		operator[](int n) {
			return _ptr[n];
		}
		const_iterator		operator+(int n) {
			return const_iterator(_ptr + n);
		}
		const_iterator&		operator+=(int n) {
			_ptr += n;
			return *this;
		}
		const_iterator		operator-(int n) {
			return const_iterator(_ptr - n);
		}
		const_iterator&		operator-=(int n) {
			_ptr -= n;
			return *this;
		}
		
		template <typename AT1, typename AT2>
		friend bool			operator==(const_iterator<AT1> x, const_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator!=(const_iterator<AT1> x, const_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator<(const_iterator<AT1> x, const_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator<=(const_iterator<AT1> x, const_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator>(const_iterator<AT1> x, const_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator>=(const_iterator<AT1> x, const_iterator<AT2> y);
	};
	template <typename AT1, typename AT2>
	bool			operator==(const_iterator<AT1> x, const_iterator<AT2> y) {
		return (x._ptr == y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator!=(const_iterator<AT1> x, const_iterator<AT2> y) {
		return (x._ptr != y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator<(const_iterator<AT1> x, const_iterator<AT2> y) {
		return (x._ptr < y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator<=(const_iterator<AT1> x, const_iterator<AT2> y) {
		return (x._ptr <= y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator>(const_iterator<AT1> x, const_iterator<AT2> y) {
		return (x._ptr > y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator>=(const_iterator<AT1> x, const_iterator<AT2> y) {
		return (x._ptr >= y._ptr);
	}

	template< class T >
	class reverse_iterator{
		T*		_ptr;

	public:
		reverse_iterator(): _ptr(NULL){}
		reverse_iterator(T* pointer) : _ptr(pointer){}
		reverse_iterator(const reverse_iterator& other) : _ptr(other._ptr){}
		~reverse_iterator(){}

		reverse_iterator&	operator=(const reverse_iterator& other) {
			this->_ptr = other._ptr;
			return *this;
		}
		reverse_iterator&	operator++() {
			_ptr--;
			return (*this);
		}
		reverse_iterator	operator++(int) {
			reverse_iterator tmp(_ptr);
			operator++();
			return (tmp);
		}
		reverse_iterator&	operator--() {
			_ptr++;
			return (*this);
		}
		reverse_iterator	operator--(int) {
			reverse_iterator	tmp(_ptr);
			operator--();
			return (tmp);
		}
		T&					operator*() {
			return *_ptr;
		}
		reverse_iterator	operator[](int n) {
			return _ptr[n];
		}
		reverse_iterator	operator+(int n) {
			return reverse_iterator(_ptr + n);
		}
		reverse_iterator&	operator+=(int n) {
			_ptr += n;
			return *this;
		}
		reverse_iterator	operator-(int n) {
			return reverse_iterator(_ptr - n);
		}
		reverse_iterator&	operator-=(int n) {
			_ptr -= n;
			return *this;
		}
		
		template <typename AT1, typename AT2>
		friend bool			operator==(reverse_iterator<AT1> x, reverse_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator!=(reverse_iterator<AT1> x, reverse_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator<(reverse_iterator<AT1> x, reverse_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator<=(reverse_iterator<AT1> x, reverse_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator>(reverse_iterator<AT1> x, reverse_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator>=(reverse_iterator<AT1> x, reverse_iterator<AT2> y);
	};
	template <typename AT1, typename AT2>
	bool			operator==(reverse_iterator<AT1> x, reverse_iterator<AT2> y) {
		return (x._ptr == y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator!=(reverse_iterator<AT1> x, reverse_iterator<AT2> y) {
		return (x._ptr != y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator<(reverse_iterator<AT1> x, reverse_iterator<AT2> y) {
		return (x._ptr < y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator<=(reverse_iterator<AT1> x, reverse_iterator<AT2> y) {
		return (x._ptr <= y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator>(reverse_iterator<AT1> x, reverse_iterator<AT2> y) {
		return (x._ptr > y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator>=(reverse_iterator<AT1> x, reverse_iterator<AT2> y) {
		return (x._ptr >= y._ptr);
	}
	
	template< class T >
	class const_reverse_iterator{
		const T*		_ptr;

	public:
		const_reverse_iterator(): _ptr(NULL){}
		const_reverse_iterator(T* pointer) : _ptr(pointer){}
		const_reverse_iterator(const const_reverse_iterator& other) : _ptr(other._ptr){}
		~const_reverse_iterator(){}

		const_reverse_iterator&		operator=(const const_reverse_iterator& other) {
			this->_ptr = other._ptr;
			return *this;
		}
		const_reverse_iterator&		operator++() {
			_ptr++;
			return (*this);
		}
		const_reverse_iterator		operator++(int) {
			const_reverse_iterator tmp(_ptr);
			operator++();
			return (tmp);
		}
		const_reverse_iterator&		operator--() {
			_ptr--;
			return (*this);
		}
		const_reverse_iterator		operator--(int) {
			const_reverse_iterator	tmp(_ptr);
			operator--();
			return (tmp);
		}
		const T&					operator*() {
			return *_ptr;
		}
		const_reverse_iterator		operator[](int n) {
			return _ptr[n];
		}
		const_reverse_iterator		operator+(int n) {
			return const_reverse_iterator(_ptr + n);
		}
		const_reverse_iterator&		operator+=(int n) {
			_ptr += n;
			return *this;
		}
		const_reverse_iterator		operator-(int n) {
			return const_reverse_iterator(_ptr - n);
		}
		const_reverse_iterator&		operator-=(int n) {
			_ptr -= n;
			return *this;
		}
		
		template <typename AT1, typename AT2>
		friend bool			operator==(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator!=(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator<(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator<=(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator>(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y);
		template <typename AT1, typename AT2>
		friend bool			operator>=(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y);
	};
	template <typename AT1, typename AT2>
	bool			operator==(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y) {
		return (x._ptr == y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator!=(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y) {
		return (x._ptr != y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator<(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y) {
		return (x._ptr < y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator<=(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y) {
		return (x._ptr <= y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator>(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y) {
		return (x._ptr > y._ptr);
	}
	template <typename AT1, typename AT2>
	bool			operator>=(const_reverse_iterator<AT1> x, const_reverse_iterator<AT2> y) {
		return (x._ptr >= y._ptr);
	}

}