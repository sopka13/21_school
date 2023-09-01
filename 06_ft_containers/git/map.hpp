/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:25:26 by eyohn             #+#    #+#             */
/*   Updated: 2022/01/18 21:36:40 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <unistd.h>
#include <math.h>
#include "source.hpp"
#include "stack.hpp"

namespace ft {
	template<typename T1, typename T2>
	class t_treeElem {

	public:
		t_treeElem(const pair<const T1, T2>& value, t_treeElem* parent = NULL):
			_kv(value.first, value.second),
			_left(NULL),
			_right(NULL),
			_parent(parent),
			_k(0)
		{}
		t_treeElem(t_treeElem* parent): // for _n_node and _rn_node
			_left(NULL),
			_right(NULL),
			_parent(parent),
			_k(-1)
		{}
		t_treeElem():					// for _nn_node and _rnn_node
			_left(NULL),
			_right(NULL),
			_parent(NULL),
			_k(-1)
		{}
		~t_treeElem(){}

		pair<T1, T2>	_kv;
		t_treeElem*		_left;
		t_treeElem*		_right;
		t_treeElem*		_parent;
		int				_k;

	};

	template <class Key, class T, class Compare = less<Key>,
				class Allocator = std::allocator<t_treeElem<const Key, T> > >
	class map
	{
		t_treeElem<const Key, T>*	_tree;
		Compare						_compare;
		Allocator					_al;
		size_t						_size;
		t_treeElem<const Key, T>*	_n_node;
		t_treeElem<const Key, T>*	_nn_node;
		t_treeElem<const Key, T>*	_rn_node;
		t_treeElem<const Key, T>*	_rnn_node;
		int							_copy_flag;

	public:
		typedef Allocator							allocator_type;
		typedef Compare								key_compare;
		typedef t_treeElem<const Key, T>			value_type;

		class const_iterator;
		class const_reverse_iterator;

	private:
		class fast_iterator {
			const t_treeElem<const Key, T>*				_pointer;
			const t_treeElem<const Key, T>*				_last;
			const ft::map<Key, T, Compare, Allocator>*	_map_pointer;

		public:
			fast_iterator():
				_pointer(NULL),
				_map_pointer(NULL)
			{}
			fast_iterator(t_treeElem<const Key, T>* pointer, const ft::map<Key, T, Compare, Allocator>*	map_pointer):
				_pointer(pointer),
				_map_pointer(map_pointer)
			{}
			~fast_iterator() {};

			typedef typename ft::map<Key, T>::fast_iterator&	iterator_type;

			const t_treeElem<const Key, T>*	get_p() {
				return (_pointer);
			}
			const pair<const Key, T>*		operator->() {
				return (&_pointer->_kv);
			}
			iterator_type					operator++(int) {
				// std::cout << "start P = " << _pointer->_kv.first << std::endl;
				_last = _pointer;
				while (1){
					// std::cout << "iter P = " << _pointer->_kv.first << "; last = " << _last->_kv.first << std::endl;
					if (_pointer->_left &&
						_last != _pointer->_left &&
						_last != _pointer->_right){
							// std::cout << "left 1 P = " << _pointer->_left->_kv.first << std::endl;
							_pointer = _pointer->_left;
							// std::cout << "end 1 P = " << _pointer->_kv.first << std::endl;
							return *this;
					} else if (_pointer->_right &&
						_last != _pointer->_right) {
							_pointer = _pointer->_right;
							// std::cout << "end 2 P = " << _pointer->_kv.first << std::endl;
							return *this;
					} else if (_pointer->_parent &&
						_pointer->_parent->_left == _pointer) {
							if (_pointer != _last)// && _last == _pointer->_right)
								_last = _pointer;
							_pointer = _pointer->_parent;
							continue ;
					} else if (_pointer->_parent &&
						_pointer->_parent->_right == _pointer) {
							if (_pointer != _last)// && _last == _pointer->_right)
								_last = _pointer;
							_pointer = _pointer->_parent;
							continue ;
					} else {
						_pointer = _map_pointer->_nn_node;
						// std::cout << "end P = " << _pointer->_kv.first << std::endl;
						return *this;
					}
				}

			}
			bool							operator!=(iterator_type it) {
				return this->_pointer != it._pointer;
			}
		};

	public:
		class iterator {
			t_treeElem<const Key, T>*				_pointer;
			ft::map<Key, T, Compare, Allocator>*	_map_pointer;

		public:
			iterator():
				_pointer(NULL),
				_map_pointer(NULL)
			{}
			// iterator(ft::map<Key, T>* pointer):
			// 	_pointer(pointer)
			// {}
			iterator(t_treeElem<const Key, T>* pointer):
				_pointer(pointer),
				_map_pointer(NULL)
			{}
			iterator(t_treeElem<const Key, T>* pointer, ft::map<Key, T, Compare, Allocator>*	map_pointer):
				_pointer(pointer),
				_map_pointer(map_pointer)
			{}
			~iterator() {};

			typedef typename ft::map<Key, T>::iterator&	iterator_type;

			t_treeElem<const Key, T>*	get_p() {
				return (_pointer);
			}
			pair<const Key, T>&			operator*(){
				return (_pointer->_kv);
			}
			iterator_type				operator=(t_treeElem<const Key, T>* pointer) {
				this->_pointer = pointer;
				return *this;
			}
			bool						operator==(iterator_type it) {
				return this->_pointer == it.get_p();
			}
			iterator_type				operator++(int) {
				if (_pointer->_k == -1)
					return *this;
				//	1. check current position
				//	2. if have right
				//		2.1. rewrite _pointer to _right and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. check current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. rewrite _pointer to _parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. go to the parent
				//				3.1.3.2. while (1)
				//					3.1.3.2.1. if _parent == NUll ->						rewrite _pointer to null node and return
				//					3.1.3.2.2. if current positions it's right in parent ->	change curent position to parent continue
				//					3.1.3.2.3. if current positions it's left in parent ->	rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_right){
					_pointer = _map_pointer->search_min(_pointer->_right);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left != _pointer &&
							_pointer->_parent->_right != _pointer &&
							_map_pointer->search(_pointer->_kv.first) == NULL) {
								iterator	begin = _map_pointer->begin();
								iterator	end = _map_pointer->end();
								while (begin != end &&
										!_map_pointer->_compare(this->get_p()->_kv.first, begin->first)) {
									begin++;
								}
								// begin--;
								_pointer = begin.get_p();
								return *this;
							}
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
						} else {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									_pointer = _map_pointer->_n_node;
									break ;
								}
								if (_pointer->_parent->_right == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						}
					} else {
						_pointer = _map_pointer->_n_node;
					}
				}
				return *this;
			}
			iterator_type				operator--(int) {
				if (_pointer->_k == -1)
					return *this;
				//	1. check current position
				//	2. if have _left
				//		2.1. rewrite _pointer to _left and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. if current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. go to the parent
				//				3.1.2.2. while (1)
				//					3.1.2.2.1. if _parent == NULL -> 	rewrite _pointer to null node and return
				//					3.1.2.2.2. if current position it's left ->	go to the parent and continue
				//					3.1.2.2.3. if current position it's right -> rewrite _pointer to parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_left){
					_pointer = _map_pointer->search_max(_pointer->_left);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left != _pointer &&
							_pointer->_parent->_right != _pointer &&
							_map_pointer->search(_pointer->_kv.first) == NULL) {
								iterator	begin = _map_pointer->begin();
								iterator	end = _map_pointer->end();
								while (begin != end &&
										!_map_pointer->_compare(this->get_p()->_kv.first, begin->first)) {
									begin++;
								}
								begin--;
								_pointer = begin.get_p();
								return *this;
							}
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									_pointer = _map_pointer->_nn_node;
									break ;
								}
								if (_pointer->_parent->_left == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						} else {
							_pointer = _pointer->_parent;
						}
					} else {
						_pointer = _map_pointer->_nn_node;
					}
				}
				return *this;
			}
			bool						operator>(iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool						operator>=(iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool						operator<(iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool						operator<=(iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool						operator!=(iterator_type it) {
				return this->_pointer != it.get_p();
			}
			pair<const Key, T>*			operator->() {
				return (&_pointer->_kv);
			}
			operator const_iterator(){
				return const_iterator(_pointer, _map_pointer);
			}
		
			typedef typename ft::map<Key, T>::const_iterator&	const_iterator_type;

			bool						operator==(const_iterator_type it) {
				return this->_pointer == it.get_p();
			}
			bool						operator>(const_iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool						operator>=(const_iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool						operator<(const_iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool						operator<=(const_iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool						operator!=(const_iterator_type it) {
				return this->_pointer != it.get_p();
			}
		
		};
		class const_iterator {
			const t_treeElem<const Key, T>*				_pointer;
			const ft::map<Key, T, Compare, Allocator>*	_map_pointer;

		public:
			const_iterator():
				_pointer(NULL),
				_map_pointer(NULL)
			{}
			// iterator(ft::map<Key, T>* pointer):
			// 	_pointer(pointer)
			// {}
			const_iterator(t_treeElem<const Key, T>* pointer):
				_pointer(pointer),
				_map_pointer(NULL)
			{}
			const_iterator(t_treeElem<const Key, T>* pointer, ft::map<Key, T, Compare, Allocator>*	map_pointer):
				_pointer(pointer),
				_map_pointer(map_pointer)
			{}
			const_iterator(t_treeElem<const Key, T>* pointer, const ft::map<Key, T, Compare, Allocator>*	map_pointer):
				_pointer(pointer),
				_map_pointer(map_pointer)
			{}
			~const_iterator() {};

			typedef typename ft::map<Key, T>::const_iterator&					iterator_type;

			const t_treeElem<const Key, T>*	get_p() {
				return (_pointer);
			}
			const pair<Key, T>&				operator*(){
				return (_pointer->_kv);
			}
			iterator_type					operator=(t_treeElem<const Key, T>* pointer) {
				this->_pointer = pointer;
				return *this;
			}
			bool							operator==(iterator_type it) {
				return this->_pointer == it.get_p();
			}
			iterator_type					operator++(int) {
				//	1. check current position
				//	2. if have right
				//		2.1. rewrite _pointer to _right and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. check current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. rewrite _pointer to _parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. go to the parent
				//				3.1.3.2. while (1)
				//					3.1.3.2.1. if _parent == NUll ->						rewrite _pointer to null node and return
				//					3.1.3.2.2. if current positions it's right in parent ->	change curent position to parent continue
				//					3.1.3.2.3. if current positions it's left in parent ->	rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_right){
					_pointer = _map_pointer->search_min(_pointer->_right);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left != _pointer &&
							_pointer->_parent->_right != _pointer &&
							_map_pointer->search(_pointer->_kv.first) == NULL) {
								const_iterator	begin = _map_pointer->begin();
								const_iterator	end = _map_pointer->end();
								while (begin != end &&
										!_map_pointer->_compare(this->get_p()->_kv.first, begin->first)) {
									begin++;
								}
								// begin--;
								_pointer = begin.get_p();
								return *this;
							}
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
						} else {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									_pointer = _map_pointer->_n_node;
									break ;
								}
								if (_pointer->_parent->_right == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						}
					} else {
						_pointer = _map_pointer->_n_node;
					}
				}
				return *this;
			}
			iterator_type					operator--(int) {
				//	1. check current position
				//	2. if have _left
				//		2.1. rewrite _pointer to _left and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. if current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. go to the parent
				//				3.1.2.2. while (1)
				//					3.1.2.2.1. if _parent == NULL -> 	rewrite _pointer to null node and return
				//					3.1.2.2.2. if current position it's left ->	go to the parent and continue
				//					3.1.2.2.3. if current position it's right -> rewrite _pointer to parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_left){
					_pointer = _map_pointer->search_max(_pointer->_left);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left != _pointer &&
							_pointer->_parent->_right != _pointer &&
							_map_pointer->search(_pointer->_kv.first) == NULL) {
								const_iterator	begin = _map_pointer->begin();
								const_iterator	end = _map_pointer->end();
								while (begin != end &&
										!_map_pointer->_compare(this->get_p()->_kv.first, begin->first)) {
									begin++;
								}
								begin--;
								_pointer = begin.get_p();
								return *this;
							}
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									_pointer = _map_pointer->_nn_node;
									break ;
								}
								if (_pointer->_parent->_left == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						} else {
							_pointer = _pointer->_parent;
						}
					} else {
						_pointer = _map_pointer->_nn_node;
					}
				}
				return *this;
			}
			bool							operator>(iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool							operator>=(iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool							operator<(iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool							operator<=(iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool							operator!=(iterator_type it) {
				return this->_pointer != it.get_p();
			}
			const pair<const Key, T>*		operator->() {
				return (&_pointer->_kv);
			}
		
			typedef typename ft::map<Key, T>::iterator&		const_iterator_type;

			bool						operator==(const_iterator_type it) {
				return this->_pointer == it.get_p();
			}
			bool						operator>(const_iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool						operator>=(const_iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool						operator<(const_iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool						operator<=(const_iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool						operator!=(const_iterator_type it) {
				return this->_pointer != it.get_p();
			}
		};
		class reverse_iterator {
			t_treeElem<const Key, T>*						_pointer;
			ft::map<Key, T, Compare, Allocator>*	_map_pointer;

		public:
			reverse_iterator():
				_pointer(NULL),
				_map_pointer(NULL)
			{}
			// iterator(ft::map<Key, T>* pointer):
			// 	_pointer(pointer)
			// {}
			reverse_iterator(t_treeElem<const Key, T>* pointer):
				_pointer(pointer),
				_map_pointer(NULL)
			{}
			reverse_iterator(t_treeElem<const Key, T>* pointer, ft::map<Key, T, Compare, Allocator>*	map_pointer):
				_pointer(pointer),
				_map_pointer(map_pointer)
			{}
			~reverse_iterator() {};

			typedef typename ft::map<Key, T>::reverse_iterator&	iterator_type;

			t_treeElem<const Key, T>*	get_p() {
				return (_pointer);
			}
			pair<const Key, T>&			operator*(){
				return (_pointer->_kv);
			}
			iterator_type				operator=(t_treeElem<const Key, T>* pointer) {
				this->_pointer = pointer;
				return *this;
			}
			bool						operator==(iterator_type it) {
				return this->_pointer == it.get_p();
			}
			iterator_type				operator--(int) {
				//	1. check current position
				//	2. if have right
				//		2.1. rewrite _pointer to _right and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. check current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. rewrite _pointer to _parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. go to the parent
				//				3.1.3.2. while (1)
				//					3.1.3.2.1. if _parent == NUll ->						rewrite _pointer to null node and return
				//					3.1.3.2.2. if current positions it's right in parent ->	change curent position to parent continue
				//					3.1.3.2.3. if current positions it's left in parent ->	rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_right){
					_pointer = _map_pointer->search_min(_pointer->_right);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left != _pointer &&
							_pointer->_parent->_right != _pointer &&
							_map_pointer->search(_pointer->_kv.first) == NULL) {
								iterator	begin = _map_pointer->begin();
								iterator	end = _map_pointer->end();
								while (begin != end &&
										!_map_pointer->_compare(this->get_p()->_kv.first, begin->first)) {
									begin++;
								}
								// begin--;
								_pointer = begin.get_p();
								return *this;
							}
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
						} else {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									_pointer = _map_pointer->_rnn_node;
									break ;
								}
								if (_pointer->_parent->_right == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						}
					} else {
						_pointer = _map_pointer->_rnn_node;
					}
				}
				return *this;
			}
			iterator_type				operator++(int) {
				//	1. check current position
				//	2. if have _left
				//		2.1. rewrite _pointer to _left and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. if current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. go to the parent
				//				3.1.2.2. while (1)
				//					3.1.2.2.1. if _parent == NULL -> 	rewrite _pointer to null node and return
				//					3.1.2.2.2. if current position it's left ->	go to the parent and continue
				//					3.1.2.2.3. if current position it's right -> rewrite _pointer to parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_left){
					_pointer = _map_pointer->search_max(_pointer->_left);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left != _pointer &&
							_pointer->_parent->_right != _pointer &&
							_map_pointer->search(_pointer->_kv.first) == NULL) {
								iterator	begin = _map_pointer->begin();
								iterator	end = _map_pointer->end();
								while (begin != end &&
										!_map_pointer->_compare(this->get_p()->_kv.first, begin->first)) {
									begin++;
								}
								begin--;
								_pointer = begin.get_p();
								return *this;
							}
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									_pointer = _map_pointer->_rn_node;
									break ;
								}
								if (_pointer->_parent->_left == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						} else {
							_pointer = _pointer->_parent;
						}
					} else {
						_pointer = _map_pointer->_rn_node;
					}
				}
				return *this;
			}
			bool						operator>(iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool						operator>=(iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool						operator<(iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool						operator<=(iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool						operator!=(iterator_type it) {
				return this->_pointer != it.get_p();
			}
			pair<const Key, T>*			operator->() {
				return (&_pointer->_kv);
			}
			operator const_reverse_iterator(){
				return const_reverse_iterator(_pointer, _map_pointer);
			}
			
			typedef typename ft::map<Key, T>::const_reverse_iterator&	const_iterator_type;

			bool						operator==(const_iterator_type it) {
				return this->_pointer == it.get_p();
			}
			bool						operator>(const_iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool						operator>=(const_iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool						operator<(const_iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool						operator<=(const_iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool						operator!=(const_iterator_type it) {
				return this->_pointer != it.get_p();
			}
		};
		class const_reverse_iterator {
			const t_treeElem<const Key, T>*						_pointer;
			const ft::map<Key, T, Compare, Allocator>*	_map_pointer;

		public:
			const_reverse_iterator():
				_pointer(NULL),
				_map_pointer(NULL)
			{}
			// iterator(ft::map<Key, T>* pointer):
			// 	_pointer(pointer)
			// {}
			const_reverse_iterator(t_treeElem<const Key, T>* pointer):
				_pointer(pointer),
				_map_pointer(NULL)
			{}
			const_reverse_iterator(t_treeElem<const Key, T>* pointer, ft::map<Key, T, Compare, Allocator>*	map_pointer):
				_pointer(pointer),
				_map_pointer(map_pointer)
			{}
			~const_reverse_iterator() {};

			typedef typename ft::map<Key, T>::const_reverse_iterator&	iterator_type;

			const t_treeElem<const Key, T>*	get_p() {
				return (_pointer);
			}
			const pair<const Key, T>&				operator*(){
				return (_pointer->_kv);
			}
			iterator_type			operator=(t_treeElem<const Key, T>* pointer) {
				this->_pointer = pointer;
				return *this;
			}
			bool					operator==(iterator_type it) {
				return this->_pointer == it.get_p();
			}
			iterator_type			operator--(int) {
				//	1. check current position
				//	2. if have right
				//		2.1. rewrite _pointer to _right and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. check current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. rewrite _pointer to _parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. go to the parent
				//				3.1.3.2. while (1)
				//					3.1.3.2.1. if _parent == NUll ->						rewrite _pointer to null node and return
				//					3.1.3.2.2. if current positions it's right in parent ->	change curent position to parent continue
				//					3.1.3.2.3. if current positions it's left in parent ->	rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_right){
					_pointer = _map_pointer->search_min(_pointer->_right);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left != _pointer &&
							_pointer->_parent->_right != _pointer &&
							_map_pointer->search(_pointer->_kv.first) == NULL) {
								const_iterator	begin = _map_pointer->begin();
								const_iterator	end = _map_pointer->end();
								while (begin != end &&
										!_map_pointer->_compare(this->get_p()->_kv.first, begin->first)) {
									begin++;
								}
								// begin--;
								_pointer = begin.get_p();
								return *this;
							}
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
						} else {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									_pointer = _map_pointer->_rnn_node;
									break ;
								}
								if (_pointer->_parent->_right == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						}
					} else {
						_pointer = _map_pointer->_rnn_node;
					}
				}
				return *this;
			}
			iterator_type			operator++(int) {
				//	1. check current position
				//	2. if have _left
				//		2.1. rewrite _pointer to _left and return
				//	3. else
				//		3.1. if have parent
				//			3.1.1. if current positions for this left or right in parent
				//			3.1.2. if this left
				//				3.1.2.1. go to the parent
				//				3.1.2.2. while (1)
				//					3.1.2.2.1. if _parent == NULL -> 	rewrite _pointer to null node and return
				//					3.1.2.2.2. if current position it's left ->	go to the parent and continue
				//					3.1.2.2.3. if current position it's right -> rewrite _pointer to parent and return
				//			3.1.3. else - this right
				//				3.1.3.1. rewrite _pointer to _parent and return
				//		3.2. else
				//			3.2.1. rewrite _pointer to null node and return
				if (_pointer->_left){
					_pointer = _map_pointer->search_max(_pointer->_left);
				} else {
					if (_pointer->_parent){
						if (_pointer->_parent->_left != _pointer &&
							_pointer->_parent->_right != _pointer &&
							_map_pointer->search(_pointer->_kv.first) == NULL) {
								const_iterator	begin = _map_pointer->begin();
								const_iterator	end = _map_pointer->end();
								while (begin != end &&
										!_map_pointer->_compare(this->get_p()->_kv.first, begin->first)) {
									begin++;
								}
								begin--;
								_pointer = begin.get_p();
								return *this;
							}
						if (_pointer->_parent->_left == _pointer) {
							_pointer = _pointer->_parent;
							while (1) {
								if (_pointer->_parent == NULL) {
									_pointer = _map_pointer->_rn_node;
									break ;
								}
								if (_pointer->_parent->_left == _pointer) {
									_pointer = _pointer->_parent;
									continue ;
								} else {
									_pointer = _pointer->_parent;
									break ;
								}
							}
						} else {
							_pointer = _pointer->_parent;
						}
					} else {
						_pointer = _map_pointer->_rn_node;
					}
				}
				return *this;
			}
			bool					operator>(iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool					operator>=(iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool					operator<(iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool					operator<=(iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool					operator!=(iterator_type it) {
				return this->_pointer != it.get_p();
			}
			const pair<const Key, T>*			operator->() {
				return (&_pointer->_kv);
			}
			
			typedef typename ft::map<Key, T>::reverse_iterator&	const_iterator_type;

			bool						operator==(const_iterator_type it) {
				return this->_pointer == it.get_p();
			}
			bool						operator>(const_iterator_type it) {
				return this->_pointer > it.get_p();
			}
			bool						operator>=(const_iterator_type it) {
				return this->_pointer >= it.get_p();
			}
			bool						operator<(const_iterator_type it) {
				return this->_pointer < it.get_p();
			}
			bool						operator<=(const_iterator_type it) {
				return this->_pointer <= it.get_p();
			}
			bool						operator!=(const_iterator_type it) {
				return this->_pointer != it.get_p();
			}
		};

		class value_compare{
		friend class map;
			Compare		comp;
			value_compare(Compare c):
				comp(c)
			{}

		public:
			bool operator() (const pair<const Key, T>& x, const pair<const Key, T>& y) const {
				return comp(x.first, y.first);
			};
		};

		typedef typename ft::map<Key, T>::iterator			iterator_type;
		typedef typename ft::map<Key, T>::const_iterator	const_iterator_type;

		explicit map (const key_compare& comp = Compare(), const allocator_type& alloc = Allocator()):
			_tree(NULL),
			_compare(comp),
			_al(alloc),
			_size(0),
			_n_node(NULL),
			_nn_node(NULL),
			_rn_node(NULL),
			_rnn_node(NULL),
			_copy_flag(0)
		{
			_n_node = _al.allocate(1);
			_al.construct(_n_node, search_max(_tree));

			_rn_node = _al.allocate(1);
			_al.construct(_rn_node, search_min(_tree));

			_nn_node = _al.allocate(1);
			_al.construct(_nn_node);

			_rnn_node = _al.allocate(1);
			_al.construct(_rnn_node);
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()):
				_tree(NULL),
				_compare(comp),
				_al(alloc),
				_size(0),
				_copy_flag(0)
			{
				_n_node = _al.allocate(1);
				_al.construct(_n_node, search_max(_tree));

				_rn_node = _al.allocate(1);
				_al.construct(_rn_node, search_min(_tree));

				_nn_node = _al.allocate(1);
				_al.construct(_nn_node);

				_rnn_node = _al.allocate(1);
				_al.construct(_rnn_node);

				while (first != last){
					pair<Key, T> f(first->first, first->second);
					insert(f);
					first++;
				}
			}
		map (const map& x):
			_tree(NULL),
			_compare(x._compare),
			_al(x._al),
			_size(0),
			_copy_flag(0)
		{
			clear();

			_n_node = _al.allocate(1);
			_al.construct(_n_node, search_max(_tree));

			_rn_node = _al.allocate(1);
			_al.construct(_rn_node, search_min(_tree));

			_nn_node = _al.allocate(1);
			_al.construct(_nn_node);

			_rnn_node = _al.allocate(1);
			_al.construct(_rnn_node);
			
			fast_iterator	begin = x.fast_begin();
			fast_iterator	end = x.fast_end();

			_copy_flag = 1;
			insert(begin, end);
			_copy_flag = 0;

			// while (begin != end && x.size() != 0){
			// 	// pair<Key, T> f(begin->first, begin->second);
			// 	insert((begin.get_p())->_kv);
			// 	// std::cout << " first  = " << begin->first << std::endl;
			// 	begin++;
			// }
		}
		~map(){
			//	1. if left == null
			//		1.1 if right == null
			//			1.1.1. free
			//			1.1.2. go parent
			//		1.2 else
			//			1.2.1. go right
			//	2. else
			//		2.1. go left
			std::cout << "Destructor map start" << std::endl;
			t_treeElem<const Key, T>*		_this = _tree;
			t_treeElem<const Key, T>*		_parent = _tree;
			while (1) {
				if (_parent == NULL)
					break ;
				if (_this->_left == NULL) {
					if (_this->_right == NULL) {
						_parent = _this->_parent;
						_al.destroy(_this);
						_al.deallocate(_this, sizeof(t_treeElem<const Key, T>));
						_this = _parent;
						if (_this && !_this->_left)
							_this->_right = NULL;
						else if (_this)
							_this->_left = NULL;
						continue;
					} else {
						_parent = _this;
						_this = _this->_right;
						continue;
					}
				} else {
					_parent = _this;
					_this = _this->_left;
					continue ;
				}
			}
			if (_n_node) {
				_al.destroy(_n_node);
				_al.deallocate(_n_node, sizeof(t_treeElem<const Key, T>));
			}
			if (_nn_node) {
				_al.destroy(_nn_node);
				_al.deallocate(_nn_node, sizeof(t_treeElem<const Key, T>));
			}
			if (_rn_node) {
				_al.destroy(_rn_node);
				_al.deallocate(_rn_node, sizeof(t_treeElem<const Key, T>));
			}
			if (_rnn_node) {
				_al.destroy(_rnn_node);
				_al.deallocate(_rnn_node, sizeof(t_treeElem<const Key, T>));
			}
		}
		map& operator=( const map& other ){
			// std::cout << "start" << std::endl;
			if (&other != this){
				clear();
				_compare = other.key_comp();
				_al = other.get_allocator();
				const_iterator	begin = other.begin();
				const_iterator	end = other.end();
				while (begin != end && other.size() != 0){
					pair<Key, T> f(begin->first, begin->second);
					insert(f);
					// std::cout << " first  = " << begin->first << std::endl;
					begin++;
				}
				updateNullNodes();
			}
			return *this;
		}

	private:
		t_treeElem<const Key, T>*		search(Key key) const {
			// Search Key in tree
			// while (1)
			//		1. if key == node_key
			//			1.1. return true + pointer
			//		2. else if pointer == NULL
			//			2.1. return false + NULL
			//		3. else
			//			3.1. if key < node_key
			//				3.1.1. pointer = left
			//				3.1.2. continue
			//			3.2. else (key > node_key)
			//				3.2.1. pointer = right
			//				3.2.2. continue
			t_treeElem<const Key, T>*		pointer = _tree;
			while (1) {
				if (pointer && !_compare(pointer->_kv.first, key) &&
					!_compare(key, pointer->_kv.first))
						return pointer;
				else if (pointer == NULL)
					return NULL;
				else {
					if (_compare(key, pointer->_kv.first)) {
						pointer = pointer->_left;
						continue ;
					} else {
						pointer = pointer->_right;
						continue ;
					}
				}
			}
		}
		void							balance(t_treeElem<const Key, T>* p) {
			//	1. if _k < 0
			//		1.1. go left
			//		1.2. if _k < 0
			//			1.2.1. start left rotate
			//		1.3. else
			//			1.3.1. sart left-right rotate
			//	2. else
			//		2.1. go right
			//		2.2. if _k < 0
			//			2.2.1. start right-left rotate
			//		2.3. else
			//			2.3.1. start right rotate

			t_treeElem<const Key, T>*		temp = NULL;
			// if (p->_k < 0){
			if ((((p->_right) ? p->_right->_k + 1 : 0) - ((p->_left) ? p->_left->_k + 1 : 0)) < 0){
				temp = p->_left;
				// if (temp->_k < 0){
				if ((((temp->_right) ? temp->_right->_k + 1 : 0) - ((temp->_left) ? temp->_left->_k + 1 : 0)) < 0){
					temp->_parent = p->_parent;
					if (temp->_right)
						temp->_right->_parent = p;
					p->_left = temp->_right;
					temp->_right = p;
					if (p->_parent && p->_parent->_left == p)
						p->_parent->_left = temp;
					else if (p->_parent)
						p->_parent->_right = temp;
					if (p->_parent == NULL)
						_tree = temp;
					p->_parent = temp;
				} else {
					t_treeElem<const Key, T>*	temp_1 = temp->_right;
					p->_left = temp_1;
					temp->_parent = temp_1;
					temp->_right = temp_1->_left;
					temp_1->_parent = p;
					if (temp_1->_left)
						temp_1->_left->_parent = temp;
					temp_1->_left = temp;
					if (p->_parent && p->_parent->_left == p)
						p->_parent->_left = temp_1;
					else if (p->_parent)
						p->_parent->_right = temp_1;
					if (p->_parent == NULL)
						_tree = temp_1;
					temp_1->_parent = p->_parent;
					p->_parent = temp_1;
					p->_left = temp_1->_right;
					if (temp_1->_right)
						temp_1->_right->_parent = p;
					temp_1->_right = p;
				}
			} else {
				temp = p->_right;
				// if (temp->_k > 0){
				if ((((temp->_right) ? temp->_right->_k + 1 : 0) - ((temp->_left) ? temp->_left->_k + 1 : 0)) > 0){
					if(p->_parent && p->_parent->_left == p)
						p->_parent->_left = temp;
					else if (p->_parent)
						p->_parent->_right = temp;
					if (p->_parent == NULL)
						_tree = temp;
					temp->_parent = p->_parent;
					p->_parent = temp;
					p->_right = temp->_left;
					if (temp->_left)
						temp->_left->_parent = p;
					temp->_left = p;
				} else {
					t_treeElem<const Key, T>*	temp_1 = temp->_left;
					if (!temp_1){
						rewrite_k(temp);
						return ;
					}
					p->_right = temp_1;
					temp->_parent = temp_1;
					temp->_left = temp_1->_right;
					temp_1->_parent = p;
					if (temp_1->_right)
						temp_1->_right->_parent = temp;
					temp_1->_right = temp;
					if (p->_parent && p->_parent->_left == p)
						p->_parent->_left = temp_1;
					else if (p->_parent)
						p->_parent->_right = temp_1;
					if (p->_parent == NULL)
						_tree = temp_1;
					temp_1->_parent = p->_parent;
					p->_parent = temp_1;
					p->_right = temp_1->_left;
					if (temp_1->_left)
						temp_1->_left->_parent = p;
					temp_1->_left = p;
				}
			}
		}
		t_treeElem<const Key, T>*		search_max(t_treeElem<const Key, T>* p) const {
			if (!p)
				return p;
			while (1) {
				if (p->_right) {
					p = p->_right;
					continue ;
				} else
					break ;
			}
			return p;
		}
		t_treeElem<const Key, T>*		search_min(t_treeElem<const Key, T>* p) const {
			if (!p)
				return p;
			while (1) {
				if (p->_left) {
					p = p->_left;
					continue ;
				} else {
					break ;
				}
			}
			return p;
		}
		int								depth(t_treeElem<const Key, T>* p) const {
			if (p == NULL)
				return 0;
			int ret = ft::max(((p->_left) ? 1 + depth(p->_left) : 0),
						((p->_right) ? 1 + depth(p->_right) : 0));
			return ret;
		}
		void							rewrite_k(t_treeElem<const Key, T>* p) {
			while (1) {
				if (p == NULL)
					break ;
				// p->_k = ((p->_right) ? depth(p->_right) + 1 : 0) - ((p->_left) ? depth(p->_left) + 1 : 0);
				p->_k = ft::max(((p->_right) ? p->_right->_k + 1 : 0),
						((p->_left) ? p->_left->_k + 1 : 0));
				// if (abs(p->_k) > 1 && !_copy_flag){
				if (abs(((p->_right) ? p->_right->_k + 1 : 0) - ((p->_left) ? p->_left->_k + 1 : 0)) > 1 && !_copy_flag){
					balance(p);
					continue ;
				} else
					p = p->_parent;
			}
		}
		void							updateNullNodes() {
			_n_node->_parent = search_max(_tree);
			_rn_node->_parent = search_min(_tree);
		}

	public:
		// Element access
		T&								at( const Key& key ){
			t_treeElem<const Key, T>*	ret = search(key);
			if (!ret)
				throw std::out_of_range("key not found");
			return (ret->_kv.second);
		}
		const T&						at( const Key& key ) const{
			t_treeElem<const Key, T>*	ret = search(key);
			if (!ret)
				throw std::out_of_range("key not found");
			return (ret->_kv.second);
		}
		T&								operator[]( const Key& key ){
			t_treeElem<const Key, T>*	ret = search(key);
			if (!ret){
				pair<Key, T>			in(key);
				pair<iterator, bool>	tmp = insert(in);
				T*						ret = &(tmp.first->second);
				// std::cout << "T = " << *ret << std::endl;
				return *ret;
				// return (insert(in).first)->second;
			}
			return ret->_kv.second;
		}

		// Modifiers:
		pair<iterator, bool>			insert( const pair<const Key, T>& value ){
			// Search this Key in tree and add if not found
			t_treeElem<const Key, T>*	 pp = search(value.first);
			if (pp) {
				iterator_type it(pp, this);
				pair<iterator_type, bool> ret(it, false);
				return ret;
			}
			// If tree is free
			if (!_size) {
				_tree = _al.allocate(1);				// allocate memory for 1 element
				_al.construct(_tree, value);			// construct element
				rewrite_k(_tree);
				_size++;								// ++ size tree
				updateNullNodes();
				iterator_type it(_tree, this);
				pair<iterator_type, bool> ret(it, true);
				return ret;
			} else {
				// If tree is non free
				// 1. Check compare iterator and key insert element
				// 2. If true
				//		2.1. Check for left elem
				//		2.2. If have
				//			2.2.1. Change iterator
				//			2.2.2. Continue
				//		2.3. Else
				//			2.3.1. Allocate memory
				//			2.3.2. Construct elem
				//			2.3.3. Add size
				// 3. else
				//		3.1. Check for left elem
				//		3.2. If have
				//			3.2.1. Change iterator
				//			3.2.2. Continue
				//		3.3. Else
				//			3.3.1. Allocate memory
				//			3.3.2. Construct elem
				//			3.3.3. Add size
				iterator_type it(_tree, this);
				while (1) {
					if (_compare(value.first, it->first)) {
						if ((it.get_p())->_left != NULL){
							it = (it.get_p())->_left;
							continue ;
						} else {
							(it.get_p())->_left = _al.allocate(1);					// allocate memory for 1 element
							_al.construct((it.get_p())->_left, value, it.get_p());	// construct element
							rewrite_k((it.get_p())->_left);
							_size++;										// ++ size tree
							updateNullNodes();
							return ft::make_pair(iterator(search(value.first), this), true);
							// iterator_type it2((it.get_p())->_left, this);
							// pair<iterator_type, bool> ret(it2, true);
							// return ret;
						}
					} else {//if (_compare(it->first, value.first)) {
						if ((it.get_p())->_right != NULL){
							it = (it.get_p())->_right;
							continue ;
						} else {
							(it.get_p())->_right = _al.allocate(1);					// allocate memory for 1 element
							_al.construct((it.get_p())->_right, value, it.get_p());	// construct element
							rewrite_k((it.get_p())->_right);
							_size++;										// ++ size tree
							updateNullNodes();
							return ft::make_pair(iterator(search(value.first), this), true);
							// iterator_type it2((it.get_p())->_right, this);
							// pair<iterator_type, bool> ret(it2, true);
							// return ret;
						}
					} //else {
					// 	pair<iterator_type, bool> ret(it, false);
					// 	return ret;
					// }
				}
			}
		}
		iterator						insert( iterator hint, const pair<const Key, T>& value ){
			// 1. Search this Key
			// 2. If tree is free
			// 3. Check current hint iterator for left and right elems and conpare
			// 4. If have fine positions
			//	4.1. Add elem in this positions
			// 5. else
			//	5.1. Add elem with insert func
			t_treeElem<const Key, T>*	 pp = search(value.first);
			if (pp) {
				iterator_type it(pp, this);
				return it;
			}
			if (!_size) {
				_tree = _al.allocate(1);				// allocate memory for 1 element
				_al.construct(_tree, value);			// construct element
				rewrite_k(_tree);
				_size++;								// ++ size tree
				iterator_type it(_tree, this);
				updateNullNodes();
				return it;
			} else {
				if (hint.get_p()->_left == NULL && _compare(value.first, hint->first)){
					hint.get_p()->_left = _al.allocate(1);
					_al.construct(hint.get_p()->_left, value, hint.get_p());
					rewrite_k(hint.get_p()->_left);
					_size++;
					iterator_type it(hint.get_p()->_left, this);
					updateNullNodes();
					return it;
				} else if (hint.get_p()->_right == NULL && _compare(hint->first, value.first)) {
					hint.get_p()->_right = _al.allocate(1);
					_al.construct(hint.get_p()->_right, value, hint.get_p());
					rewrite_k(hint.get_p()->_right);
					_size++;
					iterator_type it(hint.get_p()->_right, this);
					updateNullNodes();
					return it;
				} else {
					return (insert(value)).first ;
				}
			}
		}
		template< class InputIt >
		void							insert( InputIt first, InputIt last ){
			ft::vector<pair<const Key, T> > tmp;
			while (first != last){
				tmp.push_back((first.get_p())->_kv);
				// insert((first.get_p())->_kv);
				// std::cout << "Size = " << first->first << std::endl;
				first++;
				// if (tmp.size() > 12000)
				// 	break;
			}
			for (size_t i = 0; i < tmp.size(); ++i){
				insert(tmp.at(i));
				// tmp.pop();
				// std::cout << "Size 2 = " << _size << std::endl;
			}
		}
		void							erase( iterator position ){
			// 1. if only one elem in tree
			//		1.1. destructor
			//		1.2. deallocate memory
			//		1.3. size--
			// 2. else
			//		2.1. have child
			//			2.1.1. have left and right
			//				2.1.1.1. compare left _k and right _k
			//				2.1.1.2. search max or min elements
			//				2.1.1.3. have child elements
			//					2.1.1.3.1. rewrite child parent pointer
			//					2.1.1.3.2. rewrite parent child pointer
			//					2.1.1.3.3. rewrite new position pointers (child, parent)
			//					2.1.1.3.4. rewrite _k from parent max/min element
			//					2.1.1.3.5. destructor
			//					2.1.1.3.6. deallocate memory
			//					2.1.1.3.7. size--
			//				2.1.1.4. else
			//					2.1.1.4.1. rewrite parent pointers
			//					2.1.1.4.2. rewrite new position pointers (child, parent)
			//					2.1.1.4.3. rewrite _k from parent max/min element
			//					2.1.1.4.4. destructor
			//					2.1.1.4.5. deallocate memory
			//					2.1.1.4.6. size--
			//			2.1.2. have left or right only
			//				2.1.2.1. rewrite child parent pointer
			//				2.1.2.2. rewrite parent child pointer
			//				2.1.2.3. rewrite _k from parent
			//				2.1.2.4. destructor
			//				2.1.2.5. deallocate memory
			//				2.1.2.6. size--
			//		2.2. don't have child
			//			2.2.1. rewrite parent pointer
			//			2.2.2. rewrite _k and rebalanse
			//			2.2.3. destructor
			//			2.2.4. deallocate memory
			//			2.2.5. size--

			if (_size == 1) {
				_al.destroy(position.get_p());
				_al.deallocate(position.get_p(), sizeof(t_treeElem<const Key, T>));
				_size--;
				_tree = NULL;
				updateNullNodes();
				return ;
			} else {
				t_treeElem<const Key, T>*		left = NULL;
				t_treeElem<const Key, T>*		right = NULL;
				t_treeElem<const Key, T>*		parent = NULL;
				t_treeElem<const Key, T>*		new_this = NULL;
				t_treeElem<const Key, T>*		temp = NULL;
				if ((position.get_p())->_left || (position.get_p())->_right){
					if ((position.get_p())->_left && (position.get_p())->_right){
						int l = 0;
						int r = 0;
						if (abs((position.get_p())->_left->_k) >= abs((position.get_p())->_right->_k)){
							new_this = search_max((position.get_p())->_left);
							l++;
						} else {
							new_this = search_min((position.get_p())->_right);
							r++;
						}
						left = (position.get_p())->_left;
						right = (position.get_p())->_right;
						parent = (position.get_p())->_parent;
						if (new_this->_left || new_this->_right){
							if (l){
								if (new_this->_parent->_left != new_this)
									new_this->_parent->_right = new_this->_left;
								if (new_this->_left && new_this->_parent != position.get_p())
									new_this->_left->_parent = new_this->_parent;
							} else {
								if (new_this->_parent->_right != new_this)
									new_this->_parent->_left = new_this->_right;
								if (new_this->_right && new_this->_parent != position.get_p())
									new_this->_right->_parent = new_this->_parent;
							}
							temp = (new_this->_left) ? new_this->_left : new_this->_right;
						} else {
							if (new_this->_parent->_left == new_this)
								new_this->_parent->_left = NULL;
							else
								new_this->_parent->_right = NULL;
							temp = new_this;
						}
						// temp = new_this->_parent;
						new_this->_parent = parent;
						
						if (parent && parent->_left == (position.get_p()))
							parent->_left = new_this;
						else if (parent && parent->_right == (position.get_p()))
							parent->_right = new_this;
						if (!parent)
							_tree = new_this;

						if (new_this != left)
							new_this->_left = left;
						// else
						// 	new_this->_left = NULL;

						if (left && left != new_this)
							left->_parent = new_this;

						if (new_this != right)
							new_this->_right = right;
						// else
						// 	new_this->_right = NULL;
						
						if (right && right != new_this)
							right->_parent = new_this;
						rewrite_k(temp);
						_al.destroy(position.get_p());
						_al.deallocate(position.get_p(), sizeof(t_treeElem<const Key, T>));
						_size--;
						updateNullNodes();
						return ;
					} else if ((position.get_p())->_left) {
						if ((position.get_p())->_parent){
							if ((position.get_p())->_parent->_left == position.get_p())
								(position.get_p())->_parent->_left = (position.get_p())->_left;
							else
								(position.get_p())->_parent->_right = (position.get_p())->_left;
						} else {
							_tree = (position.get_p())->_left;
							_tree->_parent = NULL;
						}
						rewrite_k((position.get_p())->_left);
						_al.destroy(position.get_p());
						_al.deallocate(position.get_p(), sizeof(t_treeElem<const Key, T>));
						_size--;
						updateNullNodes();
						return ;
					} else {
						if ((position.get_p())->_parent){
							if ((position.get_p())->_parent->_left == position.get_p())
								(position.get_p())->_parent->_left = (position.get_p())->_right;
							else
								(position.get_p())->_parent->_right = (position.get_p())->_right;
						} else {
							_tree = (position.get_p())->_right;
							_tree->_parent = NULL;
						}
						rewrite_k((position.get_p())->_right);
						_al.destroy(position.get_p());
						_al.deallocate(position.get_p(), sizeof(t_treeElem<const Key, T>));
						_size--;
						updateNullNodes();
						return ;
					}
				} else {
					if ((position.get_p())->_parent->_left == position.get_p())
						(position.get_p())->_parent->_left = NULL;
					else
						(position.get_p())->_parent->_right = NULL;
					rewrite_k(position.get_p()->_parent);
					_al.destroy(position.get_p());
					_al.deallocate(position.get_p(), sizeof(t_treeElem<const Key, T>));
					_size--;
					updateNullNodes();
					return ;
				}
			}

		}
		void							erase( iterator first, iterator last ){
			iterator		tmp = first;
			while (first != last){
				tmp++;
				erase(first);
				first = tmp;
			}
			updateNullNodes();
		}
		size_t							erase( const Key& key ){
			t_treeElem<const Key, T>* pp = search(key);
			if (!pp)
				return 0;
			iterator_type p(pp, this);
			erase(pp);
			return 1;
		}
		void							swap( map& other ){
			t_treeElem<const Key, T>*	temp_1 = other._tree;
			other._tree = _tree;
			_tree = temp_1;

			size_t	temp = other._size;
			other._size = _size;
			_size = temp;

			temp_1 = other._n_node;
			other._n_node = _n_node;
			_n_node = temp_1;

			temp_1 = other._nn_node;
			other._nn_node = _nn_node;
			_nn_node = temp_1;

			temp_1 = other._rn_node;
			other._rn_node = _rn_node;
			_rn_node = temp_1;

			temp_1 = other._rnn_node;
			other._rnn_node = _rnn_node;
			_rnn_node = temp_1;
		}
		void							clear(){
			if (_size == 0)
				return ;
			iterator		begin = this->begin();
			iterator		end = this->end();
			while (begin != end && _size != 0){
				erase(begin);
				begin++;
			}
			_tree = NULL;
		}
		// void							less() {
		// 	std::cout << _compare(_tree->_key, _tree->_value) << std::endl;
		// }

		// Capacity:
		bool							empty() const {
			return (_size) ? false : true;
		}
		size_t							size() const {
			return _size;
		}
		size_t							max_size() const {
			long a = sysconf(_SC_PHYS_PAGES);
			long b = sysconf(_SC_PAGESIZE);
			long c = a * b;
			return static_cast<size_t>(c / sizeof(t_treeElem<const Key, T>));
		}

		// Observers:
		key_compare						key_comp() const{
			return _compare;
		}
		value_compare					value_comp() const{
			return value_compare(_compare);
		}

		// Operations:
		iterator						find( const Key& key ){
			t_treeElem<const Key, T>* pp = search(key);
			if (!pp)
				return end();
			iterator_type ff(pp, this);
			return ff;
		}
		const_iterator					find( const Key& key ) const{
			t_treeElem<const Key, T>* pp = search(key);
			if (!pp)
				return end();
			const_iterator_type ff(pp, this);
			return ff;
		}
		size_t							count( const Key& key ) const{
			t_treeElem<const Key, T>* pp = search(key);
			if (!pp)
				return 0;
			return 1;
		}
		iterator						lower_bound( const Key& key ){
			iterator	begin = this->begin();
			iterator	end = this->end();
			while(begin != end && _compare(begin->first, key))
				begin++;
			return begin;
		}
		const_iterator					lower_bound( const Key& key ) const{
			const_iterator	begin = this->begin();
			const_iterator	end = this->end();
			while(begin != end && _compare(begin->first, key))
				begin++;
			return begin;
		}
		iterator						upper_bound( const Key& key ){
			iterator	begin = this->begin();
			iterator	end = this->end();
			while(begin != end && _compare(begin->first, key))
				begin++;
			(begin == end) ? begin : begin++;
			return begin;
		}
		const_iterator					upper_bound( const Key& key ) const{
			const_iterator	begin = this->begin();
			const_iterator	end = this->end();
			while(begin != end && _compare(begin->first, key))
				begin++;
			(begin == end) ? begin : begin++;
			return begin;
		}
		pair<iterator,iterator>				equal_range( const Key& key ){
			iterator f_1 = lower_bound(key);
			iterator f_2 = upper_bound(key);
			pair<iterator_type, iterator_type> pp(f_1, f_2);
			return pp;
		}
		pair<const_iterator,const_iterator>	equal_range( const Key& key ) const{
			const_iterator f_1 = lower_bound(key);
			const_iterator f_2 = upper_bound(key);
			pair<const_iterator_type, const_iterator_type> pp(f_1, f_2);
			return pp;
		}

		// Allocator:
		Allocator						get_allocator() const{
			return _al;
		}

	private:
		fast_iterator					fast_begin() const{
			return fast_iterator(_tree, this);
		}
		fast_iterator					fast_end() const{
			return fast_iterator(_nn_node, this);
		}

	public:
		// Iterators:
		iterator						begin(){
			return iterator(search_min(_tree), this);
		}
		const_iterator					begin() const {
			return const_iterator(search_min(_tree), this);
		}
		iterator						end(){
			return iterator(_n_node, this);
		}
		const_iterator					end() const {
			return const_iterator(_n_node, this);
		}
		reverse_iterator				rbegin(){
			return reverse_iterator(search_max(_tree), this);
		}
		const_reverse_iterator			rbegin() const{
			return const_reverse_iterator(search_max(_tree), this);
		}
		reverse_iterator				rend(){
			return reverse_iterator(_rn_node, this);
		}
		const_reverse_iterator			rend() const{
			return const_reverse_iterator(_rnn_node, this);
		}
	
		template <class _Key, class _T, class _Compare, class _Allocator>
		friend bool operator==( map<_Key, _T, _Compare, _Allocator>& lhs, map<_Key, _T, _Compare, _Allocator>& rhs );

		template <class _Key, class _T, class _Compare, class _Allocator>
		friend bool operator!=( map<_Key, _T, _Compare, _Allocator>& lhs, map<_Key, _T, _Compare, _Allocator>& rhs );

		template <class _Key, class _T, class _Compare, class _Allocator>
		friend bool operator<( map<_Key, _T, _Compare, _Allocator>& lhs, map<_Key, _T, _Compare, _Allocator>& rhs );

		template <class _Key, class _T, class _Compare, class _Allocator>
		friend bool operator<=( map<_Key, _T, _Compare, _Allocator>& lhs, map<_Key, _T, _Compare, _Allocator>& rhs );

		template <class _Key, class _T, class _Compare, class _Allocator>
		friend bool operator>( map<_Key, _T, _Compare, _Allocator>& lhs, map<_Key, _T, _Compare, _Allocator>& rhs );

		template <class _Key, class _T, class _Compare, class _Allocator>
		friend bool operator>=( map<_Key, _T, _Compare, _Allocator>& lhs, map<_Key, _T, _Compare, _Allocator>& rhs );
	};

	template <class Key, class T, class Compare, class Allocator>
	bool operator==( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs._tree == rhs._tree);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs._tree != rhs._tree);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator<( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs._tree < rhs._tree);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs._tree <= rhs._tree);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs._tree > rhs._tree);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator>=( map<Key, T, Compare, Allocator>& lhs, map<Key, T, Compare, Allocator>& rhs ){
		return (lhs._tree >= rhs._tree);
	}
}