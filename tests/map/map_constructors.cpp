/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructors.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:38:56 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_constructors.hpp"

void test_map_copy_constructor(void)
{
	ft::Tester tester;

	tester.printName("Copy Constructor");
	tester.add(
		map_copy_constructor1< ft::map<int, int> >,
		map_copy_constructor1< std::map<int, int> >
	);
	tester.add(
		map_copy_constructor1< ft::map<std::string, int> >,
		map_copy_constructor1< std::map<std::string, int> >
	);
	tester.run();
}

void test_map_assignment_op(void)
{
	ft::Tester tester;

	tester.printName("operator=()");

	tester.add(
		map_assignment_op< ft::map<int, int> >,
		map_assignment_op< std::map<int, int> >
	);
	tester.add(
		map_assignment_op< ft::map<std::string, int> >,
		map_assignment_op< std::map<std::string, int> >
	);
	tester.run();
}

void test_map_range_constructor(void)
{
	ft::Tester tester;

	tester.printName("Range Constructor");
	tester.add(
		map_RangeConstructor_constructor1< ft::map<int, int> >,
		map_RangeConstructor_constructor1< std::map<int, int> >
	);
	tester.add(
		map_RangeConstructor_constructor1< ft::map<std::string, int> >,
		map_RangeConstructor_constructor1< std::map<std::string, int> >
	);
	tester.run();
}

void test_map_default_constructor(void)
{
	ft::Tester tester;

	tester.printName("Default Constructor");
	tester.add(
		map_default_constructor1< ft::map<int, int> >,
		map_default_constructor1< std::map<int, int> >
		);
	tester.add(
		map_default_constructor1< ft::map<std::string, int> >,
		map_default_constructor1< std::map<std::string, int> >
		);
	tester.add(
		map_default_constructor2< ft::map<int, int> >,
		map_default_constructor2< std::map<int, int> >
		);
	tester.add(
		map_default_constructor2< ft::map<std::string, int> >,
		map_default_constructor2< std::map<std::string, int> >
		);
	tester.run();
}

void test_map_constructors(void)
{
	ft::Tester tester;

	tester.printName("* CONSTRUCTORS *", true);
	test_map_default_constructor();
	test_map_range_constructor();
	test_map_copy_constructor();
	test_map_assignment_op();
}
