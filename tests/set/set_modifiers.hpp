/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_modifiers.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:53:05 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_MODIFIERS_HPP
# define SET_MODIFIERS_HPP

# include "set_tests.hpp"

template <typename T>
std::string set_insert1()
{
	T v;
	std::string s("");

	v.insert(typename T::value_type(1));
	v.insert(typename T::value_type(5));
	v.insert(typename T::value_type(10));

	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_insert2()
{
	T v;
	std::string s("");
	v.insert(typename T::value_type(1));
	v.insert(typename T::value_type(5));
	v.insert(typename T::value_type(10));
	v.insert(++v.begin(), typename T::value_type(7));
	v.insert(v.end(), typename T::value_type(9));
	v.insert(--v.end(), typename T::value_type(30));

	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_insert3()
{
	T v;
	T tmp;
	std::string s("");
	tmp.insert(typename T::value_type(1));
	tmp.insert(typename T::value_type(5));
	tmp.insert(typename T::value_type(10));	

	v.insert(tmp.begin(), tmp.end());
	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

/*
** testing inserting repeated elements
*/
template <typename T>
std::string set_insert4()
{
	T v;
	T tmp;
	std::string s("");
	tmp.insert(typename T::value_type(1));
	tmp.insert(typename T::value_type(5));
	tmp.insert(typename T::value_type(10));	
	s += "Insert Repeated: " + ft::to_string(tmp.insert(typename T::value_type(1)).second);
	s += "Insert Repeated: " + ft::to_string(tmp.insert(typename T::value_type(5)).second);
	s += "Insert Repeated: " + ft::to_string(tmp.insert(typename T::value_type(10)).second);
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string set_erase1()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	v.erase(v.begin(), v.end());
	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_erase2()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.insert(typename T::value_type(19)).first;
	v.erase(it);
	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_erase3()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	v.erase(5);
	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_erase4()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	v.erase(++v.begin(), --v.end());
	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_erase5()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	v.erase(v.end());
	v.erase(--v.end());
	v.erase(++v.begin());
	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_swap()
{
	T v1;
	T v2;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.insert(typename T::value_type(i));
	for(int i = 25; i >= 15; i--)
		v2.insert(typename T::value_type(i));
	v1.swap(v2);
	s = "v1: " + set_attributes<T>(v1) + "\n";
	s = "v2: " + set_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_clear()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	v.clear();
	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

#endif
