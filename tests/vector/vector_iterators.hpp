/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:59:29 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATORS_HPP
# define VECTOR_ITERATORS_HPP

# include "vector_tests.hpp"

template <typename T>
std::string iterator_rend1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	T v(rng.begin(), rng.end());
	std::string s = vector_attributes<T>(v);
	s += "\n";
	s += "REnd - 1: " + ft::to_string(*(v.rend() - 1)) + "\n";
	s += "REnd - 3: " + ft::to_string(*(v.rend() - 3)) + "\n";
	s += "REnd - 9: " + ft::to_string(*(v.rend() - 9)) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string iterator_rbegin1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	T v(rng.begin(), rng.end());
	std::string s = vector_attributes<T>(v);
	s += "\n";
	s += "RBegin: " + ft::to_string(*(v.rbegin())) + "\n";
	s += "RBegin + 3: " + ft::to_string(*(v.rbegin() + 3)) + "\n";
	s += "RBegin + 9: " + ft::to_string(*(v.rbegin() + 9)) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string iterator_end1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	T v(rng.begin(), rng.end());
	std::string s = vector_attributes<T>(v);
	s += "\n";
	s += "End - 1: " + ft::to_string(*(v.end() - 1)) + "\n";
	s += "End - 3: " + ft::to_string(*(v.end() - 3)) + "\n";
	s += "End - 9: " + ft::to_string(*(v.end() - 9)) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string iterator_begin1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.push_back(i);
	T v(rng.begin(), rng.end());
	std::string s = vector_attributes<T>(v);
	s += "\n";
	s += "Begin: " + ft::to_string(*(v.begin())) + "\n";
	s += "Begin + 3: " + ft::to_string(*(v.begin() + 3)) + "\n";
	s += "Begin + 9: " + ft::to_string(*(v.begin() + 9)) + "\n";
	return (ft::Tester::Return(s));
}

#endif
