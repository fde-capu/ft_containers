/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helpers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:56:40 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/14 12:11:05 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_HELPERS_H
# define CHECK_HELPERS_H

# include "unit_main.h"

/* ostreams so the tests do not break */
	template<typename T>
extern std::ostream& operator<< (std::ostream& oss, ft::vector<T>& rhs)
{ static_cast<void>(rhs); return oss; }

	template<typename TA, typename TB>
extern std::ostream& operator<< (std::ostream& oss, ft::pair<TA, TB>& rhs)
{ static_cast<void>(rhs); return oss; }

	template<typename TA, typename TB>
void check(size_t n, TA a, TB b, bool equal = true)
{
	if (!(n % UNIT_COLUMNS))
		std::cout << std::endl << "\t\t";
	if ((equal && (a == b)) || (!equal && (a != b)))
	{
		g_test_ok++;
		std::cout << n << ":";
		std::cout << "\033[92m[ OK ]\033[00m ";
		return ;
	}
	else
	{
		g_test_ko++;
		std::cout << "\033[31m" << n << ":[ KO ]";
		if (equal)
			std::cout << "(" << a << " != " << b << ")";
		else
			std::cout << "(" << a << " == " << b << ")";
		std::cout << "\033[00m ";
	}
}

template<typename T>
void show_vector(ft::vector<T> & u_vector, std::string id_string = "")
{
	std::cout << std::endl << "/ === Vector ================================== \\ " << id_string << std::endl;
	std::cout << "| size:\t" << u_vector.size() \
		<< "\tcap:\t" << u_vector.capacity() << \
		"\tempty:\t" << std::boolalpha << u_vector.empty() << std::noboolalpha << "\t|" << std::endl;
	std::cout << "| max: " << u_vector.max_size() << std::endl;
	std::cout << "|\t\t\t\t\t\t|" << std::endl;
	std::cout << "| [";
	for (size_t i = 0; i < u_vector.size(); i++)
	{
		std::cout << u_vector[i];
		if (i + 1 < u_vector.size())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
	std::cout << "\\ ============================================= /" << std::endl << std::endl;
}

	template<typename T>
T rnd_of_type()
{
	T		r;
	char *h = reinterpret_cast<char *>(&r);
	size_t	i = 0;
	while (i++ < sizeof(T))
	{
		*h++ = random_char();
	}
	return r;
}

	template<typename T>
T rnd_of_type(T max)
{
	T r;
	do
	{
		r = rnd_of_type<T>();
	} while (r > max);
	return r;
}

	template<typename T>
T rnd_of_type(T min, T max)
{
	if (min > max)
	{
		T tmp = min;
		min = max;
		max = tmp;
	}
	T r;
	do
	{
		r = rnd_of_type<T>(max);
	} while (r < min);
	return r;
}

	template<typename T>
typename ft::vector<T>::size_type next_sqr(size_t n)
{
	typename ft::vector<T>::size_type i(1);
	while (i < n)
		i *= 2;
	return i;
}

	template<typename T>
ft::vector<T> seq_vec(size_t n)
{
	ft::vector<T> vv;
	for (size_t i = 0; i < n; i++)
		vv.push_back(T(i));
	return vv;
}

	template<typename T>
ft::vector<T> rnd_vec(size_t n)
{
	ft::vector<T> vv;
	for (size_t i = 0; i < n; i++)
		vv.push_back(random_int(-42, 42));
	return vv;
}

class foo_class
{
	public:
		void	(*function_pointer)();
		foo_class(void(*u_fun)()) : function_pointer(u_fun) {};
		void call() {}
		typedef bool has_this_member;
};

template<typename T> struct is_reverse_iterator : ft::false_type {};
template<typename T> struct is_reverse_iterator<ft::reverse_iterator<T> > : ft::true_type {};

template<typename T>
struct inv_compare
{
	bool operator() (const T& lhs, const T& rhs) const
	{
		return lhs > rhs;
	}
};

	template<typename _K, typename _V>
void show_map(ft::map<_K, _V> mm)
{
	typename ft::map<_K, _V>::iterator it = mm.begin();
	std::cout << std::endl;
	while (it != mm.end())
	{
		std::cout << "\tK: " << it->first << "\tV: " << it->second << std::endl;
		it++;
	}
}

	template<typename T>
bool range_ten(const T& a, const T& b)
{
	if (a >= b)
		return a - b <= T(10);
	return b - a <= T(10);
}

	template<typename P>
bool v_is_same(P a, P b)
{
	return a.second == b.second;
}

#endif
