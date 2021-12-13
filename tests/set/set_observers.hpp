/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_observers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:34:56 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:57:32 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_OBSERVERS_HPP
# define SET_OBSERVERS_HPP

# include "set_tests.hpp"

template <typename T>
std::string set_observers_valuecomp1()
{
	T v;
	std::string s("");

	typename T::value_compare comparison = v.value_comp();
  	typename T::iterator it1 = v.insert(typename T::value_type(1)).first;
  	typename T::iterator it2 = v.insert(typename T::value_type(2)).first;
  	typename T::iterator it3 = v.insert(typename T::value_type(3)).first;
  	typename T::iterator it4 = v.insert(typename T::value_type(4)).first;

	s += "value_compare [1, 4|" + ft::to_string(comparison(*it1, *it4)) + "] ";
	s += "value_compare [2, 2|" + ft::to_string(comparison(*it2, *it2)) + "] ";
	s += "value_compare [4, 3|" + ft::to_string(comparison(*it4, *it3)) + "] ";
	s+= "\n";
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_observers_keycomp1()
{
	T v;
	std::string s("");
	for (int i = 0; i < 10; i++)
		v.insert(typename T::value_type(i));
	
	typename T::key_compare comparison = v.key_comp();
	int highest = *(v.rbegin());
	typename T::iterator it = v.begin();
	s = set_attributes<T>(v);
	while (comparison((*it++), highest))
		s += "[" + ft::to_string(*it) + "]";
	s+= "\n";
	return (ft::Tester::Return(s));
}

#endif
