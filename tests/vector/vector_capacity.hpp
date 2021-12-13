/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:59:18 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CAPACITY_HPP
# define VECTOR_CAPACITY_HPP

# include "vector_tests.hpp"


template <typename T>
std::string resize1()
{
	T v(10, 42);
	std::string s("");

	v.resize(500);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string resize2()
{
	T v(10, 42);
	std::string s("");

	v.resize(3);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string max_size()
{
	T v;
	std::string s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string size1()
{
	T v(10, 999);
	std::string s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string size2()
{
	T v(0, 0);
	std::string s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string capacity1()
{
	T v;
	std::string s("");

	v.reserve(1000);
	s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string capacity2()
{
	T v(100, 42);
	std::string s("");

	v.reserve(110);
	s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_empty()
{
	T v(100, 42);
	std::string s("");

	v.empty();
	s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_reserve()
{
	T v(100, 42);
	std::string s("");

	v.reserve(200);
	s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

#endif
