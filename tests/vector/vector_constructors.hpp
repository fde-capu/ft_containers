/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:24:37 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:59:22 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CONSTRUCTORS_HPP
# define VECTOR_CONSTRUCTORS_HPP

# include "vector_tests.hpp"

template <typename T>
std::string vector_assignment_op()
{
	T rng(10, 100);
	T v;

	v = rng;
	std::string s = vector_attributes<T>(v);
	
	return (ft::Tester::Return(s));
}

template <typename T>
std::string vector_copy_constructor1()
{
	T rng(10, 100);
	T v(rng);
	std::string s = vector_attributes<T>(v);
	
	return (ft::Tester::Return(s));
}

template <typename T>
std::string RangeConstructor_constructor1()
{
	T rng(10, 100);
	T v(rng.begin(), rng.end());
	std::string s = vector_attributes<T>(v);
	
	return (ft::Tester::Return(s));
}

template <typename T>
std::string FillConstructor_constructor1()
{
	T v(10, 999);
	std::string s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

template <typename T>
std::string default_constructor1()
{
	T v;
	std::string s = vector_attributes<T>(v);

	return (ft::Tester::Return(s));
}

#endif
