/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverseiterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:56:14 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 17:27:20 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_REVERSEITERATOR_HPP
# define TEST_REVERSEITERATOR_HPP

# include "test_utilities.hpp"

template<typename T, typename RevIt>
std::string test4()
{
	T v;
	std::string s("");

	v.insert(v.begin(), 15, 5);
	RevIt it = v.rbegin();
	RevIt ite = v.rend();
	for (typename T::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		s += ft::to_string(*it);
	}
	for (; it != ite; ++it)
	{
		s += ft::to_string(*it);
	}
	return (s);
}

/*
** string
*/

template<typename T>
std::string test3()
{
	std::string s("");
	std::string txt(".gnirtS a gnitseT");
	T v(txt.data(), txt.data() + txt.size());

	for (typename T::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
			s += ft::to_string(*it);
	}
	return (s);
}

/*
** complex types
*/

template<typename T1, typename T2>
std::string test2()
{
	std::string s("");
	int array[5];
	for (int i = 0; i < 5; i++)
		array[i] = i;
	T1 v;
	T2 tmp(array, array + 5);
	v.push_back(tmp);
	v.push_back(tmp);
	v.push_back(tmp);
	v.push_back(tmp);
	v.push_back(tmp);
	for (typename T1::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		for (typename T2::reverse_iterator it2 = (*it).rbegin(); it2 != (*it).rend(); it2++)
			s += ft::to_string(*it2);
	}
	return (s);
}

/*
** integers
*/

template<typename T>
std::string test1()
{
	T v;
	std::string s("");

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	for (typename T::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
		s += ft::to_string(*it);
	return (s);
}

#endif
