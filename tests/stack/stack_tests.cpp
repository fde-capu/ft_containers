/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:47:16 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/17 11:11:02 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_tests.hpp"

void test_stack(void)
{
	ft::Tester tester;

	tester.printTitle("Stack");
	test_stack_functions();
	test_stack_modifiers();
	test_stack_overloads();

}
