/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator_base_funcs.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:38:06 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/08 14:40:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_BASE_FUNCS_H
# define FT_ITERATOR_BASE_FUNCS_H

namespace ft
{
	template<typename It>
		inline typename iterator_traits<It>::difference_type
		distance(It a, It b)
		{ return b - a; }

	template<typename In, typename Distance>
		inline void
		advance(In& it, Distance amount)
		{ it += amount; }
}

#endif
