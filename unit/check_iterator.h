/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_iterator.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:57:18 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/21 16:58:58 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ITERATOR_H
# define CHECK_ITERATOR_H

# include <typeinfo>

static int g_iterator_once = 0;

static ft::input_iterator_tag			t_input_tag;
static ft::output_iterator_tag			t_outpt_tag;
static ft::forward_iterator_tag			t_forwd_tag;
static ft::bidirectional_iterator_tag	t_bidir_tag;
static ft::random_access_iterator_tag	t_randm_tag;

template<typename T>
void check_iterator()
{
	title("ITERATOR");
	if (!g_iterator_once)
	{
		title("- tags\t");
		check(1, typeid(t_input_tag).name(), typeid(t_input_tag).name());
		check(2, typeid(t_input_tag).name(), typeid(t_outpt_tag).name(), NOT_EQUAL);
		check(3, typeid(t_input_tag).name(), typeid(t_forwd_tag).name(), NOT_EQUAL);
		check(4, typeid(t_input_tag).name(), typeid(t_bidir_tag).name(), NOT_EQUAL);
		check(5, typeid(t_input_tag).name(), typeid(t_randm_tag).name(), NOT_EQUAL);
		check(6, typeid(t_outpt_tag).name(), typeid(t_outpt_tag).name());
		check(7, typeid(t_outpt_tag).name(), typeid(t_forwd_tag).name(), NOT_EQUAL);
		check(8, typeid(t_outpt_tag).name(), typeid(t_bidir_tag).name(), NOT_EQUAL);
		check(9, typeid(t_outpt_tag).name(), typeid(t_randm_tag).name(), NOT_EQUAL);
		check(10, typeid(t_forwd_tag).name(), typeid(t_forwd_tag).name());
		check(11, typeid(t_forwd_tag).name(), typeid(t_bidir_tag).name(), NOT_EQUAL);
		check(12, typeid(t_forwd_tag).name(), typeid(t_randm_tag).name(), NOT_EQUAL);
		check(13, typeid(t_bidir_tag).name(), typeid(t_bidir_tag).name());
		check(14, typeid(t_bidir_tag).name(), typeid(t_randm_tag).name(), NOT_EQUAL);
		check(15, typeid(t_randm_tag).name(), typeid(t_randm_tag).name());
		try
		{
			static_cast<void>(dynamic_cast<ft::bidirectional_iterator_tag*>(&t_randm_tag));
			static_cast<void>(dynamic_cast<ft::forward_iterator_tag*>(&t_randm_tag));
			static_cast<void>(dynamic_cast<ft::input_iterator_tag*>(&t_randm_tag));
			check(16, 1, 1);
		}
		catch(std::exception& e)
		{
			check(16, "random_access_iterator_tag inheritance", "stl");
		}
		static_cast<void>(dynamic_cast<ft::forward_iterator_tag*>(&t_bidir_tag));
		static_cast<void>(dynamic_cast<ft::input_iterator_tag*>(&t_bidir_tag));
		check(17, 1, 1);
		try
		{
			static_cast<void>(dynamic_cast<ft::input_iterator_tag*>(&t_forwd_tag));
			check(18, 1, 1);
		}
		catch(std::exception& e)
		{
			check(18, "forward_iterator_tag inheritance", "stl");
		}
	}
	{
		title("- base types");
		ft::iterator<T, T, size_t, T*, T&> specs_it;
		static_cast<void>(specs_it);
		ft::iterator<char, T, double, long*, size_t&> strange_it;
		static_cast<void>(strange_it);
		check(1, 1, 1);
	}
	{
		ft::iterator<T, T, size_t, T*> specs_it;
		static_cast<void>(specs_it);
		ft::iterator<int, long, char, unsigned char*> strange_it;
		static_cast<void>(strange_it);
		check(2, 1, 1);
	}
	{
		ft::iterator<T, T, size_t> specs_it;
		static_cast<void>(specs_it);
		ft::iterator<float, unsigned int, long> strange_it;
		static_cast<void>(strange_it);
		check(3, 1, 1);
	}
	{
		ft::iterator<T, T> specs_it;
		static_cast<void>(specs_it);
		ft::iterator<long, double*> strange_it;
		static_cast<void>(strange_it);
		check(4, 1, 1);
	}

	check(5, typeid(typename ft::iterator_traits<ft::iterator<T, T> >::iterator_category).name(), typeid(T).name());
	check(6, typeid(typename ft::iterator_traits<ft::iterator<long, T> >::iterator_category).name(), typeid(long).name());
	check(7, typeid(typename ft::iterator_traits<ft::iterator<T, T> >::value_type).name(), typeid(T).name());
	check(8, typeid(typename ft::iterator_traits<ft::iterator<T, char> >::value_type).name(), typeid(char).name());
	check(9, typeid(typename ft::iterator_traits<ft::iterator<T, T> >::difference_type).name(), typeid(ptrdiff_t).name());
	check(10, typeid(typename ft::iterator_traits<ft::iterator<T, T> >::pointer).name(), typeid(T*).name());
	check(11, typeid(typename ft::iterator_traits<ft::iterator<T, T> >::reference).name(), typeid(T&).name());

	check(12, typeid(typename ft::iterator_traits<ft::iterator<T, T>*>::iterator_category).name(), typeid(t_randm_tag).name());
	typedef typename ft::iterator_traits<ft::iterator<T, T>*>::value_type foo_value_type;
	typedef typename ft::iterator_traits<ft::iterator<T, T>*>::difference_type foo_difference_type;
	typedef typename ft::iterator_traits<ft::iterator<T, T>*>::pointer foo_pointer;
	typedef typename ft::iterator_traits<ft::iterator<T, T>*>::reference foo_reference;

	check(13, typeid(typename ft::iterator_traits<ft::iterator<T, T> >::value_type).name(), typeid(foo_value_type).name(), NOT_EQUAL);
	check(14, typeid(typename ft::iterator_traits<ft::iterator<T, T> >::difference_type).name(), typeid(foo_difference_type).name());
	check(15, typeid(typename ft::iterator_traits<ft::iterator<T, T> >::pointer).name(), typeid(foo_pointer).name(), NOT_EQUAL);
	check(16, typeid(typename ft::iterator_traits<ft::iterator<T, T> >::reference).name(), typeid(foo_reference).name(), NOT_EQUAL);

	check(17, typeid(typename ft::iterator_traits<const ft::iterator<T, T>*>::iterator_category).name(), typeid(t_randm_tag).name());
	typedef typename ft::iterator_traits<const ft::iterator<T, T>*>::value_type const_foo_value_type;
	typedef typename ft::iterator_traits<const ft::iterator<T, T>*>::difference_type const_foo_difference_type;
	typedef typename ft::iterator_traits<const ft::iterator<T, T>*>::pointer const_foo_pointer;
	typedef typename ft::iterator_traits<const ft::iterator<T, T>*>::reference const_foo_reference;

	check(18, typeid(typename ft::iterator_traits<const ft::iterator<T, T> >::value_type).name(), typeid(const_foo_value_type).name(), NOT_EQUAL);
	check(19, typeid(typename ft::iterator_traits<const ft::iterator<T, T> >::difference_type).name(), typeid(const_foo_difference_type).name());
	check(20, typeid(typename ft::iterator_traits<const ft::iterator<T, T> >::pointer).name(), typeid(const_foo_pointer).name(), NOT_EQUAL);
	check(21, typeid(typename ft::iterator_traits<const ft::iterator<T, T> >::reference).name(), typeid(const_foo_reference).name(), NOT_EQUAL);

	check(22, typeid(foo_value_type).name(), typeid(const_foo_value_type).name());
	check(23, typeid(foo_difference_type).name(), typeid(const_foo_difference_type).name());
	check(24, typeid(foo_pointer).name(), typeid(const_foo_pointer).name(), NOT_EQUAL);
	check(25, typeid(foo_reference).name(), typeid(const_foo_reference).name());

	title("- base funcs");

	ft::vector<T> vec = rnd_vec<T>(10);
	/*				^~~				   */

	if (!g_iterator_once)
	{
		check(1, ft::distance(vec.begin(), vec.begin()), 0);
		check(2, ft::distance(vec.begin(), vec.end()), 10);
		check(3, ft::distance(vec.end(), vec.end()), 0);
		check(4, ft::distance(vec.end(), vec.begin()), -10);

		{
			typename ft::vector<T>::iterator it_advance = vec.begin();
			check(5, *it_advance, vec[0]);
			ft::advance(it_advance, 0);
			check(6, *it_advance, vec[0]);
			ft::advance(it_advance, 2);
			check(7, *it_advance, vec[2]);
			ft::advance(it_advance, -1);
			check(8, *it_advance, vec[1]);
		}
	}

	title("Member types");
	check(1, typeid(typename ft::vector<T>::iterator::iterator_category).name(), typeid(t_randm_tag).name());
	check(2, typeid(typename ft::vector<T>::iterator::value_type).name(), typeid(T).name());
	check(3, typeid(typename ft::vector<T>::iterator::difference_type).name(), typeid(ptrdiff_t).name());
	check(4, typeid(typename ft::vector<T>::iterator::reference).name(), typeid(T&).name());
	check(5, typeid(typename ft::vector<T>::iterator::pointer).name(), typeid(T*).name());

	title("iterator");
	{
		typename ft::vector<T>::iterator it_a = vec.begin();
		typename ft::vector<T>::iterator it_b = vec.begin();
		typename ft::vector<T>::iterator it_c = vec.end();
		typename ft::vector<T>::iterator it_d(it_a);
		typename ft::vector<T>::iterator it_e = it_a;

		check(1, *it_b++, vec[0]);
		check(2, *it_b, vec[1]);
		check(3, *++it_b, vec[2]);
		check(4, *it_b, vec[2]);
		check(5, it_a == it_b, false);
		check(6, it_a == it_c, false);
		check(7, it_a == it_d, true);
		check(8, it_a == it_e, true);
		check(9, it_a != it_b, true);
		check(10, *it_a, vec[0]);
		*it_b = 42;
		check(11, *it_b, vec[2]);
		check(12, vec[2], T(42));
		*it_b++ = T(47);
		check(13, *it_b, vec[3]);
		check(14, vec[2], T(47));
		check(15, *(it_b--), vec[3]);
		check(16, *it_b, vec[2]);
		check(17, *it_b--, vec[2]);
		check(18, *it_b, vec[1]);
		check(19, *(--it_b), vec[0]);
		check(20, *(it_b + 5), vec[5]);
		it_b = vec.begin() + 5;
		check(21, *(0 + it_b), vec[5]);
		check(22, *(3 + it_b), vec[8]);
		check(23, *(it_b - 2), vec[3]);
		check(24, (it_b - it_a), 5);
		check(25, it_a < it_b, true);
		check(26, it_a > it_b, false);
		check(27, it_b < it_a, false);
		check(28, it_b > it_a, true);
		check(29, it_a <= it_b, true);
		check(30, it_a >= it_b, false);
		check(31, it_a <= it_e, true);
		check(32, it_a >= it_e, true);
		it_b += 2;
		check(33, *it_b, vec[7]);
		it_b -= 3;
		check(34, *it_b, vec[4]);
		check(35, it_b[0], vec[4]);
		check(36, it_b[1], vec[5]);
		check(37, it_b[3], vec[7]);
		check(38, it_b[-1], vec[3]);
		check(39, it_b[-3], vec[1]);

		ft::vector<foo_class> ff(1, (foo_function));
		ft::vector<foo_class>::iterator ffit = ff.begin();
		ffit->call();
		check(40, 1, 1);
	}
	title("reverse_it");
	{
		typename ft::vector<T>::reverse_iterator it_a = vec.rbegin();
		typename ft::vector<T>::reverse_iterator it_b = vec.rbegin();
		typename ft::vector<T>::reverse_iterator it_c = vec.rend();
		typename ft::vector<T>::reverse_iterator it_d(it_a);
		typename ft::vector<T>::reverse_iterator it_e = it_a;
		check(0, is_reverse_iterator<typename ft::vector<T>::reverse_iterator>::value, true);
		check(1, *it_b++, vec[9]);
		check(2, *it_b, vec[8]);
		check(3, *++it_b, vec[7]);
		check(4, *it_b, vec[7]);
		check(5, it_a == it_b, false);
		check(6, it_a == it_c, false);
		check(7, it_a == it_d, true);
		check(8, it_a == it_e, true);
		check(9, it_a != it_b, true);
		check(10, *it_a, vec[9]);
		*it_b = T(42);
		check(11, *it_b, vec[7]);
		check(12, vec[7], T(42));
		*it_b++ = T(47);
		check(13, *it_b, vec[6]);
		check(14, vec[7], T(47));
		check(15, *(it_b--), vec[6]);
		check(16, *it_b, vec[7]);
		check(17, *it_b--, vec[7]);
		check(18, *it_b, vec[8]);
		check(19, *(--it_b), vec[9]);
		check(20, *(it_b + 5), vec[4]);
		it_b = vec.rbegin() + 5;
		check(21, *(0 + it_b), vec[4]);
		check(22, *(3 + it_b), vec[1]);
		check(23, *(it_b - 2), vec[6]);
		check(24, (it_b - it_a), 5);
		check(25, it_a < it_b, true);
		check(26, it_a > it_b, false);
		check(27, it_b < it_a, false);
		check(28, it_b > it_a, true);
		check(29, it_a <= it_b, true);
		check(30, it_a >= it_b, false);
		check(31, it_a <= it_e, true);
		check(32, it_a >= it_e, true);
		it_b += 2;
		check(33, *it_b, vec[7]);
		it_b -= 3;
		check(34, *it_b, vec[5]);
		check(35, it_b[0], vec[5]);
		check(36, it_b[1], vec[4]);
		check(37, it_b[3], vec[7]);
		check(38, it_b[-1], vec[6]);
		check(39, it_b[-3], vec[8]);

		typedef void(*void_fun_p)();
		ft::vector<void_fun_p> foo_fun_vec(10, foo_function);
		typename ft::vector<void_fun_p>::reverse_iterator it_foo = foo_fun_vec.rbegin();
		check(40, (foo_function) == *it_foo, true);

		ft::vector<foo_class> ff(1, (foo_function));
		ft::vector<foo_class>::reverse_iterator ffit = ff.rbegin();

		ffit->call();
		check(41, 1, 1);

		title("- typedefs");
		check(1, typeid(typename ft::vector<T>::reverse_iterator::iterator_category).name(), typeid(t_randm_tag).name());
		check(2, typeid(typename ft::vector<T>::reverse_iterator::value_type).name(), typeid(T).name());
		check(3, typeid(typename ft::vector<T>::reverse_iterator::difference_type).name(), typeid(ptrdiff_t).name());
		check(4, typeid(typename ft::vector<T>::reverse_iterator::reference).name(), typeid(T&).name());
		check(5, typeid(typename ft::vector<T>::reverse_iterator::pointer).name(), typeid(T*).name());
	}
	{
		typename ft::vector<T>::reverse_iterator it_a;
		check(6, 1, 1);
		typename ft::vector<T>::reverse_iterator it_b(it_a);
		check(7, 1, 1);
		const typename ft::vector<T>::reverse_iterator it_c;
		check(8, 1, 1);
		typename ft::vector<T>::reverse_iterator it_d(it_c);
		check(9, 1, 1);
		static_cast<void>(it_a);
		static_cast<void>(it_b);
		static_cast<void>(it_d);
	}
	{
		typename ft::vector<T>::iterator it_a;
		typename ft::vector<T>::reverse_iterator it_b = static_cast<typename ft::vector<T>::reverse_iterator>(it_a);
		static_cast<void>(it_b);
		check(10, 1, 1);
	}
	if (!g_iterator_once)
	{
		ft::vector<foo_class> ff(1, (foo_function));
		ft::vector<foo_class>::reverse_iterator ffit = ff.rbegin();
		ffit->call();
		check(11, 1, 1);
	}
	g_iterator_once++;
}

#endif
