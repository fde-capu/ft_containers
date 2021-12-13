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

#include "map_largetests.hpp"


void test_map_largefind_sequential(void)
{
	ft::Tester tester;

	tester.printName("Find Sequential");
	tester.add(
		map_large_find_seq1< ft::map<int, int> >,
		map_large_find_seq1< std::map<int, int> >
		);
	tester.add(
		map_large_find_seq2< ft::map<int, int> >,
		map_large_find_seq2< std::map<int, int> >
		);
	tester.run();
}

void test_map_largefind_random(void)
{
	ft::Tester tester;

	tester.printName("Find Random");
	tester.add(
		map_large_find_rnd1< ft::map<int, int> >,
		map_large_find_rnd1< std::map<int, int> >
		);
	tester.add(
		map_large_find_rnd2< ft::map<float, int> >,
		map_large_find_rnd2< std::map<float, int> >
		);
	tester.add(
		map_large_find_rnd3< ft::map<std::string, int> >,
		map_large_find_rnd3< std::map<std::string, int> >
		);
	tester.run();
}

void test_map_largeerase_random(void)
{
	ft::Tester tester;

	tester.printName("Erase Random");
	tester.add(
		map_large_erase_rnd1< ft::map<int, int> >,
		map_large_erase_rnd1< std::map<int, int> >
		);
	tester.add(
		map_large_erase_rnd2< ft::map<float, int> >,
		map_large_erase_rnd2< std::map<float, int> >
		);
	tester.add(
		map_large_erase_rnd3< ft::map<std::string, int> >,
		map_large_erase_rnd3< std::map<std::string, int> >
		);
	tester.run();
}


void test_map_largeerase_sequential(void)
{
	ft::Tester tester;

	tester.printName("Erase Sequential");
	tester.add(
		map_large_erase_seq1< ft::map<int, int> >,
		map_large_erase_seq1< std::map<int, int> >
		);
	tester.add(
		map_large_erase_seq2< ft::map<int, int> >,
		map_large_erase_seq2< std::map<int, int> >
		);
	tester.run();
}

void test_map_largeinsert_sequential(void)
{
	ft::Tester tester;

	tester.printName("Insert Sequential");
	tester.add(
		map_large_insert_seq1< ft::map<int, int> >,
		map_large_insert_seq1< std::map<int, int> >
		);
	tester.add(
		map_large_insert_seq2< ft::map<int, int> >,
		map_large_insert_seq2< std::map<int, int> >
		);
	tester.run();
}


void test_map_largeinsert_random(void)
{
	ft::Tester tester;

	tester.printName("Insert Random");
	tester.add(
		map_large_insert_rnd1< ft::map<int, int> >,
		map_large_insert_rnd1< std::map<int, int> >
		);
	tester.add(
		map_large_insert_rnd2< ft::map<float, int> >,
		map_large_insert_rnd2< std::map<float, int> >
		);
	tester.add(
		map_large_insert_rnd3< ft::map<std::string, int> >,
		map_large_insert_rnd3< std::map<std::string, int> >
		);
	tester.run();
}

void test_map_largetests(void)
{
	ft::Tester tester;

	tester.printName("* LARGE TESTS: [" + ft::to_string(ft::Tester::large_number) + "] *", true);
	test_map_largeinsert_sequential();
	test_map_largeinsert_random();
	test_map_largeerase_sequential();
	test_map_largeerase_random();
	test_map_largefind_sequential();
	test_map_largefind_random();

}
