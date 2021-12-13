/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_overloads.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:53:08 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OVERLOADS_HPP
# define VECTOR_OVERLOADS_HPP

# include "map_tests.hpp"

/*
** as allocator's max_size can vary between implementations
** due to different maps inner structures (AVLTree, RBTree, Binary Tree),
** std:: and ft:: max_size won't necessarily match.
** This function returns, then, wether max_size is larger than size() or not.
*/

template <typename T>
std::string map_getallocator()
{
	T v;
	std::string s("");

	s = map_attributes<T>(v);
	s += "\nAlloc Max Size: " + ft::to_string(v.get_allocator().max_size() > v.size());
	return (ft::Tester::Return(s));
}


template <typename T>
std::string map_relational1()
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
std::string map_relational2()
{
	T v1;
	T v2;
	std::string s("");

	v1.insert(typename T::value_type(1, 50));
	v1.insert(typename T::value_type(2, 50));
	v1.insert(typename T::value_type(3, 50));
	v1.insert(typename T::value_type(4, 50));
	v2.insert(typename T::value_type(1, 50));
	v2.insert(typename T::value_type(2, 50));
	v2.insert(typename T::value_type(3, 50));
	v2.insert(typename T::value_type(4, 50));
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
std::string map_relational3()
{
	T v1;
	T v2;
	std::string s("");

	v1.insert(typename T::value_type(1, 50));
	v1.insert(typename T::value_type(2, 50));
	v1.insert(typename T::value_type(3, 50));
	v1.insert(typename T::value_type(4, 50));
	v2.insert(typename T::value_type(1, 50));
	v2.insert(typename T::value_type(2, 50));
	v2.insert(typename T::value_type(3, 50));
	v2.insert(typename T::value_type(4, 50));
	v2.insert(typename T::value_type(5, 50));

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
std::string map_relational4()
{
	T v1;
	T v2;
	std::string s("");
	v1.insert(typename T::value_type(6, 50));
	v1.insert(typename T::value_type(2, 50));
	v1.insert(typename T::value_type(3, 50));
	v1.insert(typename T::value_type(4, 50));
	v2.insert(typename T::value_type(1, 50));
	v2.insert(typename T::value_type(2, 50));
	v2.insert(typename T::value_type(3, 50));
	v2.insert(typename T::value_type(4, 50));
	v2.insert(typename T::value_type(5, 50));
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
std::string map_swap(void (*swap)(T&, T&))
{
	T v1;
	T v2;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.insert(typename T::value_type(i, i));
	for(int i = 5; i >= 0; i--)
		v2.insert(typename T::value_type(i, i));
	swap(v1, v2);
	s = "v1: " + map_attributes<T>(v1) + "\n";
	s += "v2: " + map_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

#endif
