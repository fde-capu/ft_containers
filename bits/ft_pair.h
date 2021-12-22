/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:38:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/22 21:42:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PAIR_H
# define FT_PAIR_H

namespace ft
{
	template <class TA, class TB>
		struct pair
		{
			typedef TA	first_type;
			typedef TB	second_type;
			TA			first;
			TB			second;

			pair() : first(TA()), second(TB()) {}

			pair(const TA& u_a, const TB& u_b) : first(u_a), second(u_b) {}

			template<class _TA, class _TB>
				pair(const pair<_TA, _TB>& u_pair)
				: first(u_pair.first), second(u_pair.second) {}

			inline bool operator== (const pair<TA, TB>& rhs) const
			{ return this->first == rhs.first && this->second == rhs.second; }

			inline bool operator!= (const pair<TA, TB>& rhs) const
			{ return !(*this == rhs); }

			inline bool operator< (const pair<TA, TB>& rhs) const
			{ 
				return this->first < rhs.first ? true :
					this->first == rhs.first && this->second < rhs.second;
			}

			inline bool operator> (const pair<TA, TB>& rhs) const
			{ return rhs < *this; }

			inline bool operator<= (const pair<TA, TB>& rhs) const
			{ return !(rhs < *this); }

			inline bool operator>= (const pair<TA, TB>& rhs) const
			{ return !(*this < rhs); }
		};

	template <class TA, class TB>
		extern inline pair<TA, TB> make_pair (const TA& lhs, const TB& rhs)
		{ return pair<TA, TB>(lhs, rhs); }
}

#endif
