/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverseiterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:54:24 by iwillens          #+#    #+#             */
/*   Updated: 2021/12/14 15:04:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_reverseiterator.hpp"
void test_reverseiterator(void)
{
    ft::Tester tester; 

    tester.printName("ft::reverse_iterator");
    tester.add(
        test1< ft::vector<int> >,
        test1< std::vector<int> >
        );
    tester.add(
        test2< ft::vector< ft::vector<int> >, ft::vector<int> >,
        test2< std::vector< std::vector<int> >, std::vector<int> >
        );
    tester.add(
        test3< ft::vector<char> >,
        test3< std::vector<char> >
        );
    tester.add(
        test4< ft::vector<int>, ft::reverse_iterator<ft::vector<int>::iterator> >,
        test4< std::vector<int>, std::reverse_iterator<std::vector<int>::iterator> >
    );
    tester.run();
}
