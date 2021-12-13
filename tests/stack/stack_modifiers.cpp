/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_modifiers.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:19:45 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/17 11:08:46 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_modifiers.hpp"


void 	test_stack_push()
{
	ft::Tester tester;

	tester.printName("push()");
	tester.add(
		stack_push1< ft::stack<int> >,
		stack_push1< std::stack<int> >
		);
	tester.add(
		stack_push2< ft::stack<int> >,
		stack_push2< std::stack<int> >
		);
	tester.add(
		stack_push1< ft::stack<int, ft::vector<int> > >,
		stack_push1< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_push1< ft::stack<int, std::vector<int> > >,
		stack_push1< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_push1< ft::stack<int, std::deque<int> > >,
		stack_push1< std::stack<int, std::deque<int> > >
		);
	tester.add(
		stack_push2< ft::stack<int, ft::vector<int> > >,
		stack_push2< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_push2< ft::stack<int, std::vector<int> > >,
		stack_push2< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_push2< ft::stack<int, std::deque<int> > >,
		stack_push2< std::stack<int, std::deque<int> > >
		);

	tester.run();
}

void 	test_stack_pop()
{
	ft::Tester tester;

	tester.printName("pop()");
	tester.add(
		stack_pop1< ft::stack<int> >,
		stack_pop1< std::stack<int> >
		);
	tester.add(
		stack_pop2< ft::stack<int> >,
		stack_pop2< std::stack<int> >
		);
	tester.add(
		stack_pop1< ft::stack<int, ft::vector<int> > >,
		stack_pop1< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_pop1< ft::stack<int, std::vector<int> > >,
		stack_pop1< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_pop1< ft::stack<int, std::deque<int> > >,
		stack_pop1< std::stack<int, std::deque<int> > >
		);
	tester.add(
		stack_pop2< ft::stack<int, ft::vector<int> > >,
		stack_pop2< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_pop2< ft::stack<int, std::vector<int> > >,
		stack_pop2< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_pop2< ft::stack<int, std::deque<int> > >,
		stack_pop2< std::stack<int, std::deque<int> > >
		);

	tester.run();
}


void test_stack_modifiers(void)
{
	ft::Tester tester;

	tester.printName("* MODIFIERS *", true);
	test_stack_push();
	test_stack_pop();
}
