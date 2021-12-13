/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_elementaccess.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:59:25 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ELEMENTACCESS_HPP
# define VECTOR_ELEMENTACCESS_HPP

# include "vector_tests.hpp"

template <typename T>
std::string vector_operator_brackets()
{
	T v;
	std::string s("");
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	
	s = vector_attributes<T>(v);
	s += "\n";
	s += "operator[3]: " + ft::to_string(v[3]) + "\n";
	s += "operator[5]: " + ft::to_string(v[5]) + "\n";
	s += "operator[7]: " + ft::to_string(v[7]) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_at()
{
	T v;
	std::string s("");
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	
	s = vector_attributes<T>(v);
	s += "\n";
	s += "at(3): " + ft::to_string(v.at(3)) + "\n";
	s += "at(5): " + ft::to_string(v.at(5)) + "\n";
	s += "at(7): " + ft::to_string(v.at(7)) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_front()
{
	T v;
	std::string s("");
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	
	s = vector_attributes<T>(v);
	s += "\n";
	s += "front: " + ft::to_string(v.front()) + "\n";
	return (ft::Tester::Return(s));
}


template <typename T>
std::string vector_back()
{
	T v;
	std::string s("");
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	
	s = vector_attributes<T>(v);
	s += "\n";
	s += "back: " + ft::to_string(v.back()) + "\n";
	return (ft::Tester::Return(s));
}

#endif
