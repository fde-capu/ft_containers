/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:39:31 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_iterators.hpp"

void test_vector_iterator_end(void)
{
	ft:: Tester tester;
	tester.printName("end()");
	tester.add(
		iterator_end1< ft::vector<int> >,
		iterator_end1< std::vector<int> >
	);
	tester.run();
}

void test_vector_iterator_begin(void)
{
	ft:: Tester tester;

	tester.printName("begin()");
	tester.add(
		iterator_begin1< ft::vector<int> >,
		iterator_begin1< std::vector<int> >
	);
	tester.run();
}

void test_vector_iterator_rend(void)
{
	ft:: Tester tester;

	tester.printName("rend()");
	tester.add(
		iterator_rend1< ft::vector<int> >,
		iterator_rend1< std::vector<int> >
	);
	tester.run();
}

void test_vector_iterator_rbegin(void)
{
	ft:: Tester tester;

	tester.printName("rbegin()");
	tester.add(
		iterator_rbegin1< ft::vector<int> >,
		iterator_rbegin1< std::vector<int> >
	);
	tester.run();
}

void test_vector_iterators(void)
{
	ft:: Tester tester;

	tester.printName("* ITERATORS *", true);
	test_vector_iterator_begin();
	test_vector_iterator_end();
	test_vector_iterator_rbegin();
	test_vector_iterator_rend();
}
