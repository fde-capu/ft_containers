/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:48:06 by iwillens          #+#    #+#             */
/*   Updated: 2021/09/24 17:08:44 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tester.hpp"

int ft::Tester::kind = KIND_COMPARE;
int ft::Tester::large_number = 1000;

ft::Tester::Tester(void)
: _text(""), _color(CLR_DEFAULT), _background(CLR_DEFAULT), _lightforeground(false), _lightbackground(false), _bold(false), _allocator(std::allocator<t_function>()), _size(0)
{
	this->_data = this->_allocator.allocate(0);
}

ft::Tester::Tester(Tester const &c) { *this = c; }

ft::Tester::Tester(std::string s, int color, int attributes, int background)
: _text(s), _color(color), _background(background), _lightforeground(false), _lightbackground(false), _bold(false),  _allocator(std::allocator<t_function>()), _size(0)
{
    if (attributes & CLR_LIGHTFG)
        this->lightForeground();
    if (attributes & CLR_LIGHTBG)
        this->lightBackground();
    attributes = attributes & 15;
    if (attributes == CLR_BOLD)
        this->Bold();
	this->_data = this->_allocator.allocate(0);
}

ft::Tester::~Tester()
{
	for (size_t i = 0; i < this->_size; i++)
		this->_allocator.destroy(&(this->_data[i]));
	this->_allocator.deallocate(this->_data, this->_size);
}

ft::Tester &ft::Tester::operator=(Tester const &c)
{
    this->_text = c._text;
    this->_color = c._color;
    this->_background = c._background;
    this->_lightforeground = c._lightforeground;
    this->_lightbackground = c._lightbackground;
    this->_bold = c._bold;
	this->_allocator = c._allocator;
	this->_data = this->_allocator.allocate(0);
	this->_size = 0;
    return (*this);
}

void ft::Tester::lightForeground(bool enabled) { this->_lightforeground = enabled; }
void ft::Tester::lightBackground(bool enabled) { this->_lightbackground = enabled; }
void ft::Tester::Bold(bool enabled) { this->_bold = enabled; }
void ft::Tester::Black() { this->_color = CLR_BLACK; }
void ft::Tester::Red() { this->_color = CLR_RED; }
void ft::Tester::Green() { this->_color = CLR_GREEN; }
void ft::Tester::Yellow() { this->_color = CLR_YELLOW; }
void ft::Tester::Blue() { this->_color = CLR_BLUE; }
void ft::Tester::Magenta() { this->_color = CLR_MAGENTA; }
void ft::Tester::Cyan() { this->_color = CLR_CYAN; }
void ft::Tester::White() { this->_color = CLR_WHITE; }
void ft::Tester::bgBlack() { this->_background = CLR_BLACK; }
void ft::Tester::bgRed() { this->_background = CLR_RED; }
void ft::Tester::bgGreen() { this->_background = CLR_GREEN; }
void ft::Tester::bgYellow() { this->_background = CLR_YELLOW; }
void ft::Tester::bgBlue() { this->_background = CLR_BLUE; }
void ft::Tester::bgMagenta() { this->_background = CLR_MAGENTA; }
void ft::Tester::bgCyan() { this->_background = CLR_CYAN; }
void ft::Tester::bgWhite() { this->_background = CLR_WHITE; }

void ft::Tester::setText(std::string s) { this->_text = s; }

/*
** prints color regardless of kind.
*/
void ft::Tester::printColor()
{
    std::string str("\033[");
    int attributes = 0;
    int color = this->_color;
	int background = this->_background;

	if (color && this->_lightforeground)
		color += 60;
	if (background)
		background += 10;
	if (background && this->_lightbackground)
		background += 60;
	if (this->_bold)
		attributes = CLR_BOLD;
	str += ft::to_string(attributes);
	str +=  ";" + ft::to_string(color);
	if (background)
		str += ";" + ft::to_string(background);
	str += "m";
	str += this->_text;
	str += "\033[0m";
	std::cout << str;
}

void ft::Tester::print()
{
    std::string str("\033[");
    int attributes = 0;
    int color = this->_color;
    int background = this->_background;

    if (this->kind == KIND_COMPARE)
    {
        if (color && this->_lightforeground)
            color += 60;
        if (background)
            background += 10;
        if (background && this->_lightbackground)
            background += 60;
        if (this->_bold)
            attributes = CLR_BOLD;
        str += ft::to_string(attributes);
        str +=  ";" + ft::to_string(color);
        if (background)
            str += ";" + ft::to_string(background);
        str += "m";
        str += this->_text;
        str += "\033[0m";
        std::cout << str;
    }
    else
    {
        std::cout << this->_text << std::endl;
    }
}

std::string &ft::Tester::line_fill(std::string &s, int align = ALN_CENTER)
{
	if (s.length() % 2)
		s += " ";
	s = " " + s + " ";	
	while (s.length() < LINE_LEN)
	{
		if (align == ALN_CENTER || align == ALN_LEFT)
			s = s + " ";
		if (align == ALN_CENTER || align == ALN_RIGHT)
			s = " " + s;
	}
	return (s);
}

void ft::Tester::printTitle()
{
	printTitle(this->_text);
}

void ft::Tester::printTitle(std::string s)
{
	std::string empty_str("");
	s = "* * * " + s + " * * *";
	std::cout << std::endl;
	ft::Tester color;

	empty_str = color.line_fill(empty_str);
	color.setText(empty_str);
	color.Blue();
	color.lightBackground();
	color.Bold();
	color.bgWhite();
	color.print();
	std::cout << std::endl;
	color.setText(color.line_fill(s));
	color.print();
	std::cout << std::endl;
	color.setText(empty_str);
	color.print();
	std::cout << std::endl;
}
	
void ft::Tester::printName()
{
	printName(this->_text);
}

void ft::Tester::printName(std::string s, bool subtitle)
{
	ft::Tester color(s);

	s = color.line_fill(s);
	color.setText(s);
	color.White();
	color.Bold();
	color.bgBlue();
	if (subtitle)
		color.bgMagenta();
	color.print();
	std::cout << std::endl;
}

void ft::Tester::startClock()
{
	this->_timestart = clock();	
}

void ft::Tester::printClock(std::string lib)
{
	if(!(this->kind == KIND_COMPARE))
		return ;
	double elapsedSeconds = (clock() - this->_timestart) / (double)(CLOCKS_PER_SEC);
	std::string s = "Time Elapsed" + lib + ": " + ft::to_string(elapsedSeconds * 1000);
	ft::Tester color;

	s = color.line_fill(s, ALN_RIGHT);
	color.setText(s);
	color.White();
	color.Bold();
	color.Black();
	color.lightBackground();
	color.print();
	std::cout << std::endl;
}

/*
** if is not compare, will print the result.
*/
std::string &ft::Tester::Return(std::string &s)
{
	if(!(ft::Tester::kind == KIND_COMPARE))
		std::cout << s << std::endl ;
	return (s);
}

void ft::Tester::run(void)
{
	if (this->kind == KIND_COMPARE)
	{
		for (size_t i = 0; i < this->_size; i++)
			this->compare(this->_data[i].ft(), this->_data[i].std());
	}
	std::cout << std::endl;
	if (this->kind & (KIND_COMPARE | KIND_FT))
	{
		this->startClock();
		for (size_t i = 0; i < this->_size; i++)
			this->_data[i].ft();
		this->printClock("[ft ]");
	}
	if (this->kind & (KIND_COMPARE | KIND_STD))
	{
		this->startClock();
		for (size_t i = 0; i < this->_size; i++)
			this->_data[i].std();
		this->printClock("[std]");
	}
}

void ft::Tester::add(std::string (*ft)(), std::string (*std)())
{
	pointer new_data = this->_allocator.allocate(this->_size + 1);
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_allocator.construct(&new_data[i], this->_data[i]);
		this->_allocator.destroy(&(this->_data[i]));
	}
	this->_allocator.construct(&new_data[this->_size], t_function());
	new_data[this->_size].ft = ft;
	new_data[this->_size].std = std;
	this->_allocator.deallocate(this->_data, this->_size);
	this->_size++;
	this->_data = new_data;
}
