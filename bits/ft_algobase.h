/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algobase.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:57:13 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/19 18:57:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGOBASE_H
# define FT_ALGOBASE_H

namespace ft
{

	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare (InputIt1 first1, InputIt1 last1,
		InputIt2 first2, InputIt2 last2, Compare comp)
	{
		while ((first1 != last1) && (first2 != last2))
		{
			if (comp(*first1, *first2))
				return (true);
			else if (comp(*first2, *first1))
				return(false);
			first1++;
			first2++;
		}
		return ((first1 == last1) && (first2 != last2));
	}


	template<typename I1, typename I2>
		bool lexicographical_compare
		(I1 a_s, I1 a_e, I2 b_s, I2 b_e)
		{
			while (a_s != a_e && b_s != b_e)
			{
				if (*a_s < *b_s)
					return true;
				if (*b_s < *a_s)
					return false;
				++a_s;
				++b_s;
			}
			return a_s == a_e && b_s != b_e;
		}

	template<typename I1, typename I2>
		bool equal(I1 a_h, I1 a_e, I2 b_h)
		{
			return \
				a_h == a_e			?	true	:
				(!(*a_h == *b_h))	?	false	:
												ft::equal(++a_h, a_e, ++b_h);
		}

	template<typename I1, typename I2, typename BinPredicate>
		bool equal(I1 a_h, I1 a_e, I2 b_h, BinPredicate p)
		{
			return \
				a_h == a_e			?	true	:
				(!p(*a_h, *b_h))	?	false	:
												ft::equal(++a_h, a_e, ++b_h, p);
		}

	template<typename Pa, typename Pb>
		void swap(Pa& a, Pb& b)
		{
			Pa foo = a;
			a = b;
			b = foo;
		}
}

#endif
