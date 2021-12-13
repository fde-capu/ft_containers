/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operations.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:53:05 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_OPERATIONS_HPP
# define SET_OPERATIONS_HPP

# include "set_tests.hpp"

template <typename T>
std::string set_upperbound4()
{
	T v;
	std::string s("teste");

	for(int i = 3; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.upper_bound(18);
	if (it != v.end())
		s = "LowerBound: " + ft::to_string(*it) + "\n";
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_upperbound3()
{
	T v;
	std::string s("");

	for(int i = 3; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.upper_bound(10);
	if (it != v.end())
		s = "LowerBound: " + ft::to_string(*it) + "\n";
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_upperbound2()
{
	T v;
	std::string s("");

	for(int i = 3; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.upper_bound(5);
	if (it != v.end())
		s = "LowerBound: " + ft::to_string(*it) + "\n";
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_upperbound1()
{
	T v;
	std::string s("");

	for(int i = 3; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.upper_bound(0);
	if (it != v.end())
		s = "LowerBound: " + ft::to_string(*it) + "\n";
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_lowerbound4()
{
	T v;
	std::string s("");

	for(int i = 3; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.lower_bound(17);
	if (it != v.end())
		s = "LowerBound: " + ft::to_string(*it) + "\n";
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_lowerbound3()
{
	T v;
	std::string s("");

	for(int i = 3; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.lower_bound(10);
	if (it != v.end())
		s = "LowerBound: " + ft::to_string(*it) + "\n";
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string set_lowerbound2()
{
	T v;
	std::string s("");

	for(int i = 3; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.lower_bound(0);
	if (it != v.end())
		s = "LowerBound: " + ft::to_string(*it) + "\n";
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_lowerbound1()
{
	T v;
	std::string s("");

	for(int i = 3; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.lower_bound(5);
	if (it != v.end())
		s = "LowerBound: " + ft::to_string(*it) + "\n";
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_equalrange2()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.equal_range(5).first;
	typename T::iterator ite = v.equal_range(5).second;
	for (; it != ite; it++)
		s = "EqualRange: " + ft::to_string(*it) + "\n";
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_equalrange1()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.equal_range(18).first;
	typename T::iterator ite = v.equal_range(18).second;
	for (; it != ite; it++)
		s = "EqualRange: " + ft::to_string(*it) + "\n";
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_find2()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.find(18);
	s = "Found: " + ( it != v.end() ? ft::to_string(*it) : "NO");
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_find1()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	typename T::iterator it = v.find(8);
	s = "Found: " + ( it != v.end() ? ft::to_string(*it) : "NO");
	s += set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_count1()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	v.count(5);
	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_count2()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.insert(typename T::value_type(i));
	v.count(13);
	s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

#endif
