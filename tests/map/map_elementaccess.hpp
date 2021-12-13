/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elementaccess.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:52:53 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ELEMENTACCESS_HPP
# define MAP_ELEMENTACCESS_HPP

# include "map_tests.hpp"
template <typename T>
std::string map_operator_brackets4()
{
	T v;
	std::string s("");
	
	s = map_attributes<T>(v);
	s += "\n";
	s += "operator[3]: " + ft::to_string(v[3]) + "\n";
	s += "operator[5]: " + ft::to_string(v[5]) + "\n";
	s += "operator[7]: " + ft::to_string(v[7]) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_operator_brackets3()
{
	T v;
	std::string s("");
	s = map_attributes<T>(v);
	s += "\n";
	s += "operator['MAP3']: " + ft::to_string(v["MAP3"]) + "\n";
	s += "operator['MAP5']: " + ft::to_string(v["MAP5"]) + "\n";
	s += "operator['MAP7']: " + ft::to_string(v["MAP7"]) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_operator_brackets2()
{
	T v;
	std::string s("");
	for (int i = 0; i < 10; i++)
		v.insert(typename T::value_type(std::string("MAP"+ ft::to_string(i)), i));
	
	s = map_attributes<T>(v);
	s += "\n";
	s += "operator['MAP3']: " + ft::to_string(v["MAP3"]) + "\n";
	s += "operator['MAP5']: " + ft::to_string(v["MAP5"]) + "\n";
	s += "operator['MAP7']: " + ft::to_string(v["MAP7"]) + "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_operator_brackets1()
{
	T v;
	std::string s("");
	for (int i = 0; i < 10; i++)
		v.insert(typename T::value_type(i, i));
	
	s = map_attributes<T>(v);
	s += "\n";
	s += "operator[3]: " + ft::to_string(v[3]) + "\n";
	s += "operator[5]: " + ft::to_string(v[5]) + "\n";
	s += "operator[7]: " + ft::to_string(v[7]) + "\n";
	return (ft::Tester::Return(s));
}

#endif
