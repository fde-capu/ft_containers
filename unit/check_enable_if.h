/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enable_if.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:56:12 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/21 16:38:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ENABLE_IF
# define CHECK_ENABLE_IF

// 1 via the return type
template <typename T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type is_odd_integral(T i)
{ return i % 2; }

template <typename T>
typename ft::enable_if<!ft::is_integral<T>::value, bool>::type is_odd_integral(T i)
{ static_cast<void>(i); return false; }

// 2 using helper type
template<typename>	struct is_int_helper		{ static const bool value = false; };
template<>			struct is_int_helper<int>	{ static const bool value = true; };
template<typename T>
struct is_int : public is_int_helper<T> {};

template<typename T>
typename ft::enable_if<is_int<T>::value, bool>::type
is_odd_and_int(T i)
{ return(i % 2); }

template<typename T>
typename ft::enable_if<!is_int<T>::value, bool>::type
is_odd_and_int(T i)
{ static_cast<void>(i); return false; }

// 3 via parameter
template<typename T>
bool is_odd_and_int_param(T i, typename ft::enable_if<is_int<T>::value>::type* = 0)
{ return(i % 2); }

template<typename T>
bool is_odd_and_int_param(T i, typename ft::enable_if<!is_int<T>::value>::type* = 0)
{ static_cast<void>(i); return false; }

static int g_enable_if_once = 0;

template<typename T>
void check_enable_if()
{
	title("ENABLE_IF");
	check(1, is_odd_integral(T()), false);
	check(2, is_odd_and_int(T()), false);
	check(3, is_odd_and_int_param(T()), false);

	if (!g_enable_if_once++)
	{
		check(4, is_odd_integral(0), false);
		check(5, is_odd_integral(1), true);
		check(6, is_odd_integral(2), false);
		unsigned long l = 42;
		for (int i = 0; i < 62; i++) { l *= 42; };
		check(7, is_odd_integral(l), false);
		l++;
		check(8, is_odd_integral(l), true);
		double d = 42.42;
		check(9, is_odd_integral(d), false);
		d = 41.00;
		check(10, is_odd_integral(d), false);
		d = 42.00;
		check(11, is_odd_integral(d), false);
		check(12, is_odd_integral(42.42), false);
		check(13, is_odd_integral(1.00), false);

		check(14, is_odd_and_int(0), false);
		check(15, is_odd_and_int(1), true);
		check(16, is_odd_and_int(2), false);
		check(17, is_odd_and_int(static_cast<char>(1)), false);
		check(18, is_odd_and_int(static_cast<char>(2)), false);

		check(19, is_odd_and_int_param(0), false);
		check(20, is_odd_and_int_param(1), true);
		check(21, is_odd_and_int_param(2), false);
		check(22, is_odd_and_int_param(static_cast<char>(1)), false);
		check(23, is_odd_and_int_param(static_cast<char>(2)), false);
	}
}

#endif
