/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterators.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:39:31 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_iterators.hpp"


void test_map_iterator_end(void)
{
	ft:: Tester tester;
	tester.printName("end()");
	tester.add(
		map_iterator_end1< ft::map<int, int> >,
		map_iterator_end1< std::map<int, int> >
	);
	tester.add(
		map_iterator_end2< ft::map<int, int> >,
		map_iterator_end2< ft::map<int, int> >
	);
	tester.run();
}

void test_map_iterator_begin(void)
{
	ft:: Tester tester;

	tester.printName("begin()");
	tester.add(
		map_iterator_begin1< ft::map<int, int> >,
		map_iterator_begin1< std::map<int, int> >
	);
	tester.add(
		map_iterator_begin2< ft::map<int, int> >,
		map_iterator_begin2< std::map<int, int> >
	);
	tester.run();
}

void test_map_iterator_rend(void)
{
	ft:: Tester tester;

	tester.printName("rend()");
	tester.add(
		map_iterator_rend1< ft::map<int, int> >,
		map_iterator_rend1< std::map<int, int> >
	);
	tester.add(
		map_iterator_rend2< ft::map<int, int> >,
		map_iterator_rend2< std::map<int, int> >
	);
	tester.run();
}

void test_map_iterator_rbegin(void)
{
	ft:: Tester tester;

	tester.printName("rbegin()");
	tester.add(
		map_iterator_rbegin1< ft::map<int, int> >,
		map_iterator_rbegin1< std::map<int, int> >
	);
	tester.add(
		map_iterator_rbegin2< ft::map<int, int> >,
		map_iterator_rbegin2< std::map<int, int> >
	);
	tester.run();
}

void test_map_iterators(void)
{
	ft:: Tester tester;

	tester.printName("* ITERATORS *", true);
	test_map_iterator_begin();
	test_map_iterator_end();
	test_map_iterator_rbegin();
	test_map_iterator_rend();
}
