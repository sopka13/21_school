/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:03:47 by eyohn             #+#    #+#             */
/*   Updated: 2022/01/16 23:45:13 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "source.hpp"
// #include "vector_iterator.hpp"

namespace ft {
	

	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		T*			_container;
		size_t		_size;
		Allocator	_alloc;
		size_t		_capacity;

	public:
		explicit vector( const Allocator& alloc = Allocator() ):
			_container(NULL),
			_size(0),
			_alloc(alloc),
			_capacity(0)
		{}
		explicit vector( size_t count, const T& value, const Allocator& alloc = Allocator()):
			_container(NULL),
			_size(count),
			_alloc(alloc),
			_capacity(count)
		{
			_container = _alloc.allocate(count);
			for (size_t i = 0; i < count; ++i)
				_alloc.construct(_container + i, value);
		}
		template< class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator()):
			_container(NULL),
			_size(0),
			_alloc(alloc),
			_capacity(0)
		{
			this->assign(first, last);
		}
		vector( const vector& other):
			_container(NULL),
			_size(0),
			_capacity(0)
		{
			*this = other;
		}
		~vector(){
			for(size_t i = 0; i < _size; ++i)
				_alloc.destroy(_container + i);
			_alloc.deallocate(_container, _size);
		}

		class const_iterator;
		class const_reverse_iterator;
		class iterator{
			T*		_ptr;

		public:
			iterator(): _ptr(NULL){}
			iterator(T* pointer) : _ptr(pointer){}
			iterator(const iterator& other) { _ptr = other._ptr; }
			~iterator(){}

			T*		get_p() {
				return _ptr;
			}
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
			operator		const_iterator(){
				return const_iterator(_ptr);
			}

			typedef typename ft::vector<T, Allocator>::iterator					iterator_type;

			bool			operator==(iterator_type x) {
				return (x._ptr == this->_ptr);
			}
			bool			operator!=(iterator_type x) {
				return this->_ptr != x.get_p();
			}
			bool			operator<(iterator_type x) {
				return (x._ptr < this->_ptr);
			}
			bool			operator<=(iterator_type x) {
				return (x._ptr <= this->_ptr);
			}
			bool			operator>(iterator_type x) {
				return (x._ptr > this->_ptr);
			}
			bool			operator>=(iterator_type x) {
				return (x._ptr >= this->_ptr);
			}

			typedef typename ft::vector<T, Allocator>::const_iterator&				const_iterator_type;

			bool			operator==(const_iterator_type x) {
				return (x.get_p() == this->_ptr);
			}
			bool			operator!=(const_iterator_type x) {
				return this->_ptr != x.get_p();
			}
			bool			operator<(const_iterator_type x) {
				return (x.get_p() < this->_ptr);
			}
			bool			operator<=(const_iterator_type x) {
				return (x.get_p() <= this->_ptr);
			}
			bool			operator>(const_iterator_type x) {
				return (x.get_p() > this->_ptr);
			}
			bool			operator>=(const_iterator_type x) {
				return (x.get_p() >= this->_ptr);
			}

		};
		class const_iterator{
			const T*		_ptr;

		public:
			const_iterator(): _ptr(NULL){}
			const_iterator(T* pointer) : _ptr(pointer){}
			const_iterator(const const_iterator& other) { _ptr = other._ptr; }
			~const_iterator(){}

			const T*			get_p() {
				return _ptr;
			}
			const_iterator&		operator=(const const_iterator& other) {
				this->_ptr = other.get_p();
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
			
			typedef typename ft::vector<T, Allocator>::const_iterator&					iterator_type;

			bool			operator==(iterator_type x) {
				return (x._ptr == this->_ptr);
			}
			bool			operator!=(iterator_type x) {
				return (x._ptr != this->_ptr);
			}
			bool			operator<(iterator_type x) {
				return (x._ptr < this->_ptr);
			}
			bool			operator<=(iterator_type x) {
				return (x._ptr <= this->_ptr);
			}
			bool			operator>(iterator_type x) {
				return (x._ptr > this->_ptr);
			}
			bool			operator>=(iterator_type x) {
				return (x._ptr >= this->_ptr);
			}
		
			typedef typename ft::vector<T, Allocator>::iterator&				const_iterator_type;

			bool			operator==(const_iterator_type x) {
				return (x.get_p() == this->_ptr);
			}
			bool			operator!=(const_iterator_type x) {
				return this->_ptr != x.get_p();
			}
			bool			operator<(const_iterator_type x) {
				return (x.get_p() < this->_ptr);
			}
			bool			operator<=(const_iterator_type x) {
				return (x.get_p() <= this->_ptr);
			}
			bool			operator>(const_iterator_type x) {
				return (x.get_p() > this->_ptr);
			}
			bool			operator>=(const_iterator_type x) {
				return (x.get_p() >= this->_ptr);
			}

		};
		class reverse_iterator{
			T*		_ptr;

		public:
			reverse_iterator(): _ptr(NULL){}
			reverse_iterator(T* pointer) : _ptr(pointer){}
			reverse_iterator(const reverse_iterator& other) { _ptr = other._ptr; }
			~reverse_iterator(){}

			T*			get_p() {
				return _ptr;
			}
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
			operator			const_reverse_iterator(){
				return const_reverse_iterator(_ptr);
			}

			typedef typename ft::vector<T, Allocator>::reverse_iterator&					iterator_type;

			bool			operator==(iterator_type x) {
				return (x._ptr == this->_ptr);
			}
			bool			operator!=(iterator_type x) {
				return (x._ptr != this->_ptr);
			}
			bool			operator<(iterator_type x) {
				return (x._ptr < this->_ptr);
			}
			bool			operator<=(iterator_type x) {
				return (x._ptr <= this->_ptr);
			}
			bool			operator>(iterator_type x) {
				return (x._ptr > this->_ptr);
			}
			bool			operator>=(iterator_type x) {
				return (x._ptr >= this->_ptr);
			}
		
			typedef typename ft::vector<T, Allocator>::const_reverse_iterator&				const_iterator_type;

			bool			operator==(const_iterator_type x) {
				return (x.get_p() == this->_ptr);
			}
			bool			operator!=(const_iterator_type x) {
				return (x.get_p() != this->_ptr);
			}
			bool			operator<(const_iterator_type x) {
				return (x.get_p() < this->_ptr);
			}
			bool			operator<=(const_iterator_type x) {
				return (x.get_p() <= this->_ptr);
			}
			bool			operator>(const_iterator_type x) {
				return (x.get_p() > this->_ptr);
			}
			bool			operator>=(const_iterator_type x) {
				return (x.get_p() >= this->_ptr);
			}
		
		};
		class const_reverse_iterator{
			const T*		_ptr;

		public:
			const_reverse_iterator(): _ptr(NULL){}
			const_reverse_iterator(T* pointer) : _ptr(pointer){}
			const_reverse_iterator(const const_reverse_iterator& other) { _ptr = other._ptr; }
			~const_reverse_iterator(){}

			const T*					get_p() {
				return _ptr;
			}
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
			
			typedef typename ft::vector<T, Allocator>::const_reverse_iterator&					iterator_type;

			bool			operator==(iterator_type x) {
				return (x._ptr == this->_ptr);
			}
			bool			operator!=(iterator_type x) {
				return (x._ptr != this->_ptr);
			}
			bool			operator<(iterator_type x) {
				return (x._ptr < this->_ptr);
			}
			bool			operator<=(iterator_type x) {
				return (x._ptr <= this->_ptr);
			}
			bool			operator>(iterator_type x) {
				return (x._ptr > this->_ptr);
			}
			bool			operator>=(iterator_type x) {
				return (x._ptr >= this->_ptr);
			}
		
			typedef typename ft::vector<T, Allocator>::reverse_iterator&				const_iterator_type;

			bool			operator==(const_iterator_type x) {
				return (x.get_p() == this->_ptr);
			}
			bool			operator!=(const_iterator_type x) {
				return (x.get_p() != this->_ptr);
			}
			bool			operator<(const_iterator_type x) {
				return (x.get_p() < this->_ptr);
			}
			bool			operator<=(const_iterator_type x) {
				return (x.get_p() <= this->_ptr);
			}
			bool			operator>(const_iterator_type x) {
				return (x.get_p() > this->_ptr);
			}
			bool			operator>=(const_iterator_type x) {
				return (x.get_p() >= this->_ptr);
			}
	
		};

		vector& operator=(const vector& other){
			if (_container){
				for (size_t i = 0; i < _size; ++i)
					_alloc.destroy(_container + i);
				_alloc.deallocate(_container, _capacity);
			}
			_size = other.size();
			_capacity = other._capacity;
			_container = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(_container + i, other[i]);
			return (*this);
		}

		// Iterators:
		iterator				begin() {
			return iterator(_container);
		}
		const_iterator			begin() const {
			return const_iterator(_container);
		}
		iterator				end(){
			return iterator(_container + _size);
		}
		const_iterator			end() const {
			return const_iterator(_container + _size);
		}
		reverse_iterator		rbegin(){
			return reverse_iterator(_container + _size - 1);
		}
		const_reverse_iterator	rbegin() const{
			return const_reverse_iterator(_container +_size - 1);
		}
		reverse_iterator		rend(){
			return reverse_iterator(_container - 1);
		}
		const_reverse_iterator	rend() const{
			return const_reverse_iterator(_container - 1);
		}

		// Capacity:
		size_t					size() const{
			return (_size);
		}
		size_t					max_size() const{
			long a = sysconf(_SC_PHYS_PAGES);
			long b = sysconf(_SC_PAGESIZE);
			long c = a * b;
			return static_cast<size_t>(c / sizeof(T));
			// return (_alloc.max_alloc());
		}
		void					reserve( size_t size ){
			if (size <= _capacity)
				return ;
			T* temp = _alloc.allocate(size);
			for (size_t k = 0; k < _size; ++k)
				_alloc.construct(temp + k, _container[k]);
			int tmp_size = _size;
			this->clear();
			_alloc.deallocate(_container, _capacity);
			_container = temp;
			_capacity = size;
			_size = tmp_size;
		}
		size_t					capacity() const{
			return (_capacity);
		}
		bool					empty() const{
			if (_size)
				return (false);
			return (true);
		}

		// Element access:
		T&						operator[]( size_t pos ){
			if (pos >= _size)
				throw std::out_of_range("Array out of bounds");
			else
				return (_container[pos]);
		}
		const T&				operator[]( size_t pos ) const{
			if (pos >= _size)
				throw std::out_of_range("Array out of bounds");
			else
				return (_container[pos]);
		}
		T&						at( size_t pos ){
			if (pos >= _size)
				throw std::out_of_range("Array out of bounds");
			else
				return (_container[pos]);
		}
		const T&				at( size_t pos ) const{
			if (pos >= _size)
				throw std::out_of_range("Array out of bounds");
			else
				return (_container[pos]);
		}
		T&		 				front(){
			if (!_size)
				throw std::out_of_range("Error: out of bounds");
			return (_container[0]);
		}
		const T&				front() const{
			if (!_size)
				throw std::out_of_range("Error: out of bounds");
			return (_container[0]);
		}
		T&		 				back(){
			if (!_size)
				throw std::out_of_range("Error: out of bounds");
			return (_container[_size - 1]);
		}
		const T&				back() const{
			if (!_size)
				throw std::out_of_range("Error: out of bounds");
			return (_container[_size - 1]);
		}
		T*						data(){
			return (&_container[0]);
		}
		const T*				data() const{
			return (&_container[0]);
		}

		// Modifiers:
		void					assign( size_t count, const T& value ){
			this->clear();
			for (size_t k = 0; k < count; ++k)
				push_back(value);
		}
		template< class InputIt >
		void					assign( InputIt first, InputIt last){
			this->clear();
			while (first != last) {
				push_back(*first);
				first++;
			}
		}
		void					push_back( const T& value ){
			if (!_size){
				reserve(1);
				_alloc.construct(_container, value);
				_size++;
			} else if (_size == _capacity) {
				reserve(_size * 2);
				_alloc.construct(_container + _size, value);
				_size++;
			} else {
				// reserve(_size + 1);
				_alloc.construct(_container + _size, value);
				_size++;
			}
		}
		void					pop_back(){
			_alloc.destroy(_container + _size - 1);
			_size--;
		}
		iterator				insert( iterator pos, const T& value ){
			int	i = 0;
			for (iterator it = begin(); it != pos; it++, i++) {}
			if (_size == _capacity) {
				reserve(_capacity ? _capacity * 2 : 1);
				pos = _container + i;
			}
			for (iterator it = this->end(); it != pos; it--) {
				_alloc.destroy(it.operator->());
				_alloc.construct(it.operator->(), *(it - 1));
			}
			*pos = value;
			_size++;
			return (pos);	
		}
		void					insert( iterator pos, size_t count, const T& value ){
			vector temp(pos, end());
			while (pos != end()){
				_size--;
				pos++;
			}
			while (count){
				push_back(value);
				count--;
			}
			iterator it = temp.begin();
			while (it != temp.end()){
				push_back(*it);
				it++;
			}
		}
		template< class InputIt >
		void					insert( iterator pos, InputIt first, InputIt last){
			vector temp(pos, end());
			while (pos != end()){
				_size--;
				pos++;
			}
			while (first != last){
				push_back(*first);
				first++;
			}
			iterator it = temp.begin();
			while (it != temp.end()){
				push_back(*it);
				it++;
			}
		}
		iterator				erase( iterator pos ){
			vector temp(pos + 1, end());
			iterator end = this->end();
			while (pos != end){
				_alloc.destroy(_container + _size - 1);
				_size--;
				pos++;
			}
			iterator ret(_container + _size - 1);
			iterator it = temp.begin();
			iterator end_2 = temp.end();
			while (it != end_2){
				push_back(*it);
				it++;
			}
			return (ret);
		}
		iterator				erase( iterator first, iterator last ){
			vector temp(last, end());
			iterator ret(last);
			while (first != end()){
				_alloc.destroy(_container + _size - 1);
				_size--;
				first++;
			}
			iterator it = temp.begin();
			while (it != temp.end()){
				push_back(*it);
				it++;
			}
			return (ret);
		}
		void					swap( vector& other ){
			T*			t_cont = other._container;
			size_t		t_size = other._size;
			Allocator	t_alloc = other._alloc;
			size_t		t_capa = other._capacity;

			other._container = this->_container;
			other._size = this->_size;
			other._alloc = this->_alloc;
			other._capacity = this->_capacity;
			
			this->_container = t_cont;
			this->_size = t_size;
			this->_alloc = t_alloc;
			this->_capacity = t_capa;
			// ft::vector<T> temp = other;
			// other = *this;
			// *this = temp;
		}
		void					clear(){
			while (_size)
				pop_back();
		}
		void					resize( size_t n, T value = T()){
			if (n > max_size())
				return ;
			if (n <= _size){
				while (n < _size)
					pop_back();
			} else {
				while (n > _size)
					push_back(value);
			}
		}

		// Allocator:
		Allocator				get_allocator() const{
			return (_alloc);
		}
	};

	// template <class T>
	// bool			operator==(typename vector<T>::iterator x, typename vector<T>::iterator y) {
	// 	return (x._ptr == y._ptr);
	// }
	// template <typename AT1, typename AT2>
	// bool			operator!=(iterator<AT1> x, iterator<AT2> y) {
	// 	return (x._ptr != y._ptr);
	// }
	// template <typename AT1, typename AT2>
	// bool			operator<(iterator<AT1> x, iterator<AT2> y) {
	// 	return (x._ptr < y._ptr);
	// }
	// template <typename AT1, typename AT2>
	// bool			operator<=(iterator<AT1> x, iterator<AT2> y) {
	// 	return (x._ptr <= y._ptr);
	// }
	// template <typename AT1, typename AT2>
	// bool			operator>(iterator<T1> x, iterator<AT2> y) {
	// 	return (x._ptr > y._ptr);
	// }
	// template <typename AT1, typename AT2>
	// bool			operator>=(iterator<AT1> x, iterator<AT2> y) {
	// 	return (x._ptr >= y._ptr);
	// }

	template<class T>
	bool operator==( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (true);
		if (lhs.size() != rhs.size())
			return (false);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs != *start_rhs)
				return (false);
			start_lhs++;
			start_rhs++;
		}
		return (true);
	}

	template<class T>
	bool operator!=( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (false);
		if (lhs.size() != rhs.size())
			return (true);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs != *start_rhs)
				return (true);
			start_lhs++;
			start_rhs++;
		}
		return (false);
	}

	template<class T>
	bool operator<( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (false);
		if (lhs.size() < rhs.size())
			return (true);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs < *start_rhs)
				return (true);
			start_lhs++;
			start_rhs++;
		}
		return (false);
	}

	template<class T>
	bool operator<=( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (true);
		if (lhs.size() <= rhs.size())
			return (true);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs <= *start_rhs)
				return (true);
			start_lhs++;
			start_rhs++;
		}
		return (false);
	}

	template<class T>
	bool operator>( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (false);
		if (lhs.size() > rhs.size())
			return (true);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs > *start_rhs)
				return (true);
			start_lhs++;
			start_rhs++;
		}
		return (false);
	}

	template<class T>
	bool operator>=( vector<T>& lhs, vector<T>& rhs ){
		if (lhs.data() == rhs.data())
			return (false);
		if (lhs.size() >= rhs.size())
			return (true);

		typename vector<T>::iterator start_lhs = lhs.begin();
		typename vector<T>::iterator start_rhs = rhs.begin();
		typename vector<T>::iterator end_lhs = lhs.end();

		while (start_lhs != end_lhs){
			if (*start_lhs >= *start_rhs)
				return (true);
			start_lhs++;
			start_rhs++;
		}
		return (false);
	}
}