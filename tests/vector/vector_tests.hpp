/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:44:04 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/23 15:24:26 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TESTS_HPP
# define VECTOR_TESTS_HPP

#include "../tests.hpp"

template <typename T>
std::string vector_attributes(T &v)
{
	std::string s("");

	s += "[Capacity: " + ft::to_string(v.capacity()) + "] ";
	s += "[Size: " + ft::to_string(v.size()) + "] ";
	s += "[Max Size: " + ft::to_string(v.max_size()) + "] ";
	s += "[Content: ";
	for (typename T::iterator it = v.begin(); it != v.end(); it++)
		s += ft::to_string(*it) + "|";
    s += "]";
	return (s);
}

/*
** vector
*/
void	test_vector(void);
void    test_vector_constructors(void);
void 	test_vector_capacity(void);
void	test_vector_iterators(void);
void	test_vector_elementaccess(void);
void	test_vector_modifiers(void);
void	test_vector_overloads(void);
void	test_vector_largetests(void);


#endif
