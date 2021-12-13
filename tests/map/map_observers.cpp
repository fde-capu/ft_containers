/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_observers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:35:32 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 14:50:57 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_observers.hpp"

void 	test_map_valuecomp(void)
{
	ft::Tester tester;
	
	tester.printName("value_comp()");
	tester.add(
		map_observers_valuecomp1< ft::map<int, int> >,
		map_observers_valuecomp1< std::map<int, int> >
		);

	tester.run();
}

void 	test_map_keycomp(void)
{
	ft::Tester tester;
	
	tester.printName("key_comp()");
	tester.add(
		map_observers_keycomp1< ft::map<int, int> >,
		map_observers_keycomp1< std::map<int, int> >
		);

	tester.run();
}

void test_map_observers(void)
{
	ft::Tester tester;

	tester.printName("* OBSERVERS *", true);
	test_map_keycomp();
	test_map_valuecomp();

}
