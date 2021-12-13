/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_overloads.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:40:08 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_overloads.hpp"

void 	test_set_getallocator()
{
	ft::Tester tester;
	
	tester.printName("get_allocator()");
	tester.add(
		set_getallocator< ft::set<int> >,
		set_getallocator< std::set<int> >
		);
	tester.run();
}

void 	test_set_nonmemberswap(void)
{
	ft::Tester tester;

	tester.printName("swap");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			set_swap< ft::set<int> >(ft::swap),
			set_swap< std::set<int> >(std::swap)
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		set_swap< ft::set<int> >(ft::swap);
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		set_swap< std::set<int> >(std::swap);
		tester.printClock("[std]");
	}
}

void 	test_set_relationalops(void)
{
	ft::Tester tester;

	tester.printName("relational operators");
	tester.add(
		set_relational1< ft::set<int> >,
		set_relational1< std::set<int> >
		);
	tester.add(
		set_relational2< ft::set<int> >,
		set_relational2< std::set<int> >
		);
	tester.add(
		set_relational3< ft::set<int> >,
		set_relational3< std::set<int> >
		);
	tester.add(
		set_relational4< ft::set<int> >,
		set_relational4< std::set<int> >
		);
	tester.run();
}

void test_set_overloads(void)
{
	ft::Tester tester;

	tester.printName("* ALLOCATOR *", true);
	test_set_getallocator();
	tester.printName("* NON-MEMBER FUNCTION OVERLOADS *", true);
	test_set_relationalops();
	test_set_nonmemberswap();
}
