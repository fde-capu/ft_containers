/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:43:31 by iwillens          #+#    #+#             */
/*   Updated: 2021/12/13 17:57:16 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include "Tester.hpp"

/*
** std:: includes
*/
# include <vector>
# include <map>
# include <set>
# include <stack>
# include <iostream>
# include <limits>
# include <algorithm>

/*
** ft:: includes
*/

# include "../vector.hpp"
# include "../map.hpp"
# include "../stack.hpp"
# include "../set.hpp"
# include "../bits/ft_algobase.h"
# include "../bits/ft_iterator_base_funcs.h"
# include "../bits/ft_iterator_base_types.h"
# include "../bits/ft_iterator.h"
# include "../bits/type_traits.h"
# include "../bits/ft_pair.h"
# include "../bits/ft_tree.h"

/*
** tests
*/

# include "./utilities/test_utilities.hpp"
# include "./vector/vector_tests.hpp"
# include "./map/map_tests.hpp"
# include "./stack/stack_tests.hpp"
# include "./set/set_tests.hpp"

# ifndef ORIGINAL_STD
#  define ORIGINAL_STD	0
# endif

#endif
