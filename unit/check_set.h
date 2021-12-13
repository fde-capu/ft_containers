/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_set.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:58:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/13 02:15:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHECK_SET_H
# define CHECK_SET_H

# include <typeinfo>
# include "check_helpers.h"

template<typename T>
void check_set()
{
	title("SET");
	title("Member types");
	check(1, typeid(typename ft::set<T>::key_type).name(), typeid(T).name());
	check(2, typeid(typename ft::set<T>::value_type).name(), typeid(T).name());
	check(3, typeid(typename ft::set<T>::size_type).name(), typeid(size_t).name());
	check(4, typeid(typename ft::set<T>::difference_type).name(), typeid(std::ptrdiff_t).name());
	check(5, typeid(typename ft::set<T>::key_compare).name(), typeid(std::less<T>).name());
	check(6, typeid(typename ft::set<T>::allocator_type).name(), typeid(std::allocator<T>).name());
	check(7, typeid(typename ft::set<T>::reference).name(), typeid(T&).name());
	check(8, typeid(typename ft::set<T>::const_reference).name(), typeid(const T&).name());
	check(9, typeid(typename ft::set<T>::pointer).name(), typeid(T*).name());
	check(10, typeid(typename ft::set<T>::const_pointer).name(), typeid(const T*).name());
	check(11, typeid(typename ft::set<T>::iterator::value_type).name(), typeid(T).name());
	check(12, typeid(typename ft::set<T>::const_iterator::value_type).name(), typeid(const T).name());
	check(13, typeid(typename ft::set<T>::reverse_iterator::value_type).name(), typeid(T).name());
	check(14, typeid(typename ft::set<T>::const_reverse_iterator::value_type).name(), typeid(const T).name());

	title("Constructors");
	check(1, typeid(ft::set<T>()).name(), typeid(ft::set<T>()).name());
	check(2, typeid(ft::set<T>(std::less<T>()).key_comp()).name(), typeid(std::less<T>).name());
	check(3, typeid(ft::set<T, inv_compare<T> >(inv_compare<T>(), std::allocator<T>()).key_comp()).name(), typeid(inv_compare<T>).name());

	ft::set<T> s;
	s.insert(T(5));
	s.insert(T(8));
	s.insert(T(3));
	s.insert(T(1));
	s.insert(T(42));
	s.insert(T(21));

	{
		ft::set<T> x(++s.begin(), --s.end());
		check(4, *x.begin(), T(3));
		check(5, *--x.end(), T(21));
	}
	{
		ft::set<T, inv_compare<T> > x(++s.begin(), --s.end(), inv_compare<T>());
		check(5, *x.begin(), T(21));
		check(6, *--x.end(), T(3));
	}
	{
		ft::set<T> x(s);
		check(7, *x.begin(), T(1));
		check(8, *--x.end(), T(42));
	}
	title("ops.\t");
	{
		ft::set<T> x = s;
		check(9, *x.begin(), T(1));
		check(10, *--x.end(), T(42));
	}
	{
		typename ft::set<T>::allocator_type a = s.get_allocator();
		try
		{
			T* address = a.allocate(T(43));
			a.deallocate(address, T(43));
			check(11, 1, 1);
		}
		catch(std::exception& e)
		{
			check(11, "failed to use allocator from set", "stl");
		}
	}

	title("Iterators");
	{
		typename ft::set<T>::iterator sia = s.begin();
		check(1, *sia, T(1));
		check(2, *++sia, T(3));
	}
	{
		typename ft::set<T>::iterator sia = s.end();
		check(3, *--sia, T(42));
		check(4, *--sia, T(21));
	}
	{
		typename ft::set<T>::reverse_iterator sia = s.rbegin();
		check(5, *sia, T(42));
		check(6, *++sia, T(21));
	}
	{
		typename ft::set<T>::reverse_iterator sia = s.rend();
		check(7, *--sia, T(1));
		check(8, *--sia, T(3));
	}

	title("Capacity");
	{
		ft::set<T> e;
		check(1, e.empty(), true);
		check(2, e.size(), static_cast<typename ft::set<T>::size_type>(0));
		e.insert(T(2));
		check(3, e.empty(), false);
		check(4, e.size(), static_cast<typename ft::set<T>::size_type>(1));
		e.erase(T(2));
		check(5, e.empty(), true);
		check(6, e.size(), static_cast<typename ft::set<T>::size_type>(0));
		check(7, s.size(), static_cast<typename ft::set<T>::size_type>(6));
		e.insert(T(0));
		check(8, e.empty(), false);
		check(9, e.size(), static_cast<typename ft::set<T>::size_type>(1));
		e.clear();
		check(10, e.empty(), true);
		check(11, e.max_size(), size_t(-1) / 80);
	}

	title("Modifiers");
	{
		ft::set<T> m(s);
		m.clear();
		check(1, m.empty(), true);
	}
	{
		ft::set<T> m(s);
		ft::pair<typename ft::set<T>::iterator, bool> i = m.insert(T(77));
		check(2, i.second, true);
		ft::pair<typename ft::set<T>::iterator, bool> j = m.insert(T(77));
		check(3, j.second, false);
		check(4, *i.first, T(77));
		check(5, *j.first, T(77));
	}
	{
		ft::set<T> m(s);
		typename ft::set<T>::iterator sia = m.begin();
		sia++++++;
		m.insert(sia, T(77));
		check(6, *m.begin(), T(1));
		check(7, *--m.end(), T(77));
	}
	{
		ft::set<T> m;
		m.insert(++s.begin(), --s.end());
		check(8, *m.begin(), T(3));
		check(9, *--m.end(), T(21));
	}
	{
		ft::set<T> m(s);
		typename ft::set<T>::iterator sia = ++++++m.begin();
		m.erase(sia);
		check(10, *++++++m.begin(), T(21));
		check(11, m.size(), static_cast<typename ft::set<T>::size_type>(5));
		check(12, *++++m.begin(), T(5));
	}
	{
		ft::set<T> m(s);
		typename ft::set<T>::iterator sia = ++++++m.begin();
		typename ft::set<T>::iterator sib = --m.end();
		m.erase(sia, sib);
		check(13, *m.begin(), T(1));
		check(14, m.size(), static_cast<typename ft::set<T>::size_type>(4));
		check(15, *--m.end(), T(42));
		check(16, *----m.end(), T(5));
	}
	{
		ft::set<T> m(s);
		typename ft::set<T>::size_type t = m.erase(T(8));
		check(17, *++++++m.begin(), T(21));
		check(18, m.size(), static_cast<typename ft::set<T>::size_type>(5));
		check(19, *++++m.begin(), T(5));
		check(20, t, static_cast<typename ft::set<T>::size_type>(1));
		t = m.erase(27);
		check(21, t, static_cast<typename ft::set<T>::size_type>(0));
	}
	{
		ft::set<T> m;
		m.insert(T(4));
		m.insert(T(9));
		m.insert(T(10));
		m.swap(s);
		check(22, *m.begin(), T(1));
		check(23, *--m.end(), T(42));
		check(24, *s.begin(), T(4));
		check(25, *--s.end(), T(10));
		check(26, m.size(), static_cast<typename ft::set<T>::size_type>(6));
		check(27, s.size(), static_cast<typename ft::set<T>::size_type>(3));
		m.swap(s);
	}

	title("Lookup\t");
	{
		ft::set<T> m(s);
		check(1, m.count(T(21)), static_cast<typename ft::set<T>::size_type>(1));
		m.insert(T(21));
		check(2, m.count(T(21)), static_cast<typename ft::set<T>::size_type>(1));
		check(3, m.count(T(17)), static_cast<typename ft::set<T>::size_type>(0));
		typename ft::set<T>::iterator i = m.find(T(21));
		check(4, *i, T(21));
		i = m.find(17);
		check(5, i == m.end(), true);
		i = m.lower_bound(T(21));
		check(6, *i, T(21));
		i = m.lower_bound(T(20));
		check(7, *i, T(21));
		i = m.upper_bound(T(21));
		check(8, *i, T(42));
		i = m.upper_bound(T(20));
		check(9, *i, T(21));
		ft::pair<typename ft::set<T>::iterator, typename ft::set<T>::iterator> p = m.equal_range(T(21));
		check(10, *p.first, T(21));
		check(11, *p.second, T(42));
		p = m.equal_range(T(20));
		check(12, *p.first, T(21));
		check(13, *p.second, T(21));
	}

	title("Observers");
	{
		ft::set<T> m(s);
		typename ft::set<T>::key_compare kc = m.key_comp();
		check(1, kc(T(1), T(2)), true);
		check(2, kc(T(2), T(1)), false);
		typename ft::set<T>::value_compare vc = m.value_comp();
		check(3, vc(T(1), T(2)), true);
		check(4, vc(T(2), T(1)), false);
	}

	title("Operators");
	{
		ft::set<T> z;
		z.insert(T(4));
		z.insert(T(9));
		z.insert(T(10));

		ft::set<T> e;

		ft::set<T> m(s);

		check(1, m == s, true);
		check(2, m == z, false);
		check(3, m == e, false);
		check(4, m != s, false);
		check(5, m != z, true);
		check(6, m != e, true);
		check(7, m > s, false);
		check(8, m > z, false);
		check(9, m > e, true);
		check(10, m < s, false);
		check(11, m < z, true);
		check(12, m < e, false);
		check(13, m >= s, true);
		check(14, m >= z, false);
		check(15, m >= e, true);
		check(16, m <= s, true);
		check(17, m <= z, true);
		check(18, m <= e, false);
	}

	title("swap()\t");
	{
		ft::set<T> z;
		z.insert(T(4));
		z.insert(T(9));
		z.insert(T(10));
	
		swap(z, s);
		check(1, *s.begin(), T(4));
		check(2, *--s.end(), T(10));
		check(3, *z.begin(), T(1));
		check(4, *--z.end(), T(42));
	}
}

# endif
