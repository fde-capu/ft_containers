/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:39:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/13 17:53:03 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_H
# define TYPE_TRAITS_H

namespace ft
{
	/* false_type, true_type, remove_const */

	struct false_type
	{
		static const bool value = false;
		const typedef false_type type;
	};

	struct true_type
	{
		static const bool value = true;
		const typedef true_type type;
	};

	template<typename T> struct remove_const { typedef T type; };
	template<typename T> struct remove_const<const T> { typedef T type; };

	/* is_integral */

	template<typename>
		struct _is_integral_helper
		: public false_type {};

	template<>
		struct _is_integral_helper<bool>
		: public true_type {};

	template<>
		struct _is_integral_helper<char>
		: public true_type {};

	template<>
		struct _is_integral_helper<unsigned char>
		: public true_type {};

	template<>
		struct _is_integral_helper<int>
		: public true_type {};

	template<>
		struct _is_integral_helper<unsigned int>
		: public true_type {};

	template<>
		struct _is_integral_helper<long>
		: public true_type {};

	template<>
		struct _is_integral_helper<unsigned long>
		: public true_type {};


	template<typename T>
		struct is_integral
		: public _is_integral_helper<typename remove_const<T>::type>::type {};

	/* enable_if */

	template <bool B, class T>
		struct _enable_if {
			typedef T type;
		};

	template <class T>
		struct _enable_if<false, T> {};

	template <bool Cond, class T = void>
		struct enable_if : public _enable_if<Cond, T> {};
}

#endif
