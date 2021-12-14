/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:38:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/14 11:14:51 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_H
# define FT_ITERATOR_H

# include "ft_iterator_base_types.h"
# include "ft_iterator_base_funcs.h"
# include "type_traits.h" // ft::remove_const

namespace ft // Originaly in namespace __gnu_cxx, used by vector.
{
	template<typename T, typename TC> // TypeIterator, TypeContainer.
		class __normal_iterator // "Basically" converts pointer into iterator.
		{
			private:
				typedef ft::iterator_traits<T> traits;

			protected:
				T _pointer;

			public:
				typedef typename traits::iterator_category	iterator_category;
				typedef typename traits::value_type			value_type;
				typedef typename traits::difference_type	difference_type;
				typedef typename traits::reference			reference;
				typedef typename traits::pointer			pointer;

				__normal_iterator() : _pointer(T()) {}

				explicit __normal_iterator(const T& u_it) : _pointer(u_it) {}

				template<typename Ci> // Converts const iterator to iterator.
					inline __normal_iterator
					(const __normal_iterator<Ci, TC>& u_it)
					: _pointer(u_it.base()) {}

				reference operator* () const
				{ return *_pointer; }

				pointer operator-> () const
				{ return _pointer; }

				__normal_iterator& operator++ ()
				{ ++_pointer; return *this; }

				__normal_iterator operator++ (int)
				{ return __normal_iterator(_pointer++); }

				__normal_iterator& operator-- ()
				{ --_pointer; return *this; }

				__normal_iterator operator-- (int)
				{ return __normal_iterator(_pointer--); }

				reference operator[] (const difference_type& n) const
				{ return _pointer[n]; }

				__normal_iterator& operator+= (const difference_type& n)
				{ _pointer += n; return *this; }

				__normal_iterator operator+ (const difference_type& n) const
				{ return __normal_iterator(_pointer + n); }

				__normal_iterator& operator-= (const difference_type& n)
				{ _pointer -= n; return *this; }

				__normal_iterator operator- (const difference_type& n) const
				{ return __normal_iterator(_pointer - n); }

				const T& base() const { return _pointer; }
		};
	
	template<typename IL, typename IR, typename TC>
		inline bool operator==
		(	const __normal_iterator<IL, TC>& lhs,
			const __normal_iterator<IR, TC>& rhs	)
		{ return lhs.base() == rhs.base(); }

	template<typename IL, typename IR, typename TC>
		inline bool operator!=
		(	const __normal_iterator<IL, TC>& lhs,
			const __normal_iterator<IR, TC>& rhs	)
		{ return lhs.base() != rhs.base(); }

	template<typename IL, typename IR, typename TC>
		inline bool operator<
		(	const __normal_iterator<IL, TC>& lhs,
			const __normal_iterator<IR, TC>& rhs	)
		{ return lhs.base() < rhs.base(); }

	template<typename IL, typename IR, typename TC>
		inline bool operator>
		(	const __normal_iterator<IL, TC>& lhs,
			const __normal_iterator<IR, TC>& rhs	)
		{ return lhs.base() > rhs.base(); }

	template<typename IL, typename IR, typename TC>
		inline bool operator<=
		(	const __normal_iterator<IL, TC>& lhs,
			const __normal_iterator<IR, TC>& rhs	)
		{ return lhs.base() <= rhs.base(); }

	template<typename IL, typename IR, typename TC>
		inline bool operator>=
		(	const __normal_iterator<IL, TC>& lhs,
			const __normal_iterator<IR, TC>& rhs	)
		{ return lhs.base() >= rhs.base(); }

	template<typename IL, typename IR, typename TC>
		inline ptrdiff_t operator-
		(	const __normal_iterator<IL, TC>& lhs,
			const __normal_iterator<IR, TC>& rhs	)
		{ return lhs.base() - rhs.base(); }

	template<typename T, typename TC>
		inline __normal_iterator<T, TC> operator+
		(ptrdiff_t n, const __normal_iterator<T, TC>& i)
		{ return __normal_iterator<T, TC>(i.base() + n); }

	/* Reverse Iterator */

	template<typename T>
	class reverse_iterator
	: public iterator	<
						typename ft::iterator_traits<T>::iterator_category,
						typename ft::iterator_traits<T>::value_type,
						typename ft::iterator_traits<T>::difference_type,
						typename ft::iterator_traits<T>::pointer,
						typename ft::iterator_traits<T>::reference
						>
	{
		private:
			typedef ft::reverse_iterator<T> traits;

		protected:
			T _pointer;

		public:
			typedef T									iterator_type;
			typedef typename traits::difference_type	difference_type;
			typedef typename traits::reference			reference;
			typedef typename traits::pointer			pointer;

			reverse_iterator() : _pointer() {}

			explicit reverse_iterator(T rhs) : _pointer(rhs) {}

//			Copy constructor deprecated; it has user-defined assignment constructor.
/*			reverse_iterator(const reverse_iterator& rhs)
**			: _pointer(rhs._pointer) {}
*/
			template<typename Ci>
				reverse_iterator(const reverse_iterator<Ci>& rhs)
				: _pointer(rhs.base()) {}

			iterator_type base() const
			{ return _pointer; }

			reference operator* () const 
			{
				typename remove_const<T>::type foo(_pointer);
				return *T(--foo);
			}

			pointer operator-> () const
			{ return &(operator*()); }

			reverse_iterator& operator++ () 
			{ --_pointer; return *this; }

			reverse_iterator operator++ (int) 
			{
				reverse_iterator foo = *this;
				--_pointer;
				return foo;
			}

			reverse_iterator& operator-- () 
			{ ++_pointer; return *this; }

			reverse_iterator operator-- (int) 
			{
				reverse_iterator foo = *this;
				++_pointer;
				return foo;
			}

			reverse_iterator operator+ (difference_type n) const 
			{ return reverse_iterator(_pointer - n); }

			reverse_iterator& operator+= (difference_type n) 
			{ _pointer -= n; return *this; }

			reverse_iterator operator- (difference_type n) const 
			{ return reverse_iterator(_pointer + n); }

			reverse_iterator& operator-= (difference_type n) 
			{ _pointer += n; return *this; }

			reference operator[] (difference_type n) const
			{ return *(*this + n); }
	}; 

	template<typename T>
		inline bool operator==
		(	const reverse_iterator<T>& lhs,
			const reverse_iterator<T>& rhs	)
		{ return lhs.base() == rhs.base(); }

	template<typename T>
		inline bool operator<
		(	const reverse_iterator<T>& lhs,
			const reverse_iterator<T>& rhs	)
		{ return rhs.base() < lhs.base(); }

	template<typename T>
		inline bool operator!=
		(	const reverse_iterator<T>& lhs,
			const reverse_iterator<T>& rhs	)
		{ return !(lhs == rhs); }

	template<typename T>
		inline bool operator>
		(	const reverse_iterator<T>& lhs,
			const reverse_iterator<T>& rhs	)
		{ return rhs < lhs; }

	template<typename T>
		inline bool operator<=
		(	const reverse_iterator<T>& lhs,
			const reverse_iterator<T>& rhs	)
		{ return !(rhs < lhs); }

	template<typename T>
		inline bool operator>=
		(	const reverse_iterator<T>& lhs,
			const reverse_iterator<T>& rhs	)
		{ return !(lhs < rhs); }

	template<typename T>
		inline typename reverse_iterator<T>::difference_type operator-
		(	const reverse_iterator<T>& lhs,
			const reverse_iterator<T>& rhs	)
		{ return rhs.base() - lhs.base(); }

	template<typename T>
		inline reverse_iterator<T> operator+
		(	typename reverse_iterator<T>::difference_type n,
			const reverse_iterator<T>& lhs					)
		{ return reverse_iterator<T>(lhs.base() - n); }
}

#endif 
