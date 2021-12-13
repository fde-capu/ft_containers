/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_overloads.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:59:37 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OVERLOADS_HPP
# define VECTOR_OVERLOADS_HPP

# include "vector_tests.hpp"

template <typename T>
std::string vector_getallocator()
{
	T v;
	std::string s("");

	s = vector_attributes<T>(v);
	s += "\nAlloc Max Size: " + ft::to_string(v.get_allocator().max_size());
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_relational1()
{
	T v1(3, 100);
	T v2(5, 200);
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
std::string vector_relational2()
{
	T v1(3, 100);
	T v2(3, 100);
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
std::string vector_relational3()
{
	T v1(4, 200);
	T v2(3, 100);
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
std::string vector_relational4()
{
	T v1(3, 100);
	T v2(4, 100);
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
std::string vector_swap(void (*swap)(T&, T&))
{
	T v1;
	T v2;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.push_back(i);
	for(int i = 5; i >= 0; i--)
		v2.push_back(i);
	swap(v1, v2);
	s = "v1: " + vector_attributes<T>(v1) + "\n";
	s += "v2: " + vector_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

#endif
