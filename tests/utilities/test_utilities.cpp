/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utilities.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:54:35 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/16 17:25:12 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utilities.hpp"

/*
** ft::lexicographical_compare
*/
bool mycomp (char c1, char c2)
{
	return (std::tolower(c1) < std::tolower(c2));
}

void lexicographical_compare(void)
{
	ft::Tester tester; 
	std::string s1("Apple");
	std::string s2("apartment");
	std::string s3("Apple");
	std::string s4("Apartment2");

	tester.printName("ft::lexicographical_compare");
    tester.compare(
		ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()),
		std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end())
		);
    tester.compare(
		ft::lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end()), 
		std::lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end())
	);
    tester.compare(
		ft::lexicographical_compare(s1.begin(), s1.end(), s3.begin(), s3.end()), 
		std::lexicographical_compare(s1.begin(), s1.end(), s3.begin(), s3.end())
		);
    tester.compare(
		ft::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), mycomp),
		std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), mycomp)
		);
    tester.compare(
		ft::lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end(), mycomp),
		std::lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end(), mycomp)
		);
    tester.compare(
		ft::lexicographical_compare(s2.begin(), s2.end(), s4.begin(), s4.end()), 
		std::lexicographical_compare(s2.begin(), s2.end(), s4.begin(), s4.end())
		);
    tester.compare(
		ft::lexicographical_compare(s2.begin(), s2.end(), s4.begin(), s4.end(), mycomp),
		std::lexicographical_compare(s2.begin(), s2.end(), s4.begin(), s4.end(), mycomp)
		);
	std::cout << std::endl;
}

/*
** ft::equal
*/

bool mypredicate (char c1, char c2)
{
	return(std::tolower(c1) == std::tolower(c2));
}

void test_equal(void)
{
	ft::Tester tester;
	std::string s1("Test1");
	std::string s2("Test1");
	std::string s3("Test3");
	std::string s4("");
	std::string s5("");
	std::string s6("Test1 ");
	std::string s7("Test1.");
	std::string s8("TEST1.");

	tester.printName("ft::equal");
    tester.compare(
		ft::equal(s1.begin(), s1.end(), s2.begin()),
		std::equal(s1.begin(), s1.end(), s2.begin())
		);
	tester.compare(
		ft::equal(s1.begin(), s1.end(), s3.begin()), 
		std::equal(s1.begin(), s1.end(), s3.begin())
		);
	tester.compare(
		ft::equal(s1.begin(), s1.end(), s4.begin()), 
		std::equal(s1.begin(), s1.end(), s4.begin())
		);
	tester.compare(
		ft::equal(s4.begin(), s4.end(), s5.begin()),
		std::equal(s4.begin(), s4.end(), s5.begin())
		);
	tester.compare(
		ft::equal(s1.begin(), s1.end(), s4.begin()), 
		std::equal(s1.begin(), s1.end(), s4.begin())
		);
	tester.compare(
		ft::equal(s1.begin(), s1.end(), s6.begin()),
		std::equal(s1.begin(), s1.end(), s6.begin())
		);
	tester.compare(
		ft::equal(s6.begin(), s6.end(), s7.begin()), 
		std::equal(s6.begin(), s6.end(), s7.begin())
		);
	tester.compare(
		ft::equal(s7.begin(), s7.end(), s8.begin()), 
		std::equal(s7.begin(), s7.end(), s8.begin())
		);
	tester.compare(
		ft::equal(s1.begin(), s1.end(), s2.begin(), mypredicate),
		std::equal(s1.begin(), s1.end(), s2.begin(), mypredicate)
		);
	tester.compare(
		ft::equal(s1.begin(), s1.end(), s3.begin(), mypredicate), 
		std::equal(s1.begin(), s1.end(), s3.begin(), mypredicate)
		);
	tester.compare(
		ft::equal(s1.begin(), s1.end(), s4.begin(), mypredicate), 
		std::equal(s1.begin(), s1.end(), s4.begin(), mypredicate)
		);
	tester.compare(
		ft::equal(s4.begin(), s4.end(), s5.begin(), mypredicate),
		std::equal(s4.begin(), s4.end(), s5.begin(), mypredicate)
		);
	tester.compare(
		ft::equal(s1.begin(), s1.end(), s4.begin(), mypredicate), 
		std::equal(s1.begin(), s1.end(), s4.begin(), mypredicate)
		);
	tester.compare(
		ft::equal(s1.begin(), s1.end(), s6.begin(), mypredicate),
		std::equal(s1.begin(), s1.end(), s6.begin(), mypredicate)
		);
	tester.compare(
		ft::equal(s6.begin(), s6.end(), s7.begin(), mypredicate), 
		std::equal(s6.begin(), s6.end(), s7.begin(), mypredicate)
		);
	tester.compare(
		ft::equal(s7.begin(), s7.end(), s8.begin(), mypredicate),
		std::equal(s7.begin(), s7.end(), s8.begin(), mypredicate)
		);
	std::cout << std::endl;
}

/*
** is_integral is CPP11. Can't compare with std::.
*/

struct A {};

void test_isintegral(void)
{
	ft::Tester tester;

	tester.printName("ft::is_integral");
	tester.compare(ft::is_integral<A>::value, false);
    tester.compare(ft::is_integral<float>::value, false);
    tester.compare(ft::is_integral<int>::value, true);
    tester.compare(ft::is_integral<const int>::value, true);
    tester.compare(ft::is_integral<bool>::value, true);
    tester.compare(ft::is_integral<int*>::value, false);
	std::cout << std::endl;
}

/*
** enable_if is CPP11. Can't compare with std::.
*/

template <typename Enableif>
bool test_enableif_helper (void) {return true;}

template <>
bool test_enableif_helper<ft::enable_if<false, bool> > (void) {return false;}

void test_enableif(void)
{
	ft::Tester tester;

    tester.printName("ft::enable_if");
	tester.compare(
		test_enableif_helper<ft::enable_if<std::numeric_limits<int*>::is_integer, bool> >(), false
		);
	tester.compare(
		test_enableif_helper<ft::enable_if<std::numeric_limits<int>::is_integer, bool> >(), true
		);
	std::cout << std::endl;
}

/*
** iterator_traits
*/

template <typename Iterator, typename T >
typename T::value_type test_iteratortraits_helper(Iterator first, Iterator last)
{
    typename T::difference_type n = last - first;
    typename T::difference_type i = 0;
    typename T::value_type val = typename T::value_type();
    while (i < n)
    {
        val += *first++;
        i++;
    }
    return (val);
}

void test_iteratortraits(void)
{
	ft::Tester tester; 
    tester.printName("ft::iterator_traits");
    int i[10];
    for (int j = 0; j < 10; j++)
        i[j] = j;
    char c[12];
    for (int j = 0; j < 12; j++)
        c[j] = j;
    tester.compare(test_iteratortraits_helper<int*, ft::iterator_traits<int*> >(i, i + 10), test_iteratortraits_helper<int*, std::iterator_traits<int*> >(i, i + 10));
    tester.compare(test_iteratortraits_helper<char*, ft::iterator_traits<char*> >(c, c + 12), test_iteratortraits_helper<char*, std::iterator_traits<char*> >(c, c + 12));
	std::cout << std::endl;

}

void test_pair(void)
{
	ft::Tester tester; 
	ft::pair<int,char> foo (10,'z');
	ft::pair<int,char> bar (90,'a');

	tester.printName("ft::pair");
	tester.compare(foo==bar, false);
	tester.compare(foo!=bar, true);
	tester.compare(foo<bar, true);
	tester.compare(foo>bar, false);
	tester.compare(foo<=bar, true);
	tester.compare(foo>=bar, false);
	tester.compare(foo.first == bar.first, false);
	tester.compare(foo.second == bar.second, false);
	foo = bar;
	tester.compare(foo==bar, true);
	tester.compare(foo!=bar, false);
	tester.compare(foo<bar, false);
	tester.compare(foo>bar, false);
	tester.compare(foo<=bar, true);
	tester.compare(foo>=bar, true);
	tester.compare(foo.first, bar.first);
	tester.compare(foo.second, bar.second);
	tester.compare(foo.first == bar.first, true);
	tester.compare(foo.second == bar.second, true);
	std::cout << std::endl;
}

void test_makepair(void)
{
	ft::Tester tester;
	ft::pair<int,char> foo = ft::make_pair(10,'z');
	ft::pair<int,char> bar = ft::make_pair(90,'a');

	tester.printName("ft::make_pair");
	tester.compare(foo==bar, false);
	tester.compare(foo!=bar, true);
	tester.compare(foo<bar, true);
	tester.compare(foo>bar, false);
	tester.compare(foo<=bar, true);
	tester.compare(foo>=bar, false);
	tester.compare(foo.first == bar.first, false);
	tester.compare(foo.second == bar.second, false);
	foo = bar;
	tester.compare(foo==bar, true);
	tester.compare(foo!=bar, false);
	tester.compare(foo<bar, false);
	tester.compare(foo>bar, false);
	tester.compare(foo<=bar, true);
	tester.compare(foo>=bar, true);
	tester.compare(foo.first, bar.first);
	tester.compare(foo.second, bar.second);
	tester.compare(foo.first == bar.first, true);
	tester.compare(foo.second == bar.second, true);
	std::cout << std::endl;
}

void test_utilities()
{
	ft::Tester tester; 

	tester.printTitle("Utilities");
	test_pair();
	test_makepair();
	test_iteratortraits();
	test_enableif();
	test_isintegral();
	test_equal();
	lexicographical_compare();
	test_reverseiterator();

}
