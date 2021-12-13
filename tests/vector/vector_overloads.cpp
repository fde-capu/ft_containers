/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_overloads.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:40:08 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_overloads.hpp"

void 	test_vector_getallocator()
{
	ft::Tester tester;
	
	tester.printName("get_allocator()");
	tester.add(
		vector_getallocator< ft::vector<int> >,
		vector_getallocator< std::vector<int> >
		);
	tester.run();
}

void 	test_vector_nonmemberswap(void)
{
	ft::Tester tester;

	tester.printName("swap");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			vector_swap< ft::vector<int> >(ft::swap),
			vector_swap< std::vector<int> >(std::swap)
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		vector_swap< ft::vector<int> >(ft::swap);
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		vector_swap< std::vector<int> >(std::swap);
		tester.printClock("[std]");
	}
}

void 	test_vector_relationalops(void)
{
	ft::Tester tester;

	tester.printName("relational operators");
	tester.add(
		vector_relational1< ft::vector<int> >,
		vector_relational1< std::vector<int> >
		);
	tester.add(
		vector_relational2< ft::vector<int> >,
		vector_relational2< std::vector<int> >
		);
	tester.add(
		vector_relational3< ft::vector<int> >,
		vector_relational3< std::vector<int> >
		);
	tester.add(
		vector_relational4< ft::vector<int> >,
		vector_relational4< std::vector<int> >
		);
	tester.run();
}

void test_vector_overloads(void)
{
	ft::Tester tester;

	tester.printName("* ALLOCATOR *", true);
	test_vector_getallocator();
	tester.printName("* NON-MEMBER FUNCTION OVERLOADS *", true);
	test_vector_relationalops();
	test_vector_nonmemberswap();
}
