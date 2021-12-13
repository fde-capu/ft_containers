/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:58:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/12 23:26:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_STACK_H
# define CHECK_STACK_H

# include <typeinfo>

template<typename T>
void check_stack()
{
	title("STACK");
	title("Member types");
	check(1, typeid(typename ft::stack<T>::value_type).name(), typeid(typename ft::vector<T>::value_type).name());
	check(2, typeid(typename ft::stack<T>::value_type).name(), typeid(T).name());
	check(3, typeid(typename ft::stack<T, ft::vector<T> >::container_type).name(), typeid(ft::vector<T>).name());
	check(4, typeid(typename ft::stack<T>::size_type).name(), typeid(typename ft::vector<T>::size_type).name());
	check(5, typeid(typename ft::stack<T>::size_type).name(), typeid(size_t).name());

	title("Constructors");
	check(1, typeid(typename ft::stack<T>()).name(), typeid(typename ft::stack<T>()).name());
	check(2, typeid(ft::stack<T, ft::vector<T> >).name(), typeid(ft::stack<T, ft::vector<T> >).name());
	check(3, typeid(ft::stack<T, ft::vector<T> >(rnd_vec<T>(42))).name(), typeid(ft::stack<T, ft::vector<T> >(rnd_vec<T>(42))).name());

	title("Member funcs");
	ft::vector<T> vec = rnd_vec<T>(42);
	vec[0] = T(55);
	ft::stack<T, ft::vector<T> > stk(vec);
	ft::stack<T> empty_stk;

	check(1, empty_stk.empty(), true);
	check(2, stk.empty(), false);
	check(3, empty_stk.size(), static_cast<typename ft::stack<T>::size_type>(0));
	check(4, stk.size(), static_cast<typename ft::stack<T>::size_type>(42));
	check(5, stk.top(), vec[41]);
	typename ft::vector<T>::reference ref = stk.top();
	check(6, ref, vec[41]);
	ref = T(42);
	check(7, stk.top(), T(42));
	check(8, vec[41], T(42), NOT_EQUAL);
	typename ft::vector<T>::const_reference cref = stk.top();
	check(9, cref, T(42));
	stk.push(T(43));
	check(10, stk.top(), T(43));
	check(11, vec.size(), static_cast<typename ft::vector<T>::size_type>(42));
	check(12, stk.size(), static_cast<typename ft::stack<T>::size_type>(43));
	stk.pop();
	check(13, stk.top(), T(42));
	check(14, stk.size(), static_cast<typename ft::stack<T>::size_type>(42));

	title("Relational");
	ft::vector<T> other_vec = rnd_vec<T>(57);
	other_vec[0] = T(66);
	ft::stack<T, ft::vector<T> > stk2(other_vec);
	ft::stack<T, ft::vector<T> > stk2_clone(other_vec);

	check(1, stk2 == stk2_clone, true);
	check(2, stk == stk2, false);
	check(3, stk2 != stk2_clone, false);
	check(4, stk != stk2, true);

	check(5, stk2 < stk2_clone, false);
	check(6, stk < stk2, true);
	check(7, stk2 < stk, false);

	check(8, stk2 <= stk2_clone, true);
	check(9, stk <= stk2, true);
	check(10, stk2 <= stk, false);

	check(11, stk2 > stk2_clone, false);
	check(12, stk > stk2, false);
	check(13, stk2 > stk, true);

	check(14, stk2 >= stk2_clone, true);
	check(15, stk >= stk2, false);
	check(16, stk2 >= stk, true);
}

#endif
