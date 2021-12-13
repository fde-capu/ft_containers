/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_constructors.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:52:49 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_CONSTRUCTORS_HPP
# define SET_CONSTRUCTORS_HPP

# include "set_tests.hpp"

template <typename T>
std::string set_assignment_op()
{
	typedef typename T::value_type value_type;

	T rng;
	for (int i = 0; i < 3; i++)
		rng.insert(set_presets<value_type>(i));
	T v;
	v = rng;
	std::string s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_copy_constructor1()
{
	typedef typename T::key_type key_type;

	T rng;
	for (int i = 0; i < 3; i++)
		rng.insert(set_presets<key_type>(i));
	T v(rng);
	std::string s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_RangeConstructor_constructor1()
{
	typedef typename T::value_type value_type;

	T rng;
	for (int i = 0; i < 3; i++)
		rng.insert(set_presets<value_type>(i));
	T v(rng.begin(), rng.end());
	std::string s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_default_constructor2()
{
	typedef typename T::value_type value_type;

	T v;
	for (int i = 0; i < 3; i++)
		v.insert(set_presets<value_type>(i));
	std::string s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string set_default_constructor1()
{
	T v;
	std::string s = set_attributes<T>(v);
	return (ft::Tester::Return(s));
}

#endif
