/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elementaccess.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:34:46 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/02 13:39:14 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_elementaccess.hpp"

void 	test_map_operator_brackets(void)
{
	ft::Tester tester;
	
	tester.printName("operator[]");
	tester.add(
		map_operator_brackets1< ft::map<int, int> >,
		map_operator_brackets1< std::map<int, int> >
		);
	tester.add(
		map_operator_brackets2< ft::map<std::string, int> >,
		map_operator_brackets2< std::map<std::string, int> >
		);
	tester.add(
		map_operator_brackets3< ft::map<std::string, int> >,
		map_operator_brackets3< std::map<std::string, int> >
		);
	tester.add(
		map_operator_brackets4< ft::map<int, int> >,
		map_operator_brackets4< std::map<int, int> >
		);
	tester.run();
}

void test_map_elementaccess(void)
{
	ft::Tester tester;

	tester.printName("* ELEMENT ACCESS *", true);
	test_map_operator_brackets();
}
