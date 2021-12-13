/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:38:44 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_capacity.hpp"

void test_vector_reserve(void)
{
	ft::Tester tester;

	tester.printName("reserve()");
	tester.add(
		vector_reserve< ft::vector<int> >,
		vector_reserve< std::vector<int> >
	);
	tester.run();

}

void test_vector_empty(void)
{
	ft::Tester tester;

	tester.printName("empty()");
	tester.add(
		vector_empty< ft::vector<int> >,
		vector_empty< std::vector<int> >
	);
	tester.run();
}

void test_vector_resize(void)
{
	ft::Tester tester;

	tester.printName("resize()");
	tester.add(
		resize1< ft::vector<int> >,
		resize1< std::vector<int> >
	);
	tester.add(
		resize2< ft::vector<float> >,
		resize2< std::vector<float> >
	);
	tester.run();
}

void test_vector_max_size(void)
{
	ft::Tester tester;

	tester.printName("max_size()");
	tester.add(
		max_size< ft::vector<int> >,
		max_size< std::vector<int> >
	);
	tester.add(
		max_size< ft::vector<std::string> >,
		max_size< std::vector<std::string> >
	);
	tester.run();
}

void test_vector_size(void)
{
	ft::Tester tester;

	tester.printName("size()");
	tester.add(
		size1< ft::vector<int> >,
		size1< std::vector<int> >
	);
	tester.add(
		size2< ft::vector<int> >,
		size2< std::vector<int> >
	);
	tester.run();
}

void test_vector_cap(void)
{
	ft::Tester tester;

	tester.printName("capacity()");
	tester.add(
		capacity1< ft::vector<int> >,
		capacity1< std::vector<int> >
	);
	tester.add(
		capacity2< ft::vector<int> >,
		capacity2< std::vector<int> >
	);
	tester.run();
}

void test_vector_capacity(void)
{
	ft::Tester tester;

	tester.printName("* CAPACITY *", true);
	test_vector_size();
	test_vector_max_size();
	test_vector_resize();
	test_vector_cap();
	test_vector_empty();
	test_vector_reserve();
}
