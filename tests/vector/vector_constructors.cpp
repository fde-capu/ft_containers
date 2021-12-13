/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:38:56 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_constructors.hpp"

void test_vector_copy_constructor(void)
{
	ft::Tester tester;

	tester.printName("Copy Constructor");
	tester.add(
		vector_copy_constructor1< ft::vector<int> >,
		vector_copy_constructor1< std::vector<int> >
	);
	tester.add(
		vector_copy_constructor1< ft::vector<float> >,
		vector_copy_constructor1< std::vector<float> >
	);
	tester.run();
}

void test_vector_assignment_op(void)
{
	ft::Tester tester;

	tester.printName("operator=()");

	tester.add(
		vector_assignment_op< ft::vector<int> >,
		vector_assignment_op< std::vector<int> >
	);
	tester.add(
		vector_assignment_op< ft::vector<float> >,
		vector_assignment_op< std::vector<float> >
	);
	tester.run();
}

void test_vector_range_constructor(void)
{
	ft::Tester tester;

	tester.printName("Range Constructor");
	tester.add(
		RangeConstructor_constructor1< ft::vector<int> >,
		RangeConstructor_constructor1< std::vector<int> >
	);
	tester.add(
		RangeConstructor_constructor1< ft::vector<float> >,
		RangeConstructor_constructor1< std::vector<float> >
	);
	tester.run();
}

void test_vector_fill_constructor(void)
{
	ft::Tester tester;

	tester.printName("Fill Constructor");

	tester.add(
		FillConstructor_constructor1< ft::vector<int> >,
		FillConstructor_constructor1< std::vector<int> >
	);
	tester.add(
		FillConstructor_constructor1< ft::vector<float> >,
		FillConstructor_constructor1< std::vector<float> >
	);
	tester.run();
}

void test_vector_default_constructor(void)
{
	ft::Tester tester;

	tester.printName("Default Constructor");
	tester.add(
		default_constructor1< ft::vector<int> >,
		default_constructor1< std::vector<int> >
		);
	tester.add(
		default_constructor1< ft::vector<float> >,
		default_constructor1< std::vector<float> >
		);
	tester.run();
}

void test_vector_constructors(void)
{
	ft::Tester tester;

	tester.printName("* CONSTRUCTORS *", true);
	test_vector_default_constructor();
	test_vector_fill_constructor();
	test_vector_range_constructor();
	test_vector_copy_constructor();
	test_vector_assignment_op();
}
