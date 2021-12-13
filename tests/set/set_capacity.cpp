/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:38:44 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_capacity.hpp"


void test_set_empty(void)
{
	ft::Tester tester;

	tester.printName("empty()");
	tester.add(
		set_empty1< ft::set<int> >,
		set_empty1< std::set<int> >
	);
	tester.add(
		set_empty2< ft::set<int> >,
		set_empty2< std::set<int> >
	);
	tester.run();
}

void test_set_max_size(void)
{
	ft::Tester tester;

	tester.printName("max_size()");
	tester.add(
		max_size< ft::set<int> >,
		max_size< std::set<int> >
	);
	tester.add(
		max_size< ft::set<std::string> >,
		max_size< std::set<std::string> >
	);
	tester.run();
}

void test_set_size(void)
{
	ft::Tester tester;

	tester.printName("size()");
	tester.add(
		set_size1< ft::set<int> >,
		set_size1< std::set<int> >
	);
	tester.add(
		set_size2< ft::set<int> >,
		set_size2< std::set<int> >
	);

	tester.run();
}


void test_set_capacity(void)
{
	ft::Tester tester;

	tester.printName("* CAPACITY *", true);
	test_set_size();
	test_set_max_size();
	test_set_empty();
}
