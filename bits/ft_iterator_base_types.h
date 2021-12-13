/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator_base_types.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:38:23 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/08 13:55:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_BASE_TYPES_H
# define FT_ITERATOR_BASE_TYPES_H

# include <cstddef> // ptrdiff_t

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<
		typename Category,				\
		typename T,						\
		typename Distance = ptrdiff_t,	\
		typename Pointer = T*,			\
		typename Reference = T&			\
		>
		struct iterator
		{
			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
		};

	template<typename I>
		struct iterator_traits
		{
			typedef typename I::iterator_category	iterator_category;
			typedef typename I::value_type			value_type;
			typedef typename I::difference_type		difference_type;
			typedef typename I::pointer				pointer;
			typedef typename I::reference			reference;
		};

	template<typename I>
		struct iterator_traits<I*>
		{
			typedef random_access_iterator_tag	iterator_category;
			typedef I							value_type;
			typedef ptrdiff_t					difference_type;
			typedef I*							pointer;
			typedef I&							reference;
		};
}

#endif
