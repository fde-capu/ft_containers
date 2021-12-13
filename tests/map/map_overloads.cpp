/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_overloads.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:40:08 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_overloads.hpp"

void 	test_map_getallocator()
{
	ft::Tester tester;
	
	tester.printName("get_allocator()");
	tester.add(
		map_getallocator< ft::map<int, int> >,
		map_getallocator< std::map<int, int> >
		);
	tester.run();
}

void 	test_map_nonmemberswap(void)
{
	ft::Tester tester;

	tester.printName("swap");
	if (tester.kind == KIND_COMPARE)
	{
		tester.compare(
			map_swap< ft::map<int, int> >(ft::swap),
			map_swap< std::map<int, int> >(std::swap)
		);
	}
	std::cout << std::endl;
	if (tester.kind & (KIND_COMPARE | KIND_FT))
	{
		tester.startClock();
		map_swap< ft::map<int, int> >(ft::swap);
		tester.printClock("[ft ]");
	}
	if (tester.kind & (KIND_COMPARE | KIND_STD))
	{
		tester.startClock();
		map_swap< std::map<int, int> >(std::swap);
		tester.printClock("[std]");
	}
}

void 	test_map_relationalops(void)
{
	ft::Tester tester;

	tester.printName("relational operators");
	tester.add(
		map_relational1< ft::map<int, int> >,
		map_relational1< std::map<int, int> >
		);
	tester.add(
		map_relational2< ft::map<int, int> >,
		map_relational2< std::map<int, int> >
		);
	tester.add(
		map_relational3< ft::map<int, int> >,
		map_relational3< std::map<int, int> >
		);
	tester.add(
		map_relational4< ft::map<int, int> >,
		map_relational4< std::map<int, int> >
		);
	tester.run();
}

void test_map_overloads(void)
{
	ft::Tester tester;

	tester.printName("* ALLOCATOR *", true);
	test_map_getallocator();
	tester.printName("* NON-MEMBER FUNCTION OVERLOADS *", true);
	test_map_relationalops();
	test_map_nonmemberswap();
}
