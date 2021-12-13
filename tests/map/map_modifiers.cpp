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

#include "map_modifiers.hpp"

void 	test_map_insert()
{
	ft::Tester tester;

	tester.printName("insert()");
	tester.add(
		map_insert1< ft::map<int, int> >,
		map_insert1< std::map<int, int> >
		);
	tester.add(
		map_insert2< ft::map<int, int> >,
		map_insert2< std::map<int, int> >
		);
	tester.add(
		map_insert3< ft::map<int, int> >,
		map_insert3< std::map<int, int> >
		);
	tester.add(
		map_insert4< ft::map<int, int> >,
		map_insert4< std::map<int, int> >
		);
	tester.run();
}


void 	test_map_erase()
{
	ft::Tester tester;

	tester.printName("erase()");
	tester.add(
		map_erase1< ft::map<int, int> >,
		map_erase1< std::map<int, int> >
		);
	tester.add(
		map_erase2< ft::map<int, int> >,
		map_erase2< std::map<int, int> >
		);
	tester.add(
		map_erase3< ft::map<int, int> >,
		map_erase3< std::map<int, int> >
		);
	tester.add(
		map_erase4< ft::map<int, int> >,
		map_erase4< std::map<int, int> >
		);
	tester.run();
}

void 	test_map_swap()
{
	ft::Tester tester;

	tester.printName("swap()");
	tester.add(
		map_swap< ft::map<int, int> >,
		map_swap< std::map<int, int> >
		);
	tester.run();
}

void 	test_map_clear()
{
	ft::Tester tester;

	tester.printName("clear()");
	tester.add(
		map_clear< ft::map<int, int> >,
		map_clear< std::map<int, int> >
		);
	tester.run();
}

void test_map_modifiers(void)
{
	ft::Tester tester;

	tester.printName("* MODIFIERS *", true);
	test_map_insert();
	test_map_erase();
	test_map_swap();
	test_map_clear();
}
