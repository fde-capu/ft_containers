/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:44:04 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 23:59:04 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TESTS_HPP
# define MAP_TESTS_HPP

# include "../tests.hpp"

template <typename T>
std::string map_attributes(T &v)
{
	std::string s("");

	s += "[Size: " + ft::to_string(v.size()) + "] ";
	//s += "[Max Size: " + ft::to_string(v.max_size()) + "] ";
	s += "[Content: ";
	for (typename T::iterator it = v.begin(); it != v.end(); it++)
		s += "[" + ft::to_string(it->first) + ":" + ft::to_string(it->second) + "] |";
    s += "]";
	return (s);
}


template <typename Type>
Type map_presets(int i)
{
	Type s[3];

	s[0] = Type(0);
	s[1] = Type(1);
	s[2] = Type(2);
	return(s[i]);
}

template <>
std::string map_presets<std::string>(int i);
std::string randomString(const int len);

/*
** map
*/
void	test_map(void);
void    test_map_constructors(void);
void 	test_map_capacity(void);
void	test_map_iterators(void);
void	test_map_elementaccess(void);
void	test_map_modifiers(void);
void	test_map_overloads(void);
void 	test_map_largetests(void);
void	test_map_operations(void);
void	test_map_observers(void);


#endif
