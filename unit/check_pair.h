/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pair.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:57:47 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/08 11:57:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_PAIR_H
# define CHECK_PAIR_H

# include <typeinfo>

template<typename TA, typename TB>
void check_pair()
{
	title("PAIR");
	std::cout << "Types:\t" << typeid(TA).name() << ", " << typeid(TB).name() << std::endl;
	title("Member types");
	check(1, typeid(typename ft::pair<TA, TB>::first_type).name(), typeid(TA).name());
	check(2, typeid(typename ft::pair<TA, TB>::second_type).name(), typeid(TB).name());

	title("Member vars");
	{
		ft::pair<TA, TB> empty_pair = ft::pair<TA, TB>();
		check(1, typeid(empty_pair.first).name(), typeid(TA).name());
		check(2, typeid(empty_pair.second).name(), typeid(TB).name());
		check(3, empty_pair.first, TA());
		check(4, empty_pair.second, TB());
		ft::pair<TA, TB> valued_pair(TA(4), TB(2));
		check(5, valued_pair.first, TA(4));
		check(6, valued_pair.second, TB(2));
	}

	title("Member funcs");
	{
		ft::pair<TA, TB> pp;
		check(1, pp, ft::pair<TA, TB>());
		check(2, pp, ft::pair<TA, TB>(TA(), TB()));
		ft::pair<TA, TB> dd(pp);
		check(3, dd.first, pp.first);
		check(4, dd.second, pp.second);
		ft::pair<TA, TB> valued_pair(TA(4), TB(2));
		check(5, valued_pair.first, TA(4));
		check(6, valued_pair.second, TB(2));
		ft::pair<TA, TB> copy_valued = valued_pair;
		check(7, copy_valued.first, TA(4));
		check(8, copy_valued.second, TB(2));
	}

	title("Relational");
	{
		ft::pair<TA, TB> pp_a(TA(4), TB(2));
		ft::pair<TA, TB> pp_b(TA(4), TB(2));
		ft::pair<TA, TB> pp_e; // empty
		ft::pair<TA, TB> pp_f(TA(3), TB(4));
		ft::pair<TA, TB> pp_g(TA(5), TB(1));
		ft::pair<TA, TB> pp_h(TA(5), TB(3));
		ft::pair<TA, TB> pp_i(TA(3), TB(1));

		check(1, pp_a == pp_b, true);
		check(2, pp_a == pp_h, false);
		check(3, pp_a == pp_e, false);
		check(4, pp_h == pp_e, false);
		check(5, pp_e == pp_a, false);
		check(6, pp_a == pp_f, false);

		check(7, pp_a != pp_b, false);
		check(8, pp_a != pp_h, true);
		check(9, pp_a != pp_e, true);
		check(10, pp_h != pp_e, true);
		check(11, pp_e != pp_a, true);

		check(12, pp_a < pp_b, false);
		check(13, pp_a < pp_e, false);
		check(14, pp_a < pp_f, false);
		check(15, pp_a < pp_g, true);
		check(16, pp_a < pp_h, true);
		check(17, pp_a < pp_i, false);

		check(18, pp_a > pp_b, false);
		check(19, pp_a > pp_e, true);
		check(20, pp_a > pp_f, true);
		check(21, pp_a > pp_g, false);
		check(22, pp_a > pp_h, false);
		check(23, pp_a > pp_i, true);

		check(24, pp_a <= pp_b, true);
		check(25, pp_a <= pp_e, false);
		check(26, pp_a <= pp_f, false);
		check(27, pp_a <= pp_g, true);
		check(28, pp_a <= pp_h, true);
		check(29, pp_a <= pp_i, false);

		check(30, pp_a >= pp_b, true);
		check(31, pp_a >= pp_e, true);
		check(32, pp_a >= pp_f, true);
		check(33, pp_a >= pp_g, false);
		check(34, pp_a >= pp_h, false);
		check(35, pp_a >= pp_i, true);
	}

	title("make_pair()");
	{
		try
		{
			ft::pair<TA, TB> pp_a = ft::make_pair(TA(4), TB(2));
			static_cast<void>(pp_a);
			check(1, 1, 1);
		}
		catch (std::exception& e)
		{
			check(1, "make_pair() not implemented", "stl");
		}
		ft::pair<TA, TB> pp_a = ft::make_pair(TA(4), TB(2));
		ft::pair<TA, TB> pp_e = ft::make_pair(TA(), TB());
		check(2, pp_e, ft::pair<TA, TB>());
		check(3, pp_e, pp_a, NOT_EQUAL);
		check(4, pp_a.first, TA(4));
		check(5, pp_a.second, TB(2));
	}
}

#endif
