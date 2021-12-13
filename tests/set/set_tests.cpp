/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:47:16 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:00:29 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_tests.hpp"

template<>
std::string set_presets<std::string>(int i)
{
	std::string s[3];

	s[0] = "Testing";
	s[1] = "Forty";
	s[2] = "Two";
	return(s[i]);
}

void test_set(void)
{
	ft::Tester tester;

	tester.printTitle("Set");
	test_set_constructors();
	test_set_capacity();
	test_set_iterators();
	test_set_modifiers();
	test_set_operations();
	test_set_overloads();
	test_set_observers();
 	test_set_largetests();

}
