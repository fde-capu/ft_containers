/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eq_lexico.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:43:13 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/09 13:36:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_EQ_LEXICO_H
# define CHECK_EQ_LEXICO_H

# include "check_helpers.h"

template<typename K, typename V>
void check_eq_lexico()
{
	title("ft::lexicographical_compare");
	std::cout << std::endl << "\t\t";

	ft::map<K, V> ma;
	ma[K(7)] = V(1);
	ma[K(9)] = V(11);
	ma[K(3)] = V(1);
	ma[K(13)] = V(21);

	check(1, ft::lexicographical_compare(
		ma.begin(), ma.begin(), ma.begin(), ma.begin()
	), false);

	check(2, ft::lexicographical_compare(
		ma.begin(), ++ma.begin(), ma.begin(), ++ma.begin()
	), false);

	check(3, ft::lexicographical_compare(
		ma.begin(), ++++ma.begin(), ma.begin(), ++ma.begin()
	), false);

	check(4, ft::lexicographical_compare(
		ma.begin(), ++ma.begin(), ma.begin(), ++++ma.begin()
	), true);

	check(5, ft::lexicographical_compare(
		ma.begin(), ++++ma.begin(), ma.begin(), ++++ma.begin()
	), false);

	check(6, ft::lexicographical_compare(
		ma.begin(), ++++ma.begin(), ma.begin(), ++++++ma.begin()
	), true);

	{
		ft::map<K, V> mb(ma);
		mb[K(3)] = V(2);

		check(7, ft::lexicographical_compare(
			ma.begin(), ++ma.begin(), mb.begin(), ++++mb.begin() // ma/mb (...)
		), true);

		mb[K(3)] = V(0);

		check(8, ft::lexicographical_compare(
			ma.begin(), ++ma.begin(), mb.begin(), ++++mb.begin()
		), false);

		mb[K(2)] = V(22);

		check(9, ft::lexicographical_compare(
			ma.begin(), ++ma.begin(), mb.begin(), ++++mb.begin()
		), false);

		mb[K(2)] = V(0);

		check(10, ft::lexicographical_compare(
			ma.begin(), ++ma.begin(), mb.begin(), ++++mb.begin()
		), false);

		mb.erase(K(2));
		mb.erase(K(3));

		check(11, ft::lexicographical_compare(
			ma.begin(), ++++ma.begin(), mb.begin(), ++++mb.begin()
		), true);
	}

	{
		ft::map<K, V> mb(ma);
		mb[K(9)] = V(12);

		check(12, ft::lexicographical_compare(
			ma.begin(), ma.end(), mb.begin(), mb.end()
		), true);

		mb[K(9)] = V(10);

		check(13, ft::lexicographical_compare(
			ma.begin(), ma.end(), mb.begin(), mb.end()
		), false);
	}

	title("ft::equal");

	ft::map<K, V> mc;
	mc[K(0)] = V(5);
	mc[K(1)] = V(3);
	mc[K(2)] = V(3);
	mc[K(3)] = V(5);

	check(1, ft::equal(mc.begin(), mc.begin(), mc.begin()), true);
	check(2, ft::equal(mc.begin(), ++mc.begin(), mc.begin()), true);
	check(3, ft::equal(mc.begin(), mc.end(), mc.begin()), true);
	check(4, ft::equal(mc.begin(), mc.end(), ++++mc.begin()), false);
	check(5, ft::equal(++mc.begin(), --mc.end(), ++mc.begin()), true);
	check(6, ft::equal(mc.begin(), mc.begin(), --mc.end()), true);
	check(7, ft::equal(++mc.begin(), ++mc.begin(), ++++mc.begin()), true);

	ft::map<K, V> md(mc);
	md[K(2)] = V(4);

	check(8, ft::equal(mc.begin(), ----mc.end(), md.begin()), true);
	check(9, ft::equal(mc.begin(), --mc.end(), md.begin()), false);
	check(10, ft::equal(++mc.begin(), ++mc.begin(), ++md.begin()), true);
	check(11, ft::equal(++mc.begin(), ++++mc.begin(), ++md.begin()), true);
	check(12, ft::equal(++mc.begin(), ++++mc.begin(), ++++md.begin()), false);
	check(13, ft::equal(++mc.begin(), mc.end(), ++md.begin()), false);

	title("eq bool pred.");

	ft::vector<V> va;
	va.push_back(V(22));
	va.push_back(V(100));
	va.push_back(V(15));
	va.push_back(V(11));
	va.push_back(V(42));

	check(1, ft::equal(va.begin(), va.end(), va.begin(), range_ten<V>), true);
	check(2, ft::equal(----va.end(), va.end(), va.begin(), range_ten<V>), false);
	check(3, ft::equal(--va.end(), va.end(), ----va.end(), range_ten<V>), false);

	ft::vector<V> vb(va);
	check(4, ft::equal(va.begin(), --va.end(), vb.begin(), range_ten<V>), true);
	check(5, ft::equal(--va.end(), va.end(), ----vb.end(), range_ten<V>), false);
	check(6, ft::equal(va.begin(), --va.end(), ++vb.begin(), range_ten<V>), false);

}

#endif
