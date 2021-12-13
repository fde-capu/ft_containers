/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterators.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:39:31 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_iterators.hpp"


void test_set_iterator_end(void)
{
	ft:: Tester tester;
	tester.printName("end()");
	tester.add(
		set_iterator_end1< ft::set<int> >,
		set_iterator_end1< std::set<int> >
	);
	tester.add(
		set_iterator_end2< ft::set<int> >,
		set_iterator_end2< ft::set<int> >
	);
	tester.run();
}

void test_set_iterator_begin(void)
{
	ft:: Tester tester;

	tester.printName("begin()");
	tester.add(
		set_iterator_begin1< ft::set<int> >,
		set_iterator_begin1< std::set<int> >
	);
	tester.add(
		set_iterator_begin2< ft::set<int> >,
		set_iterator_begin2< std::set<int> >
	);
	tester.run();
}

void test_set_iterator_rend(void)
{
	ft:: Tester tester;

	tester.printName("rend()");
	tester.add(
		set_iterator_rend1< ft::set<int> >,
		set_iterator_rend1< std::set<int> >
	);
	tester.add(
		set_iterator_rend2< ft::set<int> >,
		set_iterator_rend2< std::set<int> >
	);
	tester.run();
}

void test_set_iterator_rbegin(void)
{
	ft:: Tester tester;

	tester.printName("rbegin()");
	tester.add(
		set_iterator_rbegin1< ft::set<int> >,
		set_iterator_rbegin1< std::set<int> >
	);
	tester.add(
		set_iterator_rbegin2< ft::set<int> >,
		set_iterator_rbegin2< std::set<int> >
	);
	tester.run();
}

void test_set_iterators(void)
{
	ft:: Tester tester;

	tester.printName("* ITERATORS *", true);
	test_set_iterator_begin();
	test_set_iterator_end();
	test_set_iterator_rbegin();
	test_set_iterator_rend();
}
