/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:15:40 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/20 15:57:45 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

bool	is_num(std::string str)
{
	if (!str.empty())
	{
		if (str.find_first_not_of("0123456789") == std::string::npos
			|| (str.find_first_not_of("-0123456789") == std::string::npos && str[0] == '-'))
		{
			if (str.find('-', 1) == std::string::npos)
			return (true);
		}
	}
	return(false);
}

bool	is_double(std::string str)
{
	if (!str.empty())
	{
		if (str.find_first_not_of("0123456789.") == std::string::npos
			|| (str.find_first_not_of("-0123456789.") == std::string::npos && str[0] == '-'))
		{
			if (str.find('-', 1) == std::string::npos
				&& str.find('.', str.find('.', 0) + 1) == std::string::npos)
			return (true);
		}
	}
	return(false);
}

bool	is_float(std::string str)
{
	if (!str.empty())
	{
		if (str.find_first_not_of("0123456789.f") == std::string::npos
			|| (str.find_first_not_of("-0123456789.f") == std::string::npos && str[0] == '-'))
		{
			if (str.find('-', 1) == std::string::npos
				&& str.find('.', str.find('.', 0) + 1) == std::string::npos
				&& str.find('f', str.find('f', 0) + 1) == std::string::npos)
			return (true);
		}
	}
	return(false);
}

bool	is_char(std::string str)
{
	if (str.length() == 1)
		return (true);
	else if ((str == "nan" || str == "+inf" || str == "-inf"))
		return (true);
	else if ((str == "nanf" || str == "+inff" || str == "-inff"))
		return (true);
	return (false);
}

bool	is_convertible(std::string str)
{
	if (is_num(str) || is_double(str) || is_float(str) || is_char(str))
		return (true);
	return (false);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if (av[1][0] && is_convertible(av[1]))
		{
			ScalarConverter::convert(av[1]);
			return (0);
		}
		std::cout << "Invalid argument" << std::endl;
		return (1);
	}
	else
		std::cout << "Wrong number of arguments -- usage: ./convert <arg>" << std::endl;
	return (1);
}