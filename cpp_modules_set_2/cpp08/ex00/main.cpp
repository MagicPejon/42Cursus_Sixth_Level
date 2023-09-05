/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:33:15 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/30 14:05:50 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> vec;

	for (int i = 10; i >= 0; i--)
		vec.push_back(i);
	try
	{
		std::cout << easyfind(vec, 5) << std::endl;
		std::cout << easyfind(vec, 20) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	char a = 'a';
	vec.push_back(a);
	
	std::cout << easyfind(vec, a) << std::endl;
}