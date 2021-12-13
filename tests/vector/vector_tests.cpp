/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:47:16 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/23 15:22:56 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_tests.hpp"

void test_vector(void)
{
	ft::Tester tester;

    tester.printTitle("Vector");
    test_vector_constructors();
    test_vector_capacity();
	test_vector_iterators();
	test_vector_elementaccess();
	test_vector_modifiers();
	test_vector_overloads();
	test_vector_largetests();
}
