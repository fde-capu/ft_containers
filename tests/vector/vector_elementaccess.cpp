/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_elementaccess.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:39:14 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_elementaccess.hpp"

void 	test_vector_front(void)
{
	ft::Tester tester;

	tester.printName("front()");
	tester.add(
		vector_front< ft::vector<int> >,
		vector_front< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_back(void)
{
	ft::Tester tester;

	tester.printName("back()");
	tester.add(
		vector_back< ft::vector<int> >,
		vector_back< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_operator_brackets(void)
{
	ft::Tester tester;
	
	tester.printName("operator[]");
	tester.add(
		vector_operator_brackets< ft::vector<int> >,
		vector_operator_brackets< std::vector<int> >
		);
	tester.run();
}

void test_vector_elementaccess(void)
{
	ft::Tester tester;

	tester.printName("* ELEMENT ACCESS *", true);
	test_vector_operator_brackets();
	test_vector_front();
	test_vector_back();

}
