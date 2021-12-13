/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:04:20 by iwillens          #+#    #+#             */
/*   Updated: 2021/10/24 08:23:41 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <iostream>
#include <sstream>
#include "tests.hpp"

std::string randomString(const int len)
{
	std::string s;
	static const char alphanum[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	s.reserve(len);
	for (int i = 0; i < len; i++)
		s += alphanum[rand() % (sizeof(alphanum) - 1)];
	return s;   
}

void set_largenumber(int argc, char **argv, int cmd_pos)
{
	if (argc <= cmd_pos)
		return;
	std::istringstream ss(argv[cmd_pos]);
	int number;
	if (!(ss >> number) || number < 0 || number > 100000)
		return;
	ft::Tester::large_number = number;
}

void run_tests (int argc, char **argv, int cmd_pos)
{
	set_largenumber(argc, argv, cmd_pos + 1);
	if (argc <= cmd_pos ||  std::string(argv[cmd_pos]) == std::string("all"))
	{
		test_utilities();
		test_vector();
		test_map();
		test_stack();
		test_set();
	}
	else if (std::string(argv[cmd_pos]) == std::string("utilities"))
		test_utilities();
	else if (std::string(argv[cmd_pos]) == std::string("vector"))
		test_vector();
	else if (std::string(argv[cmd_pos]) == std::string("map"))
		test_map();
	else if (std::string(argv[cmd_pos]) == std::string("stack"))
		test_stack();
	else if (std::string(argv[cmd_pos]) == std::string("set"))
		test_set();
	else
		std::cout << "Invalid command. Try " << std::string(argv[0]) << " --help" << std::endl;
}

void print_title(void)
{
	std::string s[4];
	s[0] = std::string("\033[38;2;123;145;255m _         _  _  _");
	s[1] = std::string("\033[38;2;87;115;255m<_> _ _ _ <_>| || | ___ ._ _  ___");
	s[2] = std::string("\033[38;2;207;59;255m| || | | || || || |/ ._>| ' |<_-<");
	s[3] = std::string("\033[38;2;255;135;255m|_||__/_/ |_||_||_|\\___.|_|_|/__/\033[0m");
	std::cout << s[0] << std::endl;
	std::cout << s[1] << std::endl;
	std::cout << s[2] << std::endl;
	std::cout << s[3] << std::endl << std::endl;
}

void print_help(void)
{
	ft::Tester color("\033[4m./ft_containers && ./std_containers --help\n\n", CLR_WHITE, CLR_DEFAULT);

	color.Bold();
	color.printColor();
	print_title();
	color.setText("\033[4mSyntax:\n");
	color.printColor();
	color.Bold(false);
	std::cout << "  $ ./ft_containers [compare] [container [large_number] ]" << std::endl;
	std::cout << "  $ ./std_containers [compare] [container [large_number] ]" << std::endl << std::endl;
	color.Bold();
	color.setText("\n\033[4mCommands:\n");
	color.printColor();
	color.setText("\tcompare\n");
	color.printColor();
	std::cout << "\t\tDisplays a coloured output comparing time of execution and results between STL containers and ft:: containers." << std::endl;
	std::cout << "\t\tIf this option is enabled, ./ft_containers and ./std_containers behaviour is exactly the same." << std::endl;
	std::cout << "\t\tOtherwise, ./ft_containers will print the output of ft:: containers and ./std_containers will display the output of the original STL containers." << std::endl << std::endl;
	color.setText("\tcontainer\n");
	color.printColor();
	std::cout << "\t\tselect one of these:" << std::endl;
	color.setText("\t\tvector\n\t\tmap\n\t\tstack\n\t\tset\t\033[0m(bonus)");
	color.printColor();
	color.setText("\n\t\tall\033[0m\twill output all of the above. Same as if left blank.\n\n");
	color.printColor();
	color.setText("\tlarge_number\t\033[0m the number of tests to be done for map and set. Defaults to 1.000, limit is 1.000.000.\n\n");
	color.printColor();
	color.setText("\n\033[4mExamples:\n");
	color.printColor();
	std::cout << "  $ ./ft_containers compare" << std::endl;
	std::cout << "  $ ./ft_containers compare vector" << std::endl;
	std::cout << "  $ ./ft_containers compare all 10000" << std::endl;
	std::cout << "  $ diff <(./ft_containers) <(./std_containers)" << std::endl;
	std::cout << "  $ diff <(./ft_containers map) <(./std_containers map)" << std::endl;
	std::cout << "  $ diff <(./ft_containers map 10000) <(./std_containers map 10000)" << std::endl << std::endl;
}

int main (int argc, char **argv)
{
	ft::Tester tester;
	int cmd_pos = 1;

	if (argc > 1 && ((std::string(argv[1]) == std::string("help"))
	|| (std::string(argv[1]) == std::string("--help") || std::string(argv[1]) == std::string("-h"))))
	{
		print_help();
		return (0);
	}
	else if (argc == 1 || std::string(argv[1]) != std::string("compare"))
	{
		if (ORIGINAL_STD == 1)
		{
			std::cout << "ORIGINAL_STD" << std::endl;
			ft::Tester::kind = KIND_STD;
		}
		else
		{
			std::cout << "FT" << std::endl;
			ft::Tester::kind = KIND_FT;
		}
	}
	else
	{
		ft::Tester::kind = KIND_COMPARE;
		cmd_pos++;
	}
	try
	{
		run_tests(argc, argv, cmd_pos);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
	return (0);
}
