/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_integral.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:57:01 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/21 16:36:42 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_IS_INTEGRAL_H
# define CHECK_IS_INTEGRAL_H

typedef int IntType;
typedef double DoubleType;

template <class T>
bool integral_tester(T i)
{
	static_cast<void>(i);
	if (ft::is_integral<T>::value)
		return true;
	else
		return false;
}

static int g_is_integral_once = 0;

template <class T>
void check_is_integral()
{
	title("IS_INTEGRAL");
	check(1, ft::is_integral<T>::value, integral_tester(T()));
	if (!g_is_integral_once++)
	{
		check(2, ft::is_integral<bool>::value, true);
		check(3, ft::is_integral<char>::value, true);
		check(4, ft::is_integral<unsigned char>::value, true);
		check(5, ft::is_integral<int>::value, true);
		check(6, ft::is_integral<const int>::value, true);
		check(7, ft::is_integral<unsigned int>::value, true);
		check(8, ft::is_integral<long>::value, true);
		check(9, ft::is_integral<unsigned long>::value, true);
		check(10, ft::is_integral<IntType>::value, true);
		check(11, ft::is_integral<DoubleType>::value, false);
		check(12, integral_tester(true), true);
		check(13, integral_tester(false), true);
		check(14, integral_tester(123l), true);
		check(15, ft::is_integral<std::string>::value, false);
		check(16, ft::is_integral<float>::value, false);
		check(17, ft::is_integral<double>::value, false);
		check(18, ft::is_integral<DoubleType>::value, false);
		check(19, integral_tester(123.456), false);
		check(20, integral_tester(123.4567f), false);
		check(21, integral_tester("Don't Panic"), false);
	}
}

#endif
