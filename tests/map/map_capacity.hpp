/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_capacity.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:52:46 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CAPACITY_HPP
# define MAP_CAPACITY_HPP

# include "map_tests.hpp"

/*
** As max_size depends on the structure of the Node,
** std:: and ft:: results won't match exactly.
*/
template <typename T>
std::string max_size()
{
	T v;
	std::string s = map_attributes<T>(v);
	s += "MaxSize: " + ft::to_string(v.max_size() > v.size());
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_size2()
{
	T v;
	std::string s = map_attributes<T>(v);
	s += "Size: " + ft::to_string(v.size());
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_size1()
{
	T v;
	
	for (int i = 0; i < 10; i++)
		v.insert(typename T::value_type(i, i));
	std::string s = map_attributes<T>(v);
	s += "Size: " + ft::to_string(v.size());
	return (ft::Tester::Return(s));
}


template <typename T>
std::string map_empty2()
{
	T v;
	std::string s("");

	v.insert(typename T::value_type());
	s = map_attributes<T>(v);
	s += "Empty: " + ft::to_string(v.empty());
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_empty1()
{
	T v;
	std::string s("");

	s = map_attributes<T>(v);
	s += "Empty: " + ft::to_string(v.empty());
	return (ft::Tester::Return(s));
}

#endif
