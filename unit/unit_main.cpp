/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:52:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/12/21 20:44:56 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_main.h"
#include <cstdlib> // rand()

void title(std::string str)
{ std::cout << std::endl << str << "\t"; }

void foo_function()
{ std::cout << "Foo Function called." << std::endl; }

int random_int(int min, int max)
{ return min + (rand() % (static_cast<long>(max) - static_cast<long>(min))); }

unsigned char random_char()
{ return rand() % (static_cast<long>(256)); }

int unit_main(int argc, char** argv) 
{
#if STL
		ft::cout << "STL mode | ft = std; `ft::cout` and `ft::endl` working." << ft::endl;
#else
		std::cout << "FT mode | namespace ft = ft" << std::endl;
		// ft::cout << "This would not compile. There is no cout in namespace ft." << ft::endl;
#endif

	const int seed = atoi(argv[1]);
	srand(static_cast<unsigned int>(seed));
	Chronometer chrono;

	if (SECTION & _FT_)
	{
		std::cout << std::endl << "[ ft_main ]" << std::endl;
		std::cout << chrono.start() << std::endl;
		ft_main(argc, argv);
		std::cout << std::endl << " ft_main " << chrono << std::endl;
	}

	if (SECTION & _PAIR_)
	{
		std::cout << std::endl << "[ pair ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_pair<char, char>();
		check_pair<char, int>();
		check_pair<char, long>();
		check_pair<char, float>();
		check_pair<char, double>();
		check_pair<char, unsigned char>();
		check_pair<char, unsigned int>();
		check_pair<char, unsigned long>();

		check_pair<int, char>();
		check_pair<int, int>();
		check_pair<int, long>();
		check_pair<int, float>();
		check_pair<int, double>();
		check_pair<int, unsigned char>();
		check_pair<int, unsigned int>();
		check_pair<int, unsigned long>();

		check_pair<long, char>();
		check_pair<long, int>();
		check_pair<long, long>();
		check_pair<long, float>();
		check_pair<long, double>();
		check_pair<long, unsigned char>();
		check_pair<long, unsigned int>();
		check_pair<long, unsigned long>();

		check_pair<float, char>();
		check_pair<float, int>();
		check_pair<float, long>();
		check_pair<float, float>();
		check_pair<float, double>();
		check_pair<float, unsigned char>();
		check_pair<float, unsigned int>();
		check_pair<float, unsigned long>();

		check_pair<double, char>();
		check_pair<double, int>();
		check_pair<double, long>();
		check_pair<double, float>();
		check_pair<double, double>();
		check_pair<double, unsigned char>();
		check_pair<double, unsigned int>();
		check_pair<double, unsigned long>();

		check_pair<unsigned char, char>();
		check_pair<unsigned char, int>();
		check_pair<unsigned char, long>();
		check_pair<unsigned char, float>();
		check_pair<unsigned char, double>();
		check_pair<unsigned char, unsigned char>();
		check_pair<unsigned char, unsigned int>();
		check_pair<unsigned char, unsigned long>();

		check_pair<unsigned int, char>();
		check_pair<unsigned int, int>();
		check_pair<unsigned int, long>();
		check_pair<unsigned int, float>();
		check_pair<unsigned int, double>();
		check_pair<unsigned int, unsigned char>();
		check_pair<unsigned int, unsigned int>();
		check_pair<unsigned int, unsigned long>();

		check_pair<unsigned long, char>();
		check_pair<unsigned long, int>();
		check_pair<unsigned long, long>();
		check_pair<unsigned long, float>();
		check_pair<unsigned long, double>();
		check_pair<unsigned long, unsigned char>();
		check_pair<unsigned long, unsigned int>();
		check_pair<unsigned long, unsigned long>();

		std::cout << std::endl << " pair " << chrono << std::endl;
	}

	if (SECTION & _IS_INTEGRAL_)
	{
		std::cout << std::endl << "[ is_integral ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_is_integral<int>();

		std::cout << std::endl << " is_integral " << chrono << std::endl;
	}

	if (SECTION & _ENABLE_IF_)
	{
		std::cout << std::endl << "[ enable_if ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_enable_if<char>();
		check_enable_if<int>();
		check_enable_if<long>();
		check_enable_if<float>();
		check_enable_if<double>();
		check_enable_if<unsigned char>();
		check_enable_if<unsigned int>();
		check_enable_if<unsigned long>();

		std::cout << std::endl << " enable_if " << chrono << std::endl;
	}

	if (SECTION & _ITERATOR_)
	{
		std::cout << std::endl << "[ iterator ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_iterator<char>();
		check_iterator<int>();
		check_iterator<long>();
		check_iterator<float>();
		check_iterator<double>();
		check_iterator<unsigned char>();
		check_iterator<unsigned int>();
		check_iterator<unsigned long>();

		std::cout << std::endl << " iterator " << chrono << std::endl;
	}

	if (SECTION & _VECTOR_)
	{
		std::cout << std::endl << "[ vector ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_vector<char>();
		check_vector<int>();
		check_vector<long>();
		check_vector<float>();
		check_vector<double>();
		check_vector<unsigned char>();
		check_vector<unsigned int>();
		check_vector<unsigned long>();

		std::cout << std::endl << " vector " << chrono << std::endl;
	}

	if (SECTION & _STACK_)
	{
		std::cout << std::endl << "[ stack ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_stack<char>();
		check_stack<int>();
		check_stack<long>();
		check_stack<float>();
		check_stack<double>();
		check_stack<unsigned char>();
		check_stack<unsigned int>();
		check_stack<unsigned long>();

		std::cout << std::endl << " stack " << chrono << std::endl;
	}

	if (SECTION & _MAP_A_)
	{
		std::cout << std::endl << "[ map a ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_map<char, char>();
		check_map<char, int>();
		check_map<char, float>();
		check_map<char, double>();
		check_map<char, unsigned char>();

		check_map<int, char>();
		check_map<int, int>();
		check_map<int, float>();
		check_map<int, double>();
		check_map<int, unsigned int>();

		check_map<float, char>();
		check_map<float, int>();
		check_map<float, float>();
		check_map<float, double>();

		check_map<double, char>();
		check_map<double, int>();
		check_map<double, float>();
		check_map<double, double>();

		std::cout << std::endl << " map a " << chrono << std::endl;
	}

	if (SECTION & _MAP_B_)
	{
		std::cout << std::endl << "[ map b ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_map<unsigned char, char>();
		check_map<unsigned char, int>();
		check_map<unsigned char, float>();
		check_map<unsigned char, double>();
		check_map<unsigned char, unsigned char>();
		check_map<unsigned char, unsigned int>();

		check_map<unsigned int, char>();
		check_map<unsigned int, int>();
		check_map<unsigned int, float>();
		check_map<unsigned int, double>();
		check_map<unsigned int, unsigned char>();
		check_map<unsigned int, unsigned int>();

		std::cout << std::endl << " map b " << chrono << std::endl;
	}

	if (SECTION & _MAP_C_)
	{
		std::cout << std::endl << "[ map c ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_map<float, long>();
		check_map<double, long>();
		check_map<float, unsigned long>();
		check_map<double, unsigned long>();
		check_map<unsigned char, long>();
		check_map<unsigned int, long>();
		check_map<unsigned char, unsigned long>();

		std::cout << std::endl << " map c " << chrono << std::endl;
	}

	if (SECTION & _SET_)
	{
		std::cout << std::endl << "[ set ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_set<char>();
		check_set<int>();
		check_set<long>();
		check_set<float>();
		check_set<double>();
		check_set<unsigned char>();
		check_set<unsigned int>();
		check_set<unsigned long>();

		std::cout << std::endl << " set " << chrono << std::endl;
	}

	if (SECTION & _EQ_LEXICO_)
	{
		std::cout << std::endl << "[ eq_lexico ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_eq_lexico<char, char>();
		check_eq_lexico<char, int>();
		check_eq_lexico<char, long>();
		check_eq_lexico<char, float>();
		check_eq_lexico<char, double>();

		check_eq_lexico<int, char>();
		check_eq_lexico<int, int>();
		check_eq_lexico<int, long>();
		check_eq_lexico<int, float>();
		check_eq_lexico<int, double>();

		check_eq_lexico<long, char>();
		check_eq_lexico<long, int>();
		check_eq_lexico<long, long>();
		check_eq_lexico<long, float>();
		check_eq_lexico<long, double>();

		check_eq_lexico<float, char>();
		check_eq_lexico<float, int>();
		check_eq_lexico<float, long>();
		check_eq_lexico<float, float>();
		check_eq_lexico<float, double>();

		check_eq_lexico<double, char>();
		check_eq_lexico<double, int>();
		check_eq_lexico<double, long>();
		check_eq_lexico<double, float>();
		check_eq_lexico<double, double>();

		std::cout << std::endl << " eq_lexico " << chrono << std::endl;
	}

	if (SECTION & _GENERAL_)
	{
		std::cout << std::endl << "[ general testing ]" << std::endl;
		std::cout << chrono.start() << std::endl;

		check_pair<char, int>();
		check_pair<int, int>();
		check_pair<float, int>();
		check_pair<float, float>();
		check_is_integral<int>();
		check_enable_if<char>();
		check_enable_if<int>();
		check_enable_if<long>();
		check_enable_if<float>();
		check_enable_if<double>();
		check_iterator<char>();
		check_iterator<int>();
		check_iterator<long>();
		check_iterator<float>();
		check_iterator<double>();
		check_stack<char>();
		check_stack<int>();
		check_stack<long>();
		check_stack<float>();
		check_map<char, char>();
		check_map<int, int>();
		check_map<int, float>();
		check_map<float, char>();
		check_map<unsigned char, unsigned char>();
		check_set<char>();
		check_set<int>();
		check_set<long>();
		check_set<double>();
		check_eq_lexico<char, char>();
		check_eq_lexico<char, int>();
		check_eq_lexico<int, int>();
		check_eq_lexico<int, float>();
		check_eq_lexico<int, long>();
		check_eq_lexico<float, float>();
		check_eq_lexico<float, double>();

		std::cout << std::endl << " general testing " << chrono << std::endl;
	}

	if (SECTION & _STRESS_)
	{
		std::cout << std::endl << "[ stress ]" << std::endl;
		std::cout << chrono.start() << std::endl;
		check_stress();
		std::cout << std::endl << " stress " << chrono << std::endl;
	}

	std::cout << std::endl;
	title("End\t");
	if (g_test_ko)
		std::cout << "Total: " << (g_test_ok + g_test_ko) <<"\t[ OK ] " << g_test_ok << "\t\033[31m[ KO ] " << g_test_ko << "\033[00m" << std::endl;
	else
		std::cout << "Total: " << (g_test_ok + g_test_ko) <<"\t[ OK ] " << g_test_ok << "\t[ KO ] " << g_test_ko << std::endl;
	return 0;
}
