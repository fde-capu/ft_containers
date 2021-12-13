/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:53:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/13 17:54:40 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "bits/ft_utility.h" // ft::pair (link as stl) and _alloc_interface.
# include "bits/ft_iterator.h"
# include "bits/type_traits.h" // ft::is_integral, ft::enable_if.
# include "bits/ft_algobase.h" // ft::lexicographical_compare.
# include <memory> // std::allocator
# include <bits/functexcept.h> // std::__throw*.
# include <sstream> // exception string.

namespace ft
{
	template<typename T, typename A = std::allocator<T> >
		class vector : protected _alloc_interface<T, A>
		{
			private:
				typedef _alloc_interface<T, A>	_base;
				typedef vector<T, A>			_vector_type;
				typedef const _vector_type&		_const_vector_ref;

			public:
				/* Member types */
				typedef T													value_type;
				typedef A													allocator_type;
				typedef T&													reference;
				typedef const T&											const_reference;
				typedef T*													pointer;
				typedef const T*											const_pointer;
				typedef ptrdiff_t											difference_type;
				typedef size_t												size_type;
				typedef ft::__normal_iterator<pointer, _vector_type>		iterator;
				typedef ft::__normal_iterator<const_pointer, _vector_type>	const_iterator;
				typedef ft::reverse_iterator<iterator>						reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			private:
				void	expand(size_type size_to_fit, bool bypass_check = false)
				{
					if (!bypass_check && !need_expansion(size_to_fit))
						return ;
					size_type new_size = this->size();
					new_size = new_size ? new_size : 1;
					while (new_size < size_to_fit)
						new_size *= 2;
					this->reserve(new_size);
				}

				bool	need_expansion(size_type size_to_fit)
				{ return size_to_fit > this->capacity(); }

				void	expand_update(size_type size_to_fit, iterator& position)
				{
					if (need_expansion(size_to_fit))
					{
						size_type new_pos = ft::distance(this->begin(), position);
						this->expand(size_to_fit, true);
						position = this->begin() + new_pos;
					}
				}

				void	splitopen_for_insert(iterator position, size_type n)
				{
					size_type gap = n;
					n += ft::distance(position + n, end());
					while (n--)
						*(position + gap + n) = *(position + n);
					this->_m_finish += gap;
				}

				void _m_range_check(size_type n) const
				{
					if (n < this->size())
						return ;
					std::stringstream ss;
					ss << "What index would you please? " << n << ", really?";
					throw std::out_of_range(ss.str());
				}

				pointer _fill_n(pointer h, size_t n, const T& v)
				{
					while (n--)
						*h++ = T(v);
					return h;
				}

				template<typename X, typename Y>
					X _copy(Y o_s, Y o_e, X pos)
					{
						X p = pos;
						while (o_s != o_e)
							*p++ = *o_s++;
						return p;
					}

			public:

				/* Member functions */

				explicit vector() : _base() {}

				vector(size_type n, const_reference val = value_type(), \
					const allocator_type type_sample = allocator_type())
				: _base(n)
				{
					this->_m_finish = this->_m_start + n;
					while (n--)
						*(this->_m_start + n) = value_type(val);
					static_cast<void>(type_sample);
				}

				template<typename I>
					vector(I o_s, I o_e, const allocator_type type_sample = allocator_type(), \
						typename ft::enable_if<!ft::is_integral<I>::value, bool>::type foo = 0)
					: _base(ft::distance(o_s, o_e))
					{
						this->_m_finish = _copy(o_s, o_e, this->_m_start);
						static_cast<void>(foo);
						static_cast<void>(type_sample);
					}

				vector(_const_vector_ref x)
				: _base(x.size())
				{ this->_m_finish = _copy(x.begin(), x.end(), this->_m_start); }
//				{ this->_m_finish = _copy(x.begin(), x.end(), this->_m_start); }

				~vector() {}

				vector& operator= (const vector& rhs)
				{
					if (this == &rhs)
						return *this;
					this->_m_free();
					this->_m_start = this->_m_allocate(rhs.size());
					this->_m_finish = _copy(rhs.begin(), rhs.end(), this->_m_start);
					this->_m_end_of_storage = this->_m_start + rhs.size();
					return *this;
				}

				/* Iterators */

				iterator				begin()				{ return iterator(this->_m_start); }
				const_iterator			begin()		const	{ return const_iterator(this->_m_start); }
				iterator				end()				{ return iterator(this->_m_finish); }
				const_iterator			end()		const	{ return const_iterator(this->_m_finish);}
				reverse_iterator		rbegin()			{ return reverse_iterator(end()); }
				const_reverse_iterator	rbegin()	const	{ return const_reverse_iterator(end()); }
				reverse_iterator		rend()				{ return reverse_iterator(begin()); }
				const_reverse_iterator	rend()		const	{ return const_reverse_iterator(begin()); }

				/* Capacity */

				size_type	size() const { return size_type(end() - begin()); }

				size_type	max_size() const { return size_type(-1) / sizeof(T) / 2; }

				void		resize(size_type new_size, const value_type& x = value_type())
				{
					if (new_size < size())
						this->_m_finish = this->_m_start + new_size;
					else if (new_size <= capacity())
						this->_m_finish = _fill_n( \
							this->_m_finish, new_size - size(), x);
					else
					{
						size_t complement = new_size - size();
						expand(new_size);
						this->_m_finish = _fill_n( \
							this->_m_finish, complement, x);
					}
				}

				size_type	capacity() const
				{ return size_type(const_iterator(this->_m_end_of_storage) - begin()); }

				bool		empty() const { return begin() == end(); }

				void		reserve(size_type new_size)
				{
					if (capacity() >= new_size)
						return ;
					if (new_size > max_size())
						throw std::length_error("Too lengthy.");
					pointer new_m_start = this->_m_allocate(new_size);
					this->_m_finish = _copy( \
						this->_m_start, this->_m_finish, new_m_start);
					this->_m_free();
					this->_m_start = new_m_start;
					this->_m_end_of_storage = this->_m_start + new_size;
				}

				/* Element Access */

				reference		operator[] (size_type n)
				{ return *(begin() + n); }

				const_reference	operator[] (size_type n) const
				{ return *(begin() + n); }

				reference		at(size_type n)
				{ this->_m_range_check(n); return *(begin() + n); }

				const_reference	at(size_type n)	const
				{ this->_m_range_check(n); return *(begin() + n); }

				reference		front()
				{ return *begin(); }
				
				const_reference	front() const
				{ return *begin(); }
				
				reference		back()
				{ return *(end() - 1); }

				const_reference	back() const
				{ return *(end() - 1); }

				/* Modifiers */

				void assign(size_type n, const value_type& val) 
				{
					size_t new_cap = n > capacity() ? n : capacity();
					this->expand(new_cap);
					this->_m_finish = _fill_n( \
						this->_m_start, n, val);
					this->_m_end_of_storage = this->_m_start + new_cap;
				}

				template<typename In>
					typename ft::enable_if< \
						!ft::is_integral<In>::value, void>::type
					assign(In origin_first, In origin_last)
					{
						this->_m_free();
						size_t new_cap =
							static_cast<size_t>(ft::distance(origin_first, origin_last)) > static_cast<size_t>(capacity()) ?
							ft::distance(origin_first, origin_last) : capacity();
						this->_m_start = this->_m_allocate(new_cap);
						this->_m_finish = _copy(origin_first, origin_last, this->_m_start);
						this->_m_end_of_storage = this->_m_start + new_cap;
					}

				void push_back(const value_type& x)
				{
					this->expand(this->size() + 1);
					*(this->_m_finish++) = x;
				}

				void pop_back()
				{
					--this->_m_finish;
				}

				iterator insert(iterator position, const value_type& x)
				{
					size_type new_pos = ft::distance(this->begin(), position);
					insert(position, 1, x);
					return this->begin() + new_pos;
				}

				void insert(iterator position, size_type n, const value_type& x)
				{
					this->expand_update(this->size() + n, position);
					this->splitopen_for_insert(position, n);
					_fill_n(position.base(), n, x);
				}

				template<typename In>
					typename ft::enable_if<!ft::is_integral<In>::value, void>::type
					insert(iterator position, In origin_first, In origin_last)
					{
						size_type n = ft::distance(origin_first, origin_last);
						this->expand_update(this->size() + n, position);
						this->splitopen_for_insert(position, n);
						_copy(origin_first, origin_last, position);
					}

				iterator erase(iterator first)
				{
					return erase(first, first + 1);
				}

				iterator erase(iterator first, iterator last)
				{
					size_type n = ft::distance(first, last);
					pointer head = &*first;
					while ((head != &*last) && (head + n != this->_m_finish))
					{
						*head = *(head + n);
						head++;
					}
					while ((head != this->_m_finish) && (head + n != this->_m_finish))
					{
						*head = *(head + n);
						head++;
					}
					this->_m_finish -= n;
					return first;
				}

				void swap(vector& rhs)
				{
					pointer _FOO_start = this->_m_start;
					pointer _FOO_finish = this->_m_finish;
					pointer _FOO_end_of_storage = this->_m_end_of_storage;
					this->_m_start = rhs._m_start;
					this->_m_finish = rhs._m_finish;
					this->_m_end_of_storage = rhs._m_end_of_storage;
					rhs._m_start = _FOO_start;
					rhs._m_finish = _FOO_finish;
					rhs._m_end_of_storage = _FOO_end_of_storage;
				}

				void clear()
				{
					erase(this->begin(), this->end());
				}

				allocator_type get_allocator() const { return allocator_type(); }

				inline bool operator== (vector<T, A>& rhs)
				{
					if (this->size() != rhs.size())
						return false;
					iterator l = this->begin();
					iterator le = this->end();
					iterator r = rhs.begin();
					while (l != le)
						if (*l++ != *r++)
							return false;
					return true;
				}

				inline bool operator!= (vector<T, A>& rhs) { return !(*this == rhs); }

				inline bool operator< (vector<T, A>& rhs)
				{
					return ft::lexicographical_compare \
						(this->begin(), this->end(), rhs.begin(), rhs.end());
				}

				inline bool operator<=	(vector<T, A>& rhs) { return !(rhs < *this);	}
				inline bool operator>	(vector<T, A>& rhs) { return rhs < *this;		}
				inline bool operator>=	(vector<T, A>& rhs) { return !(*this < rhs);	}
		};

	template<typename T, typename A>
		extern inline void swap (vector<T, A>& lhs, vector<T, A>& rhs)
		{ lhs.swap(rhs); }
}

#endif
