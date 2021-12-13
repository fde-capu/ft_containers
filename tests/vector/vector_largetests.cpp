/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_largetests.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:17:24 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/23 16:02:23 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector_largetests.hpp"


void test_vector_largeswap_random(void)
{
	ft::Tester tester;

	tester.printName("Swap Random");
	tester.add(
		vector_large_swap_random< ft::vector<int> >,
		vector_large_swap_random< std::vector<int> >
		);
	tester.add(
		vector_large_swap_random< ft::vector<float> >,
		vector_large_swap_random< std::vector<float> >
		);
	tester.add(
		vector_large_swap_random< ft::vector<ft::s_buffer> >,
		vector_large_swap_random< std::vector<ft::s_buffer> >
		);
	tester.run();
}

void test_vector_largeaccess_random(void)
{
	ft::Tester tester;

	tester.printName("Access Random");
	tester.add(
		vector_large_access_random< ft::vector<int> >,
		vector_large_access_random< std::vector<int> >
		);
	tester.add(
		vector_large_access_random< ft::vector<float> >,
		vector_large_access_random< std::vector<float> >
		);
	tester.add(
		vector_large_access_rndbuf< ft::vector<ft::s_buffer> >,
		vector_large_access_rndbuf< std::vector<ft::s_buffer> >
		);
	tester.run();
}


void test_vector_largeinsert_random(void)
{
	ft::Tester tester;

	tester.printName("Insert Random");
	tester.add(
		vector_large_insert_random< ft::vector<int> >,
		vector_large_insert_random< std::vector<int> >
		);
	tester.add(
		vector_large_insert_random< ft::vector<float> >,
		vector_large_insert_random< std::vector<float> >
		);
	tester.add(
		vector_large_insert_rndbuf< ft::vector<ft::s_buffer> >,
		vector_large_insert_rndbuf< std::vector<ft::s_buffer> >
		);
	tester.run();
}

void test_vector_largetests(void)
{
	ft::Tester tester;

	tester.printName("* LARGE TESTS: [" + ft::to_string(ft::Tester::large_number) + "] *", true);
	test_vector_largeinsert_random();
	test_vector_largeaccess_random();
	test_vector_largeswap_random();
}
