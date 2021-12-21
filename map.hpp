/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:39:33 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/21 14:34:42 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "bits/ft_tree.h"
# include <functional> // std::less

namespace ft
{
	template <
		typename K, typename V, typename C = std::less<K>, \
		typename A = std::allocator<ft::pair<const K, V> >
		>
		class map
		{
			private:
				_tree<K, ft::pair<const K, V>, C, A> _mtree;

			public:
				typedef K										key_type;
				typedef V										mapped_type;
				typedef C										key_compare;
				typedef A										allocator_type;
				typedef ft::pair<const K, V>					value_type;
				typedef value_type&								reference;
				typedef const value_type&						const_reference;
				typedef ft::_tree_iterator<value_type>			iterator;
				typedef const iterator							const_iterator;
				typedef size_t						  			size_type;
				typedef ptrdiff_t					  			difference_type;
				typedef value_type*					  			pointer;
				typedef const value_type*			  			const_pointer;
				typedef ft::reverse_iterator<iterator>			reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

				explicit map(const C& c = C(), const A& a = A()) : _mtree(c, a) {}

				map(iterator s, iterator e, const C& c = C(), const A& a = A()) : _mtree(c, a)
				{ _mtree.insert_unique(s, e); }

				map(const map& rhs) : _mtree(rhs._mtree) {}

				map& operator= (const map& rhs)
				{
					_mtree = rhs._mtree;
					return *this;
				}

				allocator_type			get_allocator()	const	{ return _mtree.get_allocator(); }
				iterator				begin()					{ return _mtree.begin(); }
				const_iterator			begin()			const	{ return _mtree.begin(); }
				iterator				end()					{ return _mtree.end(); }
				const_iterator			end()			const	{ return _mtree.end(); }
				reverse_iterator		rbegin()				{ return _mtree.rbegin(); }
				const_reverse_iterator	rbegin()		const	{ return _mtree.rbegin(); }
				reverse_iterator		rend()					{ return _mtree.rend(); }
				const_reverse_iterator	rend()			const	{ return _mtree.rend(); }
				bool					empty()			const	{ return _mtree.empty(); }
				size_type				size()			const	{ return _mtree.size(); }
				size_type				max_size()		const	{ return _mtree.max_size(); }

				iterator insert(iterator position, const value_type& p)
				{
					static_cast<void>(position);
					return _mtree.insert_unique(p).first;
				}

				ft::pair<iterator, bool> insert(const value_type& p)	{ return _mtree.insert_unique(p); }
				void			insert(iterator s, iterator e)			{ _mtree.insert_unique(s, e); }
				void			erase(iterator position)				{ _mtree.erase(position); }
				size_type		erase(const key_type& k)				{ return _mtree.erase(k); }
				void			erase(iterator s, iterator e)			{ _mtree.erase(s, e); }
				void			swap(map& rhs)							{ _mtree.swap(rhs._mtree); }
				void			clear()									{ _mtree.clear(); }
				key_compare		key_comp() const						{ return _mtree.key_comp(); }
				iterator		find(const key_type& k)					{ return _mtree.find(k); }
				const_iterator	find(const key_type& k) const			{ return _mtree.find(k); }
				size_type		count(const key_type& k) const			{ return _mtree.find(k) != _mtree.end() ? 1 : 0; }
				iterator		lower_bound(const key_type& k)			{ return _mtree.lower_bound(k); }
				const_iterator	lower_bound(const key_type& k) const	{ return _mtree.lower_bound(k); }
				iterator		upper_bound(const key_type& k)			{ return _mtree.upper_bound(k); }
				const_iterator	upper_bound(const key_type& k) const	{ return _mtree.upper_bound(k); }
				ft::pair<iterator, iterator> equal_range(const key_type& k) { return _mtree.equal_range(k); }
				ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const { return _mtree.equal_range(k); }

				class value_compare
				{
					friend class map<K, V, C, A>;
					private:
						C comp;
					protected:
						value_compare(C u_compare) : comp(u_compare) {}
					public:
						bool operator() (const value_type& lhs, const value_type& rhs) const
						{ return comp(lhs.first, rhs.first); }

						typedef bool		result_type;
						typedef value_type	first_argument_type;
						typedef value_type	second_argument_type;
				};

				value_compare value_comp() const { return value_compare(_mtree.key_comp()); }

				template <typename _K, typename _V, typename _C, typename _A>
					friend bool operator== (const ft::map<_K, _V, _C, _A>&, const ft::map<_K, _V, _C, _A>&);

				template <typename _K, typename _V, typename _C, typename _A>
					friend bool operator< (const ft::map<_K, _V, _C, _A>&, const ft::map<_K, _V, _C, _A>&);

				mapped_type& operator[] (const key_type& p)
				{
					iterator i = find(p);
					if (i != end())
						return (*i).second;
					return (*_mtree.insert_unique(value_type(p, mapped_type())).first).second;
				}
		};

	template <typename K, typename V, typename C, typename A>
		inline bool operator==
		(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs)
		{ return lhs._mtree == rhs._mtree; } // _mtree access, thanks, friend!

	template <typename K, typename V, typename C, typename A>
		inline bool operator<
		(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs)
		{ return lhs._mtree < rhs._mtree; }

	template <typename K, typename V, typename C, typename A>
		inline bool operator!=
		(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs)
		{ return !(lhs == rhs); }

	template <typename K, typename V, typename C, typename A>
		inline bool operator>
		(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs)
		{ return rhs < lhs; }

	template <typename K, typename V, typename C, typename A>
		inline bool operator<=
		(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs)
		{ return !(rhs < lhs); }

	template <typename K, typename V, typename C, typename A>
		inline bool operator>=
		(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs)
		{ return !(lhs < rhs); }

	template <typename K, typename V, typename C, typename A>
		inline void swap
		(const ft::map<K, V, C, A>& lhs, const ft::map<K, V, C, A>& rhs)
		{ lhs.swap(rhs); }
}

#endif
