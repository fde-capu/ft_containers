/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:39:53 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_operations.hpp"

void 	test_set_lowerbound()
{
	ft::Tester tester;

	tester.printName("lower_bound()");
	tester.add(
		set_lowerbound1< ft::set<int> >,
		set_lowerbound1< std::set<int> >
		);
	tester.add(
		set_lowerbound2< ft::set<int> >,
		set_lowerbound2< std::set<int> >
		);
	tester.add(
		set_lowerbound3< ft::set<int> >,
		set_lowerbound3< std::set<int> >
		);
	tester.add(
		set_lowerbound4< ft::set<int> >,
		set_lowerbound4< std::set<int> >
		);
	tester.run();
}

void 	test_set_upperbound()
{
	ft::Tester tester;

	tester.printName("upper_bound()");
	tester.add(
		set_upperbound1< ft::set<int> >,
		set_upperbound1< std::set<int> >
		);
	tester.add(
		set_upperbound2< ft::set<int> >,
		set_upperbound2< std::set<int> >
		);
	tester.add(
		set_upperbound3< ft::set<int> >,
		set_upperbound3< std::set<int> >
		);
	tester.add(
		set_upperbound4< ft::set<int> >,
		set_upperbound4< std::set<int> >
		);
	tester.run();
}

void 	test_set_equalrange()
{
	ft::Tester tester;

	tester.printName("equal_range()");
	tester.add(
		set_equalrange1< ft::set<int> >,
		set_equalrange1< std::set<int> >
		);
	tester.add(
		set_equalrange2< ft::set<int> >,
		set_equalrange2< std::set<int> >
		);
	tester.run();
}

void 	test_set_find()
{
	ft::Tester tester;

	tester.printName("find()");
	tester.add(
		set_find1< ft::set<int> >,
		set_find1< std::set<int> >
		);
	tester.add(
		set_find2< ft::set<int> >,
		set_find2< std::set<int> >
		);
	tester.run();
}

void 	test_set_count()
{
	ft::Tester tester;

	tester.printName("count()");
	tester.add(
		set_count1< ft::set<int> >,
		set_count1< std::set<int> >
		);
	tester.add(
		set_count2< ft::set<int> >,
		set_count2< std::set<int> >
		);
	tester.run();
}

void test_set_operations(void)
{
	ft::Tester tester;

	tester.printName("* OPERATIONS *", true);
	test_set_count();
	test_set_find();
	test_set_equalrange();
	test_set_lowerbound();
	test_set_upperbound();
}
