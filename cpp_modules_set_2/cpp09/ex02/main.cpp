/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:06:45 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/15 18:27:16 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void incorrect_mark(std::string expr)
{
	while(expr.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cerr << expr.substr(0, expr.find_first_not_of("0123456789"));
		std::cerr << RED << expr.at(expr.find_first_not_of("0123456789")) << DEFAULT;
		expr.erase(0, expr.find_first_not_of("0123456789") + 1);
	}
	std::cerr << expr << " ";
}

void check_single(char ** av)
{
	int i;

	i = 0;
	while (av[++i])
	{
		std::string single(av[i]);
		incorrect_mark(single);
	}
	std::cerr << std::endl;
}

bool all_digits(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{	
		j = -1;
		while (av[i][++j])
		{
			if (!isdigit(av[i][j]))
				return (false);	
		}
	}
	return (true);
}

int main(int ac, char **av)
{
	if ((ac >= 3 && ac <= 3001) && all_digits(av))
	{
		PmergeMe sort(av);
	}
	else
	{
		std::cerr << "Invalid arguments given:" << std::endl;
		check_single(av);
		std::cerr << YELLOW << "Usage: " << DEFAULT << "./PmergeMe <numbers>" << RED << "*" << std::endl;
		std::cerr << "*" << DEFAULT << "Number of numbers must be between 5 and 3000" << std::endl;
		std::cerr << GREEN << "For example: 5 7 9 10 6 8 ...." << DEFAULT << std::endl;
		return (1);
	}
	return (0);
}