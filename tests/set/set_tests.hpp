/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:44:04 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:57:42 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TESTS_HPP
# define SET_TESTS_HPP

# include "../tests.hpp"

template <typename T>
std::string set_attributes(T &v)
{
	std::string s("");

	s += "[Size: " + ft::to_string(v.size()) + "] ";
	//s += "[Max Size: " + ft::to_string(v.max_size()) + "] ";
	s += "[Content: ";
	for (typename T::iterator it = v.begin(); it != v.end(); it++)
		s += "[" + ft::to_string(*it) + "] |";
    s += "]";
	return (s);
}


template <typename Type>
Type set_presets(int i)
{
	Type s[3];

	s[0] = Type(0);
	s[1] = Type(1);
	s[2] = Type(2);
	return(s[i]);
}

template <>
std::string set_presets<std::string>(int i);
std::string randomString(const int len);

/*
** set
*/
void	test_set(void);
void    test_set_constructors(void);
void 	test_set_capacity(void);
void	test_set_iterators(void);
void	test_set_modifiers(void);
void	test_set_overloads(void);
void 	test_set_largetests(void);
void	test_set_operations(void);
void	test_set_observers(void);


#endif
