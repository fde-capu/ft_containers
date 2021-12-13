/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:39:53 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_modifiers.hpp"

void 	test_vector_assign()
{

	ft::Tester tester;

	tester.printName("assign()");
	tester.add(
		vector_assign1< ft::vector<int> >,
		vector_assign1< std::vector<int> >
		);
	tester.add(
		vector_assign2< ft::vector<int> >,
		vector_assign2< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_pushback()
{
	ft::Tester tester;

	tester.printName("push_back()");
	tester.add(
		vector_pushback1< ft::vector<int> >,
		vector_pushback1< std::vector<int> >
		);
	tester.add(
		vector_pushback2< ft::vector<int> >,
		vector_pushback2< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_popback()
{
	ft::Tester tester;

	tester.printName("pop_back()");
	tester.add(
		vector_popback1< ft::vector<int> >,
		vector_popback1< std::vector<int> >
		);
	tester.add(
		vector_popback2< ft::vector<int> >,
		vector_popback2< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_insert()
{
	ft::Tester tester;

	tester.printName("insert()");
	tester.add(
		vector_insert1< ft::vector<int> >,
		vector_insert1< std::vector<int> >
		);
	tester.add(
		vector_insert2< ft::vector<int> >,
		vector_insert2< std::vector<int> >
		);
	tester.add(
		vector_insert3< ft::vector<int> >,
		vector_insert3< std::vector<int> >
		);
	tester.add(
		vector_insert4< ft::vector<int> >,
		vector_insert4< std::vector<int> >
		);
	tester.add(
		vector_insert5< ft::vector<int> >,
		vector_insert5< std::vector<int> >
		);
	tester.add(
		vector_insert6< ft::vector<int> >,
		vector_insert6< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_erase()
{
	ft::Tester tester;

	tester.printName("erase()");
	tester.add(
		vector_erase1< ft::vector<int> >,
		vector_erase1< std::vector<int> >
		);
	tester.add(
		vector_erase2< ft::vector<int> >,
		vector_erase2< std::vector<int> >
		);
	tester.add(
		vector_erase3< ft::vector<int> >,
		vector_erase3< std::vector<int> >
		);
	tester.add(
		vector_erase4< ft::vector<int> >,
		vector_erase4< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_swap()
{
	ft::Tester tester;

	tester.printName("swap()");
	tester.add(
		vector_swap< ft::vector<int> >,
		vector_swap< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_clear()
{
	ft::Tester tester;

	tester.printName("clear()");
	tester.add(
		vector_clear< ft::vector<int> >,
		vector_clear< std::vector<int> >
		);
	tester.run();
}

void test_vector_modifiers(void)
{
	ft::Tester tester;

	tester.printName("* MODIFIERS *", true);
	test_vector_assign();
	test_vector_pushback();
	test_vector_popback();
	test_vector_insert();
	test_vector_erase();
	test_vector_swap();
	test_vector_clear();
}
