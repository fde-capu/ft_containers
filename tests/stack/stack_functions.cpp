/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:19:23 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/17 11:03:11 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_functions.hpp"

void 	test_stack_constructors()
{
	ft::Tester tester;

	tester.printName("Default Constructor");
	tester.add(
		stack_constructor1< ft::stack<int> >,
		stack_constructor1< std::stack<int> >
		);
	tester.add(
		stack_constructor2< ft::stack<int> >,
		stack_constructor2< std::stack<int> >
		);
	tester.add(
		stack_constructor1< ft::stack<int, ft::vector<int> > >,
		stack_constructor1< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_constructor1< ft::stack<int, std::vector<int> > >,
		stack_constructor1< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_constructor1< ft::stack<int, std::deque<int> > >,
		stack_constructor1< std::stack<int, std::deque<int> > >
		);
	tester.add(
		stack_constructor3< ft::stack<int, ft::vector<int> > >,
		stack_constructor3< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_constructor3< ft::stack<int, std::vector<int> > >,
		stack_constructor3< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_constructor3< ft::stack<int, std::deque<int> > >,
		stack_constructor3< std::stack<int, std::deque<int> > >
		);
	tester.run();
}

void 	test_stack_empty()
{
	ft::Tester tester;

	tester.printName("empty()");
	tester.add(
		stack_empty1< ft::stack<int> >,
		stack_empty1< std::stack<int> >
		);
	tester.add(
		stack_empty2< ft::stack<int> >,
		stack_empty2< std::stack<int> >
		);
	tester.add(
		stack_empty1< ft::stack<int, ft::vector<int> > >,
		stack_empty1< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_empty1< ft::stack<int, std::vector<int> > >,
		stack_empty1< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_empty1< ft::stack<int, std::deque<int> > >,
		stack_empty1< std::stack<int, std::deque<int> > >
		);
	tester.add(
		stack_empty2< ft::stack<int, ft::vector<int> > >,
		stack_empty2< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_empty2< ft::stack<int, std::vector<int> > >,
		stack_empty2< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_empty2< ft::stack<int, std::deque<int> > >,
		stack_empty2< std::stack<int, std::deque<int> > >
		);

	tester.run();
}

void 	test_stack_size()
{
	ft::Tester tester;

	tester.printName("size()");
	tester.add(
		stack_size1< ft::stack<int> >,
		stack_size1< std::stack<int> >
		);
	tester.add(
		stack_size2< ft::stack<int> >,
		stack_size2< std::stack<int> >
		);
	tester.add(
		stack_size1< ft::stack<int, ft::vector<int> > >,
		stack_size1< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_size1< ft::stack<int, std::vector<int> > >,
		stack_size1< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_size1< ft::stack<int, std::deque<int> > >,
		stack_size1< std::stack<int, std::deque<int> > >
		);
	tester.add(
		stack_size2< ft::stack<int, ft::vector<int> > >,
		stack_size2< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_size2< ft::stack<int, std::vector<int> > >,
		stack_size2< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_size2< ft::stack<int, std::deque<int> > >,
		stack_size2< std::stack<int, std::deque<int> > >
		);

	tester.run();
}

void 	test_stack_top()
{
	ft::Tester tester;

	tester.printName("top()");
	tester.add(
		stack_top1< ft::stack<int> >,
		stack_top1< std::stack<int> >
		);
	tester.add(
		stack_top2< ft::stack<int> >,
		stack_top2< std::stack<int> >
		);
	tester.add(
		stack_top1< ft::stack<int, ft::vector<int> > >,
		stack_top1< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_top1< ft::stack<int, std::vector<int> > >,
		stack_top1< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_top1< ft::stack<int, std::deque<int> > >,
		stack_top1< std::stack<int, std::deque<int> > >
		);
	tester.add(
		stack_top2< ft::stack<int, ft::vector<int> > >,
		stack_top2< std::stack<int, ft::vector<int> > >
		);
	tester.add(
		stack_top2< ft::stack<int, std::vector<int> > >,
		stack_top2< std::stack<int, std::vector<int> > >
		);
	tester.add(
		stack_top2< ft::stack<int, std::deque<int> > >,
		stack_top2< std::stack<int, std::deque<int> > >
		);

	tester.run();
}

void test_stack_functions(void)
{
	ft::Tester tester;

	tester.printName("* CONSTRUCTORS *", true);
	test_stack_constructors();
	tester.printName("* MEMBER FUNCTIONS *", true);
	test_stack_empty();
	test_stack_size();
	test_stack_top();
}
