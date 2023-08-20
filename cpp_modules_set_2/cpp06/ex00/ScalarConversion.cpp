/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:15:11 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/20 15:58:05 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"
#include <_ctype.h>
#include <exception>
#include <limits>
#include <stdexcept>

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(ScalarConverter const & copy)
{
	*this = copy;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
	if (this == &rhs)
	{}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	
}

void ScalarConverter::convert(std::string str)
{
	toChar(str);
	// toInt(str);
	// toDouble(str);
	// toFloat(str);	
}

void ScalarConverter::toChar(std::string str)
{
	char ch;

	ch = 0;
	try
	{
		if (str.length() == 1 && !isdigit(str[0]))
			ch = str[0];
		else
		{
			int base = 10;
			char *endptr = NULL;
			const long long num = std::strtoll(str.c_str(), &endptr, base);
			if (endptr == str.c_str())
				throw std::invalid_argument("no conversion possible");
			if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
				throw std::out_of_range("Out of range");
			ch = static_cast<char>(num);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "char: impossible" << std::endl;
		return ;
	}
	if (isprint(ch))
		std::cout << "char: '" << ch << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

// void ScalarConverter::toInt(std::string str)
// {
	
// }

// void ScalarConverter::toDouble(std::string str)
// {
	
// }

// void ScalarConverter::toFloat(std::string str)
// {
	
// }