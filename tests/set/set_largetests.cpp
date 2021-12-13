/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_constructors.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:38:56 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_largetests.hpp"


void test_set_largefind_sequential(void)
{
	ft::Tester tester;

	tester.printName("Find Sequential");
	tester.add(
		set_large_find_seq1< ft::set<int> >,
		set_large_find_seq1< std::set<int> >
		);
	tester.add(
		set_large_find_seq2< ft::set<int> >,
		set_large_find_seq2< std::set<int> >
		);
	tester.run();
}

void test_set_largefind_random(void)
{
	ft::Tester tester;

	tester.printName("Find Random");
	tester.add(
		set_large_find_rnd1< ft::set<int> >,
		set_large_find_rnd1< std::set<int> >
		);
	tester.add(
		set_large_find_rnd2< ft::set<float> >,
		set_large_find_rnd2< std::set<float> >
		);
	tester.add(
		set_large_find_rnd3< ft::set<std::string> >,
		set_large_find_rnd3< std::set<std::string> >
		);
	tester.run();
}

void test_set_largeerase_random(void)
{
	ft::Tester tester;

	tester.printName("Erase Random");
	tester.add(
		set_large_erase_rnd1< ft::set<int> >,
		set_large_erase_rnd1< std::set<int> >
		);
	tester.add(
		set_large_erase_rnd2< ft::set<float> >,
		set_large_erase_rnd2< std::set<float> >
		);
	tester.add(
		set_large_erase_rnd3< ft::set<std::string> >,
		set_large_erase_rnd3< std::set<std::string> >
		);
	tester.run();
}


void test_set_largeerase_sequential(void)
{
	ft::Tester tester;

	tester.printName("Erase Sequential");
	tester.add(
		set_large_erase_seq1< ft::set<int> >,
		set_large_erase_seq1< std::set<int> >
		);
	tester.add(
		set_large_erase_seq2< ft::set<int> >,
		set_large_erase_seq2< std::set<int> >
		);
	tester.run();
}

void test_set_largeinsert_sequential(void)
{
	ft::Tester tester;

	tester.printName("Insert Sequential");
	tester.add(
		set_large_insert_seq1< ft::set<int> >,
		set_large_insert_seq1< std::set<int> >
		);
	tester.add(
		set_large_insert_seq2< ft::set<int> >,
		set_large_insert_seq2< std::set<int> >
		);
	tester.run();
}


void test_set_largeinsert_random(void)
{
	ft::Tester tester;

	tester.printName("Insert Random");
	tester.add(
		set_large_insert_rnd1< ft::set<int> >,
		set_large_insert_rnd1< std::set<int> >
		);
	tester.add(
		set_large_insert_rnd2< ft::set<float> >,
		set_large_insert_rnd2< std::set<float> >
		);
	tester.add(
		set_large_insert_rnd3< ft::set<std::string> >,
		set_large_insert_rnd3< std::set<std::string> >
		);
	tester.run();
}

void test_set_largetests(void)
{
	ft::Tester tester;

	tester.printName("* LARGE TESTS: [" + ft::to_string(ft::Tester::large_number) + "] *", true);
	test_set_largeinsert_sequential();
	test_set_largeinsert_random();
	test_set_largeerase_sequential();
	test_set_largeerase_random();
	test_set_largefind_sequential();
	test_set_largefind_random();

}
