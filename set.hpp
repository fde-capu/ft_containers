/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:22:03 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/12 07:16:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "bits/ft_tree.h"

namespace ft
{
	template<typename K, typename C = std::less<K>, typename A = std::allocator<K> >
		class set
		{
			private:
				_tree<K, K, C, A> _mtree;

			public:
				typedef K										key_type;
				typedef K										value_type;
				typedef size_t						  			size_type;
				typedef ptrdiff_t					  			difference_type;
				typedef C										key_compare;
				typedef A										allocator_type;
				typedef value_type&								reference;
				typedef const value_type&						const_reference;
				typedef value_type*					  			pointer;
				typedef const value_type*			  			const_pointer;
				typedef ft::_tree_iterator<value_type>			iterator;
				typedef const iterator							const_iterator;
				typedef ft::reverse_iterator<iterator>			reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

				explicit set(const C& c = C(), const A& a = A()) : _mtree(c, a) {}

				set(iterator s, iterator e, const C& c = C(), const A& a = A()) : _mtree(c, a)
				{ _mtree.insert_unique(s, e); }

				set(const set& rhs) : _mtree(rhs._mtree) {}

				set& operator= (const set& rhs)
				{
					_mtree = rhs._mtree;
					return *this;
				}

				key_compare				key_comp()		const	{ return _mtree.key_comp(); }
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
				void			clear()									{ _mtree.clear(); }
				void			swap(set& rhs)							{ _mtree.swap(rhs._mtree); }
				size_type		count(const key_type& k) const			{ return _mtree.find(k) != _mtree.end() ? 1 : 0; }
				iterator		find(const key_type& k)					{ return _mtree.find(k); }
				const_iterator	find(const key_type& k) const			{ return _mtree.find(k); }
				iterator		lower_bound(const key_type& k)			{ return _mtree.lower_bound(k); }
				const_iterator	lower_bound(const key_type& k) const	{ return _mtree.lower_bound(k); }
				iterator		upper_bound(const key_type& k)			{ return _mtree.upper_bound(k); }
				const_iterator	upper_bound(const key_type& k) const	{ return _mtree.upper_bound(k); }
				ft::pair<iterator, iterator> equal_range(const key_type& k)	{ return _mtree.equal_range(k); }
				ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const { return _mtree.equal_range(k); }

				class value_compare
				{
					friend class set<K, C, A>;
					private:
						C comp;
					protected:
						value_compare(C u_compare) : comp(u_compare) {}
					public:
						bool operator() (const value_type& lhs, const value_type& rhs) const
						{ return comp(lhs, rhs); }

						typedef bool		result_type;
						typedef value_type	first_argument_type;
						typedef value_type	second_argument_type;
				};

				value_compare value_comp() const { return value_compare(_mtree.key_comp()); }

				template <typename _K, typename _C, typename _A>
					friend bool operator== (const ft::set<_K, _C, _A>&, const ft::set<_K, _C, _A>&);

				template <typename _K, typename _C, typename _A>
					friend bool operator< (const ft::set<_K, _C, _A>&, const ft::set<_K, _C, _A>&);
		};
	
	template<typename K, typename C, typename A>
		inline bool operator==
		(const ft::set<K, C, A>& lhs, const ft::set<K, C, A>& rhs)
		{ return lhs._mtree == rhs._mtree; }

	template<typename K, typename C, typename A>
		inline bool operator!=
		(const ft::set<K, C, A>& lhs, const ft::set<K, C, A>& rhs)
		{ return !(lhs == rhs); }

	template<typename K, typename C, typename A>
		inline bool operator<
		(const ft::set<K, C, A>& lhs, const ft::set<K, C, A>& rhs)
		{ return lhs._mtree < rhs._mtree; }

	template<typename K, typename C, typename A>
		inline bool operator>
		(const ft::set<K, C, A>& lhs, const ft::set<K, C, A>& rhs)
		{ return rhs < lhs; }

	template<typename K, typename C, typename A>
		inline bool operator>=
		(const ft::set<K, C, A>& lhs, const ft::set<K, C, A>& rhs)
		{ return !(lhs < rhs); }

	template<typename K, typename C, typename A>
		inline bool operator<=
		(const ft::set<K, C, A>& lhs, const ft::set<K, C, A>& rhs)
		{ return !(rhs < lhs); }

	template<typename K, typename C, typename A>
		inline void swap
		(ft::set<K, C, A>& lhs, ft::set<K, C, A>& rhs)
		{ lhs.swap(rhs); }
}

#endif
