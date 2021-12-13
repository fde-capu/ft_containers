/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_overloads.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 11:12:56 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/17 11:16:58 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_overloads.hpp"

void 	test_stack_relationalops(void)
{
	ft::Tester tester;

	tester.printName("relational operators");
	tester.add(
		stack_relational1< ft::stack<int> >,
		stack_relational1< std::stack<int> >
		);
	tester.add(
		stack_relational2< ft::stack<int> >,
		stack_relational2< std::stack<int> >
		);
	tester.add(
		stack_relational3< ft::stack<int> >,
		stack_relational3< std::stack<int> >
		);
	tester.add(
		stack_relational4< ft::stack<int> >,
		stack_relational4< std::stack<int> >
		);
	tester.run();
}

void test_stack_overloads(void)
{
	ft::Tester tester;

	tester.printName("* NON-MEMBER FUNCTION OVERLOADS *", true);
	test_stack_relationalops();
}
