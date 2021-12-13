/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_constructors.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:38:56 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_constructors.hpp"

void test_set_copy_constructor(void)
{
	ft::Tester tester;

	tester.printName("Copy Constructor");
	tester.add(
		set_copy_constructor1< ft::set<int> >,
		set_copy_constructor1< std::set<int> >
	);
	tester.add(
		set_copy_constructor1< ft::set<std::string> >,
		set_copy_constructor1< std::set<std::string> >
	);
	tester.run();
}

void test_set_assignment_op(void)
{
	ft::Tester tester;

	tester.printName("operator=()");

	tester.add(
		set_assignment_op< ft::set<int> >,
		set_assignment_op< std::set<int> >
	);
	tester.add(
		set_assignment_op< ft::set<std::string> >,
		set_assignment_op< std::set<std::string> >
	);
	tester.run();
}

void test_set_range_constructor(void)
{
	ft::Tester tester;

	tester.printName("Range Constructor");
	tester.add(
		set_RangeConstructor_constructor1< ft::set<int> >,
		set_RangeConstructor_constructor1< std::set<int> >
	);
	tester.add(
		set_RangeConstructor_constructor1< ft::set<std::string> >,
		set_RangeConstructor_constructor1< std::set<std::string> >
	);
	tester.run();
}

void test_set_default_constructor(void)
{
	ft::Tester tester;

	tester.printName("Default Constructor");
	tester.add(
		set_default_constructor1< ft::set<int> >,
		set_default_constructor1< std::set<int> >
		);
	tester.add(
		set_default_constructor1< ft::set<std::string> >,
		set_default_constructor1< std::set<std::string> >
		);
	tester.add(
		set_default_constructor2< ft::set<int> >,
		set_default_constructor2< std::set<int> >
		);
	tester.add(
		set_default_constructor2< ft::set<std::string> >,
		set_default_constructor2< std::set<std::string> >
		);
	tester.run();
}

void test_set_constructors(void)
{
	ft::Tester tester;

	tester.printName("* CONSTRUCTORS *", true);
	test_set_default_constructor();
	test_set_range_constructor();
	test_set_copy_constructor();
	test_set_assignment_op();
}
