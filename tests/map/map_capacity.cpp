/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:38:44 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_capacity.hpp"


void test_map_empty(void)
{
	ft::Tester tester;

	tester.printName("empty()");
	tester.add(
		map_empty1< ft::map<int, int> >,
		map_empty1< std::map<int, int> >
	);
	tester.add(
		map_empty2< ft::map<int, int> >,
		map_empty2< std::map<int, int> >
	);
	tester.run();
}

void test_map_max_size(void)
{
	ft::Tester tester;

	tester.printName("max_size()");
	tester.add(
		max_size< ft::map<int, int> >,
		max_size< std::map<int, int> >
	);
	tester.add(
		max_size< ft::map<std::string, std::string> >,
		max_size< std::map<std::string, std::string> >
	);
	tester.run();
}

void test_map_size(void)
{
	ft::Tester tester;

	tester.printName("size()");
	tester.add(
		map_size1< ft::map<int, int> >,
		map_size1< std::map<int, int> >
	);
	tester.add(
		map_size2< ft::map<int, int> >,
		map_size2< std::map<int, int> >
	);

	tester.run();
}


void test_map_capacity(void)
{
	ft::Tester tester;

	tester.printName("* CAPACITY *", true);
	test_map_size();
	test_map_max_size();
	test_map_empty();
}
