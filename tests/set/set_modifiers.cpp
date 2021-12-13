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

#include "set_modifiers.hpp"

void 	test_set_insert()
{
	ft::Tester tester;

	tester.printName("insert()");
	tester.add(
		set_insert1< ft::set<int> >,
		set_insert1< std::set<int> >
		);
	tester.add(
		set_insert2< ft::set<int> >,
		set_insert2< std::set<int> >
		);
	tester.add(
		set_insert3< ft::set<int> >,
		set_insert3< std::set<int> >
		);
	tester.add(
		set_insert4< ft::set<int> >,
		set_insert4< std::set<int> >
		);
	tester.run();
}


void 	test_set_erase()
{
	ft::Tester tester;

	tester.printName("erase()");
	tester.add(
		set_erase1< ft::set<int> >,
		set_erase1< std::set<int> >
		);
	tester.add(
		set_erase2< ft::set<int> >,
		set_erase2< std::set<int> >
		);
	tester.add(
		set_erase3< ft::set<int> >,
		set_erase3< std::set<int> >
		);
	tester.add(
		set_erase4< ft::set<int> >,
		set_erase4< std::set<int> >
		);
	tester.run();
}

void 	test_set_swap()
{
	ft::Tester tester;

	tester.printName("swap()");
	tester.add(
		set_swap< ft::set<int> >,
		set_swap< std::set<int> >
		);
	tester.run();
}

void 	test_set_clear()
{
	ft::Tester tester;

	tester.printName("clear()");
	tester.add(
		set_clear< ft::set<int> >,
		set_clear< std::set<int> >
		);
	tester.run();
}

void test_set_modifiers(void)
{
	ft::Tester tester;

	tester.printName("* MODIFIERS *", true);
	test_set_insert();
	test_set_erase();
	test_set_swap();
	test_set_clear();
}
