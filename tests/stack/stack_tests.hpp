/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:44:04 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/17 11:10:56 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TESTS_HPP
# define STACK_TESTS_HPP

# include "../tests.hpp"

template <typename T>
std::string stack_attributes(T &v)
{
	std::string s("");

	s += "[Size: " + ft::to_string(v.size()) + "] ";
	s += "[Empty: " + ft::to_string(v.empty()) + "] ";
	s += "[Top: " + (v.size() ? ft::to_string(v.top()) : "") + "]";
	return (s);
}

/*
** stack
*/
void	test_stack(void);
void	test_stack_modifiers(void);
void    test_stack_overloads(void);
void	test_stack_functions(void);

#endif
