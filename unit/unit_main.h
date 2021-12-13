/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_main.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:52:21 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/13 17:20:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_MAIN_H
# define UNIT_MAIN_H

#if STL
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include "../vector.hpp"
	#include "../stack.hpp"
	#include "../map.hpp"
	#include "../set.hpp"
#endif

# include "Chronometer.hpp"

# define UNIT_COLUMNS 6
# define NOT_EQUAL false

static size_t g_test_ok;
static size_t g_test_ko;

int main(int argc, char** argv);
int ft_main(int argc, char** argv);
int unit_main(int argc, char** argv);

void title(std::string str);
void foo_function();
int random_int(int min, int max);
unsigned char random_char();

# include "check_helpers.h"
# include "check_vector.h"
# include "check_iterator.h"
# include "check_pair.h"
# include "check_is_integral.h"
# include "check_enable_if.h"
# include "check_stack.h"
# include "check_map.h"
# include "check_set.h"
# include "check_eq_lexico.h"

# define _FT_			(1 << 0)
# define _PAIR_			(1 << 1)
# define _IS_INTEGRAL_	(1 << 2)
# define _ENABLE_IF_	(1 << 3)
# define _ITERATOR_		(1 << 4)
# define _VECTOR_		(1 << 5)
# define _STACK_		(1 << 6)
# define _MAP_A_		(1 << 7)
# define _SET_			(1 << 8)
# define _EQ_LEXICO_	(1 << 9)
# define _MAP_B_		(1 << 10)
# define _MAP_C_		(1 << 11)
# define _MAP_D_		(1 << 12)
# define _MAP_E_		(1 << 13)
# define _GENERAL_		(1 << 14)

# define _MAP_ _MAP_A_ + _MAP_B_ + _MAP_C_ + _MAP_D_ + _MAP_E_
# define _ALL_ _FT_ + _PAIR_ + _IS_INTEGRAL_ + _ENABLE_IF_ + _ITERATOR_ + _VECTOR_ + _STACK_ + _MAP_ + _SET_ + _EQ_LEXICO_
# define _SIMPLE_ _FT_ + _GENERAL_
# define _EXTRAS_ _FT_ + _PAIR_ + _IS_INTEGRAL_ + _ENABLE_IF_ + _ITERATOR_ + _EQ_LEXICO_
# define _VECSTACK_ _VECTOR_ + _STACK_

# ifndef SECTION
#  define SECTION _SIMPLE_
# endif

//# define SECTION _PAIR_
//# define SECTION _FT_
//# define SECTION _IS_INTEGRAL_
//# define SECTION _ENABLE_IF_
//# define SECTION _ITERATOR_
//# define SECTION _EQ_LEXICO_

//# define SECTION _VECTOR_
//# define SECTION _STACK_

//# define SECTION _SET_

//# define SECTION _MAP_

#endif
