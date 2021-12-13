/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:39:53 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_operations.hpp"

void 	test_map_lowerbound()
{
	ft::Tester tester;

	tester.printName("lower_bound()");
	tester.add(
		map_lowerbound1< ft::map<int, int> >,
		map_lowerbound1< std::map<int, int> >
		);
	tester.add(
		map_lowerbound2< ft::map<int, int> >,
		map_lowerbound2< std::map<int, int> >
		);
	tester.add(
		map_lowerbound3< ft::map<int, int> >,
		map_lowerbound3< std::map<int, int> >
		);
	tester.add(
		map_lowerbound4< ft::map<int, int> >,
		map_lowerbound4< std::map<int, int> >
		);
	tester.run();
}

void 	test_map_upperbound()
{
	ft::Tester tester;

	tester.printName("upper_bound()");
	tester.add(
		map_upperbound1< ft::map<int, int> >,
		map_upperbound1< std::map<int, int> >
		);
	tester.add(
		map_upperbound2< ft::map<int, int> >,
		map_upperbound2< std::map<int, int> >
		);
	tester.add(
		map_upperbound3< ft::map<int, int> >,
		map_upperbound3< std::map<int, int> >
		);
	tester.add(
		map_upperbound4< ft::map<int, int> >,
		map_upperbound4< std::map<int, int> >
		);
	tester.run();
}

void 	test_map_equalrange()
{
	ft::Tester tester;

	tester.printName("equal_range()");
	tester.add(
		map_equalrange1< ft::map<int, int> >,
		map_equalrange1< std::map<int, int> >
		);
	tester.add(
		map_equalrange2< ft::map<int, int> >,
		map_equalrange2< std::map<int, int> >
		);
	tester.run();
}

void 	test_map_find()
{
	ft::Tester tester;

	tester.printName("find()");
	tester.add(
		map_find1< ft::map<int, int> >,
		map_find1< std::map<int, int> >
		);
	tester.add(
		map_find2< ft::map<int, int> >,
		map_find2< std::map<int, int> >
		);
	tester.run();
}

void 	test_map_count()
{
	ft::Tester tester;

	tester.printName("count()");
	tester.add(
		map_count1< ft::map<int, int> >,
		map_count1< std::map<int, int> >
		);
	tester.add(
		map_count2< ft::map<int, int> >,
		map_count2< std::map<int, int> >
		);
	tester.run();
}

void test_map_operations(void)
{
	ft::Tester tester;

	tester.printName("* OPERATIONS *", true);
	test_map_count();
	test_map_find();
	test_map_equalrange();
	test_map_lowerbound();
	test_map_upperbound();
}
