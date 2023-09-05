/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:49:07 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/24 19:20:34 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	int x = 50;
	int y = 100;
	float z = 5.50;
	float a = 5.52;

	std::cout << "-------------Swap Test with int-------------------" << std::endl << std::endl;
	
	std::cout << "x is: " << x << std::endl;
	std::cout << "y is: " << y << std::endl;
	swap(x, y);
	std::cout << "x is: " << x << std::endl;
	std::cout << "y is: " << y << std::endl;
	
	std::cout << "-------------Min Test with int-------------------" << std::endl << std::endl;
	
	std::cout << min(x, y) << std::endl;
	std::cout << min(75, 25) << std::endl;

	std::cout << "-------------Max Test with int-------------------" << std::endl << std::endl;
	
	std::cout << max(x, y) << std::endl;
	std::cout << max(75, 25) << std::endl;
	
	std::cout << "-------------Swap Test with float-------------------" << std::endl << std::endl;

	std::cout << "z is: " << z << std::endl;
	std::cout << "a is: " << a << std::endl;
	swap(z, a);
	std::cout << "z is: " << z << std::endl;
	std::cout << "a is: " << a << std::endl;
	
	std::cout << "-------------Min Test with float-------------------" << std::endl << std::endl;

	std::cout << min(z, a) << std::endl;
	std::cout << min(9.10, 9.03) << std::endl;
	
	std::cout << "-------------Max Test with float-------------------" << std::endl << std::endl;
	
	std::cout << max(z, a) << std::endl;
	std::cout << max(20.9, 15.5) << std::endl;

	std::cout << "-------------Mixed Types Test-------------------" << std::endl << std::endl;

	// swap(x, z); compiler won't compile with different types :(
	// std::cout << min(x, z) << std::endl;
	// std::cout << max(x, z) << std::endl;
}