/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_observers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:35:32 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 22:19:17 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_observers.hpp"

void 	test_set_valuecomp(void)
{
	ft::Tester tester;
	
	tester.printName("value_comp()");
	tester.add(
		set_observers_valuecomp1< ft::set<int> >,
		set_observers_valuecomp1< std::set<int> >
		);

	tester.run();
}

void 	test_set_keycomp(void)
{
	ft::Tester tester;
	
	tester.printName("key_comp()");
	tester.add(
		set_observers_keycomp1< ft::set<int> >,
		set_observers_keycomp1< std::set<int> >
		);

	tester.run();
}

void test_set_observers(void)
{
	ft::Tester tester;

	tester.printName("* OBSERVERS *", true);
	test_set_keycomp();
	test_set_valuecomp();

}
