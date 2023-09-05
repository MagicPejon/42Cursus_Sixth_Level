/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:27:00 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/03 12:11:48 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange exchange_rate(av[1]);	
	}
	else 
	{
		std::cerr << "Invalid Arguments given: " << std::endl;
		std::cerr << "Usage: ./btc <infile>" << std::endl;
		return (1);
	}
	return (0);
}