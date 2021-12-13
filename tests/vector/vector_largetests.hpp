/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_largetests.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:17:49 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/23 16:02:06 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_LARGETESTS_HPP
# define VECTOR_LARGETESTS_HPP

# include "vector_tests.hpp"

template <typename T>
std::string vector_large_swap_random()
{
	T v;
	for (int i = 0; i < ft::Tester::large_number; i++)
		v.push_back(typename T::value_type());
	T().swap(v);
	std::string s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_large_access_rndbuf()
{
	T v;
	for (int i = 0; i < ft::Tester::large_number; i++)
		v.push_back(typename T::value_type());
	for (int i = 0; i < ft::Tester::large_number; i++)
		v[i].idx = i;
	std::string s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_large_access_random()
{
	T v;
	for (int i = 0; i < ft::Tester::large_number; i++)
		v.push_back(typename T::value_type(i));
	for (int i = 0; i < ft::Tester::large_number; i++)
		v[i] = i;
	std::string s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_large_insert_rndbuf()
{
	T v;
	for (int i = 0; i < ft::Tester::large_number; i++)
		v.push_back(typename T::value_type());
	std::string s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_large_insert_random()
{
	T v;
	for (int i = 0; i < ft::Tester::large_number; i++)
		v.push_back(typename T::value_type(i));
	std::string s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

#endif
