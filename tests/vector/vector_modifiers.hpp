/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:59:33 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_MODIFIERS_HPP
# define VECTOR_MODIFIERS_HPP

# include "vector_tests.hpp"


template <typename T>
std::string vector_pushback1()
{
	T rng;
	T v;
	std::string s("");
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_pushback2()
{
	T rng;
	T v;
	std::string s("");
	for (int i = 0; i < 42; i++)
		rng.push_back(i);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_popback1()
{
	T v;
	std::string s("");
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	v.pop_back();
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_popback2()
{
	T v;
	std::string s("");

	v.push_back(1);
	v.pop_back();
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_assign1()
{
	T rng;
	T v;
	std::string s("");
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	v.assign(rng.begin() + 3, rng.end());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_assign2()
{
	T v;
	std::string s("");

	v.assign(10, 42);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert1()
{
	T v(10, 42);
	T tmp(15, 21);
	std::string s("");

	v.insert(v.begin() + 5, tmp.begin(), tmp.end());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert2()
{
	T v(10, 42);
	std::string s("");

	v.insert(v.begin() + 2, 15, 21);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert3()
{
	T v(10, 42);
	std::string s("");

	v.insert(v.begin() + 2, 15);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert4()
{
	T v(10, 42);
	T tmp(15, 21);
	std::string s("");

	v.insert(v.end(), tmp.begin(), tmp.end());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert5()
{
	T v(10, 42);
	std::string s("");

	v.insert(v.end(), 15, 21);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_insert6()
{
	T v(10, 42);
	std::string s("");

	v.insert(v.end(), 15);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase1()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.push_back(i);
	v.erase(v.begin(), v.end());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase2()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.push_back(i);
	v.erase(v.begin() + 3, v.end() - 1);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase3()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.push_back(i);
	v.erase(v.begin());
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase4()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.push_back(i);
	v.erase(v.end() - 1);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_erase5()
{
	T v;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v.push_back(i);
	v.erase(v.begin() + 5);
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_swap()
{
	T v1;
	T v2;
	std::string s("");

	for(int i = 0; i <= 10; i++)
		v1.push_back(i);
	for(int i = 5; i >= 0; i--)
		v2.push_back(i);
	v1.swap(v2);
	s = "v1: " + vector_attributes<T>(v1) + "\n";
	s = "v2: " + vector_attributes<T>(v2);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_clear()
{
	T v(10, 42);
	T tmp(15, 21);
	std::string s("");

	v.insert(v.end(), tmp.begin(), tmp.end());
	v.clear();
	s = vector_attributes<T>(v);
	return (ft::Tester::Return(s));
}

#endif
