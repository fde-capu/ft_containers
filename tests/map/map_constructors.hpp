/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructors.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:52:49 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CONSTRUCTORS_HPP
# define MAP_CONSTRUCTORS_HPP

# include "map_tests.hpp"

template <typename T>
std::string map_assignment_op()
{
	typedef typename T::key_type key_type;
	typedef typename T::mapped_type mapped_type;

	T rng;
	for (int i = 0; i < 3; i++)
		rng[map_presets<key_type>(i)] = map_presets<mapped_type>(i);
	T v;
	v = rng;
	std::string s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_copy_constructor1()
{
	typedef typename T::key_type key_type;
	typedef typename T::mapped_type mapped_type;

	T rng;
	for (int i = 0; i < 3; i++)
		rng[map_presets<key_type>(i)] = map_presets<mapped_type>(i);
	T v(rng);
	std::string s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_RangeConstructor_constructor1()
{
	typedef typename T::key_type key_type;
	typedef typename T::mapped_type mapped_type;

	T rng;
	for (int i = 0; i < 3; i++)
		rng[map_presets<key_type>(i)] = map_presets<mapped_type>(i);
	T v(rng.begin(), rng.end());
	std::string s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_default_constructor2()
{
	typedef typename T::key_type key_type;
	typedef typename T::mapped_type mapped_type;

	T v;
	for (int i = 0; i < 3; i++)
		v[map_presets<key_type>(i)] = map_presets<mapped_type>(i);
	std::string s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

template <typename T>
std::string map_default_constructor1()
{
	T v;
	std::string s = map_attributes<T>(v);
	return (ft::Tester::Return(s));
}

#endif
