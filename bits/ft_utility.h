/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:38:51 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/22 12:44:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITY_H
# define FT_UTILITY_H

# include "ft_pair.h"
# include <memory> // std::allocator
# include <cstddef> // size_t

namespace ft
{
	template<typename T, typename A = std::allocator<T> >
		struct _alloc_interface
		{
			protected:
				A					a;
				T*					_m_start;
				T*					_m_finish;
				T*					_m_end_of_storage;

				typedef const T&	const_reference;
				typedef T*			address;
				typedef A			allocator_type;

				_alloc_interface()
				: _m_start(0), _m_finish(0), _m_end_of_storage(0) {}

				_alloc_interface(size_t n)
				{
					_m_start = n ? _m_allocate(n) : 0;
					_m_finish = _m_start;
					_m_end_of_storage = _m_start + n;
				}

				~_alloc_interface() 
				{ _m_free(); }

				address	_m_allocate(size_t n)
				{ return a.allocate(n); }

				void	_m_deallocate(address p, size_t n)
				{ a.deallocate(p, n); }

				void	_m_free()
				{
					_m_destroy();
					if (_m_start != _m_end_of_storage)
						_m_deallocate(_m_start, _m_end_of_storage - _m_start);
				}

				void	_m_destroy()
				{
//					if (_m_start == _m_end_of_storage)
					if (!_m_capacity())
						return ;
					T* h = _m_start;
					while (h < _m_end_of_storage)
						h++->~T();
				}

				size_t	_m_capacity() const
				{ return size_t(
					&dynamic_cast<void*>(_m_end_of_storage) -
					&dynamic_cast<void*>(_m_start)); }
		};
}

#endif
