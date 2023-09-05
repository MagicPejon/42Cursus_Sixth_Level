/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:13:48 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/26 19:23:37 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>

int main()
{
	std::cout << std::endl;
	std::cout << "---------------Default Array Creation Test---------------" << std::endl << std::endl;
	Array<char> empty;
	
	try
	{
		empty[0] = 'b';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "The size of array is: " << empty.size() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "---------------Parameterized Array Creation Test---------------" << std::endl << std::endl;
	Array<int> ha(5);

	ha[0] = 1;
	ha[1] = 2;
	ha[2] = 3;
	ha[3] = 4;
	ha[4] = 5;
	for (unsigned int i = 0; i < ha.size(); i++)
		std::cout << ha[i] << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------------Out Of Bounds Test---------------" << std::endl << std::endl;
	try
	{
		std::cout << ha[8] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "---------------Copy Constructure Test---------------" << std::endl << std::endl;
	
	// Array<char> copy(ha); No matching constructor for initialization
	Array<int> copy(ha);

	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << std::endl;
		
	std::cout << std::endl;
	std::cout << "---------------Deep Copy Test---------------" << std::endl << std::endl;
	
	copy[0] = 10;

	for (unsigned int i = 0; i < ha.size(); i++)
		std::cout << "ha Array[" << i << "]: " << ha[i] << std::endl;

	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << "copy Array[" << i << "]: " << copy[i] << std::endl;

	std::cout << std::endl;
	std::cout << "---------------Out Of Bounds Test (Copy)---------------" << std::endl << std::endl;
	try
	{
		std::cout << copy[8] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "---------------Equal Operator Test---------------" << std::endl << std::endl;
	
	Array<int> equality = ha;
	
	for (unsigned int i = 0; i < equality.size(); i++)
		std::cout << equality[i] << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------------Deep Copy Test---------------" << std::endl << std::endl;

	equality[0] = 6;
	equality[1] = 9;
	
	for (unsigned int i = 0; i < ha.size(); i++)
		std::cout << "ha Array[" << i << "]: " << ha[i] << std::endl;

	for (unsigned int i = 0; i < equality.size(); i++)
		std::cout << "equality Array[" << i << "]: " << equality[i] << std::endl;
	
	std::cout << std::endl;
	std::cout << "---------------Out Of Bounds Test (Equal Operator)---------------" << std::endl << std::endl;
	try
	{
		std::cout << copy[-20] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}