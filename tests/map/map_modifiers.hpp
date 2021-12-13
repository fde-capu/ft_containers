/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifiers.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:53:05 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_MODIFIERS_HPP
# define MAP_MODIFIERS_HPP

# include "map_tests.hpp"

template <typename T>
std::string map_insert1()
{
	T v;
	std::string s("");

	v.insert(typename T::value_type(1, 100));
	v.insert(typename T::value_type(5, 500));
	v.insert(typename T::value_type(10, 1000));

	s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_insert2()
{
	T v;
	std::string s("");
	v.insert(typename T::value_type(1, 100));
	v.insert(typename T::value_type(5, 500));
	v.insert(typename T::value_type(10, 1000));
	v.insert(++v.begin(), typename T::value_type(7, 700));
	v.insert(v.end(), typename T::value_type(9, 900));
	v.insert(--v.end(), typename T::value_type(30, 300));

	s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_insert3()
{
	T v;
	T tmp;
	std::string s("");
	tmp.insert(typename T::value_type(1, 100));
	tmp.insert(typename T::value_type(5, 500));
	tmp.insert(typename T::value_type(10, 1000));	

	v.insert(tmp.begin(), tmp.end());
	s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

/*
** testing inserting repeated elements
*/
template <typename T>
std::string map_insert4()
{
	T v;
	T tmp;
	std::string s("");
	tmp.insert(typename T::value_type(1, 100));
	tmp.insert(typename T::value_type(5, 500));
	tmp.insert(typename T::value_type(10, 1000));	
	s += "Insert Repeated: " + ft::to_string(tmp.insert(typename T::value_type(1, 100)).second);
	s += "Insert Repeated: " + ft::to_string(tmp.insert(typename T::value_type(5, 500)).second);
	s += "Insert Repeated: " + ft::to_string(tmp.insert(typename T::value_type(10, 1000)).second);
	s += map_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string map_erase1()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i, i));
	v.erase(v.begin(), v.end());
	s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_erase2()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i, i));
	typename T::iterator it = v.insert(typename T::value_type(19, 44)).first;
	v.erase(it);
	s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_erase3()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i, i));
	v.erase(5);
	s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_erase4()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i, i));
	v.erase(++v.begin(), --v.end());
	s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_erase5()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i, i));
	v.erase(v.end());
	v.erase(--v.end());
	v.erase(++v.begin());
	s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_swap()
{
	T v1;
	T v2;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.insert(typename T::value_type(i, i));
	for(int i = 25; i >= 15; i--)
		v2.insert(typename T::value_type(i, i));
	v1.swap(v2);
	s = "v1: " + map_attributes<T>(v1) + "\n";
	s = "v2: " + map_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_clear()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i, i));
	v.clear();
	s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

#endif
