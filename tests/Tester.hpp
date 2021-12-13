/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:30:16 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/24 16:03:20 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

# include <string>
# include <iostream>
# include <time.h>
# include <sstream>
# include "vector.hpp"

# define LINE_LEN		80

# define CLR_BLACK		30
# define CLR_RED		31
# define CLR_GREEN		32
# define CLR_YELLOW		33
# define CLR_BLUE		34
# define CLR_MAGENTA	35
# define CLR_CYAN		36
# define CLR_WHITE		37

# define CLR_DEFAULT		0
# define CLR_BOLD			1
# define CLR_DIM			2
# define CLR_ITALICS		3
# define CLR_UNDERLINED		4
# define CLR_BLINK			5
# define CLR_REVERSE		7
# define CLR_HIDDEN			8
# define CLR_LIGHTFG		16
# define CLR_LIGHTBG		32

# define ALN_CENTER		0
# define ALN_LEFT		1
# define ALN_RIGHT		2

# define KIND_COMPARE	1
# define KIND_FT		2
# define KIND_STD		4

namespace ft
{
	typedef struct s_function
	{
		std::string (*ft)();
		std::string (*std)();
	} t_function;

	class Tester
	{	
		public:
			static int								kind;
			static int						large_number;
			typedef std::allocator<t_function>		allocator_type;
			typedef allocator_type::reference		reference;
			typedef allocator_type::pointer			pointer;
		private:
			std::string 				_text;
			int							_color;
			int							_background;
			bool						_lightforeground;
			bool						_lightbackground;
			bool						_bold;
			clock_t						_timestart;
			std::allocator<t_function>	_allocator;
			t_function					*_data;
			size_t						_size;

		public:
			Tester();
			Tester(Tester const &c);
			Tester(std::string s, int color = CLR_DEFAULT, int attributes = CLR_DEFAULT, int background = CLR_DEFAULT);
			virtual ~Tester();
			Tester &operator=(Tester const &c);
			void setText(std::string s);

			/*
			** colors and decorations
			*/
			void lightForeground(bool enabled = true);
			void lightBackground(bool enabled = true);
			void Bold(bool enabled = true);
			void Black();
			void Red();
			void Green();
			void Yellow();
			void Blue();
			void Magenta();
			void Cyan();
			void White();
			void bgBlack();
			void bgRed();
			void bgGreen();
			void bgYellow();
			void bgBlue();
			void bgMagenta();
			void bgCyan();
			void bgWhite();
			
			/*
			** print functions
			*/
			std::string &line_fill(std::string &s, int align);
			void print();
			void printColor();
			void printTitle();
			void printTitle(std::string s);
			void printName();
			void printName(std::string s, bool subtitle = false);

			/*
			** test equality.
			*/
			template <typename T>
			void compare(T t1, T t2)
			{
				if((kind != KIND_COMPARE))
					return ;
				ft::Tester color;
				color.Bold();
				color.Green();
				if (t1 == t2)
				{
					color.setText("[OK] ");
					color.print();
				}
				else
				{
					color.Red();
					color.setText("[X] ");
					color.print();
				}
			}
			
			/*
			** clock
			*/
			void startClock();
			void printClock(std::string lib = "[ft ]");
			static std::string &Return(std::string &s);
			void run();
			void add(std::string (*ft)(), std::string (*std)());
};
	
	struct s_buffer
	{
		int idx;
		char buff[4096];
	};


	template<typename T>
	std::string to_string(const T& value)
	{
		std::ostringstream oss;
		oss << value;
		return (oss.str());
	}

	template<>
	inline std::string to_string(const s_buffer& value) { return (ft::to_string(value.idx)); }

}

#endif
