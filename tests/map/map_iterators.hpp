/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:52:42 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATORS_HPP
# define MAP_ITERATORS_HPP

# include "map_tests.hpp"

template <typename T>
std::string map_iterator_rend2()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.insert(typename T::value_type(i, i));
	T v(rng.begin(), rng.end());
	std::string s = map_attributes<T>(v);
	typename T::reverse_iterator it = v.rend();
	it--;
	it--;
	it++;
	s += "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_iterator_rend1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.insert(typename T::value_type(i, i));
	T v(rng.begin(), rng.end());
	std::string s = map_attributes<T>(v);
	s += "\n";
	s += "REnd - 1: " + ft::to_string((--(v.rend()))->first) + "\n";
	s += "REnd - 3: " + ft::to_string((--(--(v.rend())))->first) + "\n";
	s += "REnd - 9: " + ft::to_string((--(--(--(v.rend()))))->first) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_iterator_rbegin2()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.insert(typename T::value_type(i, i));
	T v(rng.begin(), rng.end());
	std::string s = map_attributes<T>(v);
	typename T::reverse_iterator it = v.rbegin();
	it++;
	it++;
	it--;
	s += "\n";
	s += "Value: " + ft::to_string(it->first) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_iterator_rbegin1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.insert(typename T::value_type(i, i));
	T v(rng.begin(), rng.end());
	std::string s = map_attributes<T>(v);
	s += "\n";
	s += "RBegin: " + ft::to_string((v.rbegin())->first) + "\n";
	s += "RBegin + 3: " + ft::to_string((v.rbegin()++)->first) + "\n";
	s += "RBegin + 9: " + ft::to_string(((v.rbegin()++)++)->first) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_iterator_end2()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.insert(typename T::value_type(i, i));
	T v(rng.begin(), rng.end());
	std::string s = map_attributes<T>(v);
	typename T::iterator it = v.end();
	it--;
	it--;
	it++;
	s += "\n";
	s += "Value: " + ft::to_string(it->first) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_iterator_end1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.insert(typename T::value_type(i, i));
	T v(rng.begin(), rng.end());
	std::string s = map_attributes<T>(v);
	s += "\n";
	s += "End - 1: " + ft::to_string(((--v.end()))->first) + "\n";
	s += "End - 3: " + ft::to_string((--(--(v.end())))->first) + "\n";
	s += "End - 9: " + ft::to_string((--(--(--(v.end()))))->first) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_iterator_begin2()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.insert(typename T::value_type(i, i));
	T v(rng.begin(), rng.end());
	std::string s = map_attributes<T>(v);
	typename T::iterator it = v.begin();
	it++;
	it++;
	it--;
	s += "\n";
	s += "Value: " + ft::to_string(it->first) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_iterator_begin1()
{
	T rng;
	for (int i = 0; i < 10; i++)
		rng.insert(typename T::value_type(i, i));
	T v(rng.begin(), rng.end());
	std::string s = map_attributes<T>(v);
	s += "\n";
	s += "Begin: " + ft::to_string((v.begin())->first) + "\n";
	s += "Begin + 3: " + ft::to_string((v.begin()++)->first) + "\n";
	s += "Begin + 9: " + ft::to_string(((v.begin()++)++)->first) + "\n";
	return (ft::Tester::Return(s));
}

#endif
