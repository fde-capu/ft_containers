/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_overloads.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:53:08 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OVERLOADS_HPP
# define STACK_OVERLOADS_HPP

# include "stack_tests.hpp"

template <typename T>
std::string stack_relational1()
{
	T v1;
	T v2;
	std::string s("");

	if (v1 == v2)
		s += "v1 and v2 are equal\n";
	if (v1 != v2)
		s += "v1 and v2 are not equal\n";
	if (v1 <  v2)
		s += "v1 is less than v2\n";
	if (v1 >  v2)
		s += "v1 is greater than v2\n";
	if (v1 <= v2)
		s += "v1 is less than or equal to v2\n";
	if (v1 >= v2)
		s += "v1 is greater than or equal to v2\n";
	return (ft::Tester::Return(s));
}


template <typename T>
std::string stack_relational2()
{
	T v1;
	T v2;
	std::string s("");

	v1.push(typename T::value_type(1));
	v1.push(typename T::value_type(2));
	v1.push(typename T::value_type(3));
	v1.push(typename T::value_type(4));
	v2.push(typename T::value_type(1));
	v2.push(typename T::value_type(2));
	v2.push(typename T::value_type(3));
	v2.push(typename T::value_type(4));
	if (v1 == v2)
		s += "v1 and v2 are equal\n";
	if (v1 != v2)
		s += "v1 and v2 are not equal\n";
	if (v1 <  v2)
		s += "v1 is less than v2\n";
	if (v1 >  v2)
		s += "v1 is greater than v2\n";
	if (v1 <= v2)
		s += "v1 is less than or equal to v2\n";
	if (v1 >= v2)
		s += "v1 is greater than or equal to v2\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_relational3()
{
	T v1;
	T v2;
	std::string s("");

	v1.push(typename T::value_type(1));
	v1.push(typename T::value_type(2));
	v1.push(typename T::value_type(3));
	v1.push(typename T::value_type(4));
	v2.push(typename T::value_type(1));
	v2.push(typename T::value_type(2));
	v2.push(typename T::value_type(3));
	v2.push(typename T::value_type(4));
	v2.push(typename T::value_type(5));

	if (v1 == v2)
		s += "v1 and v2 are equal\n";
	if (v1 != v2)
		s += "v1 and v2 are not equal\n";
	if (v1 <  v2)
		s += "v1 is less than v2\n";
	if (v1 >  v2)
		s += "v1 is greater than v2\n";
	if (v1 <= v2)
		s += "v1 is less than or equal to v2\n";
	if (v1 >= v2)
		s += "v1 is greater than or equal to v2\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string stack_relational4()
{
	T v1;
	T v2;
	std::string s("");
	v1.push(typename T::value_type(6));
	v1.push(typename T::value_type(2));
	v1.push(typename T::value_type(3));
	v1.push(typename T::value_type(4));
	v2.push(typename T::value_type(1));
	v2.push(typename T::value_type(2));
	v2.push(typename T::value_type(3));
	v2.push(typename T::value_type(4));
	v2.push(typename T::value_type(5));
	if (v1 == v2)
		s += "v1 and v2 are equal\n";
	if (v1 != v2)
		s += "v1 and v2 are not equal\n";
	if (v1 <  v2)
		s += "v1 is less than v2\n";
	if (v1 >  v2)
		s += "v1 is greater than v2\n";
	if (v1 <= v2)
		s += "v1 is less than or equal to v2\n";
	if (v1 >= v2)
		s += "v1 is greater than or equal to v2\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_swap(void (*swap)(T&, T&))
{
	T v1;
	T v2;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.push(typename T::value_type(i));
	for(int i = 5; i >= 0; i--)
		v2.push(typename T::value_type(i));
	swap(v1, v2);
	s = "v1: " + set_attributes<T>(v1) + "\n";
	s += "v2: " + set_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

#endif
