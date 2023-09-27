/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:42:34 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/27 15:14:09 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>

void incorrect_mark(std::string expr)
{
	while(expr.find_first_not_of("0123456789/*-+ ") != std::string::npos)
	{
		std::cerr << expr.substr(0, expr.find_first_not_of("0123456789/*-+ "));
		std::cerr << RED << expr.at(expr.find_first_not_of("0123456789/*-+ ")) << DEFAULT;
		expr.erase(0, expr.find_first_not_of("0123456789/*-+ ") + 1);
	}
	std::cerr << expr << std::endl;
}

bool op_present(std::string expr)
{
	if (expr.find('+') == std::string::npos && expr.find('-') == std::string::npos
		&& expr.find('*') == std::string::npos && expr.find('/') == std::string::npos)
		return (false);
	return (true);
}

bool correct_notation(std::string expr)
{
	if (expr.find_first_not_of("0123456789/*-+ ") != std::string::npos)
		return (false);
	int i = 0;
	while(expr[i])
	{
		if (isdigit(expr[i]) && isdigit(expr[i + 1]))
		{
			std::cout << "Two digit number detected at: " << YELLOW << i << DEFAULT << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

int main(int ac, char **av)
{
	std::string explain("start");
	if (ac == 3)
		explain = av[2];
	if (ac == 2 || (ac == 3 && (explain == "ex")))
	{
		std::string expr(av[1]);
		if (correct_notation(expr))
		{
			 if (op_present(expr))
			 	RPN solve(av[1], ac);
			 else
			 {
				std::cerr << "Arithmetic operators needed: " << std::endl;
				std::cerr << GREEN << "+ - * /" << std::endl;
			 }
		}
		else
		{
			std::cerr << "Invalid input(s) given: " << std::endl;
			incorrect_mark(expr);
		}
	}
	else
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./RPN <reverse polish notation equation>" << std::endl;
		std::cerr << "you may add: " << YELLOW << "ex" << DEFAULT << " at the end for the explanation of the equation" << std::endl;
		return (1);
	}
	return (0);
}