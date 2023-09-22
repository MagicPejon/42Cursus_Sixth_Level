/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:41:42 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/20 15:16:35 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "----------------Normal Use of Span (Group Set)----------------" << std::endl << std::endl;
	
	Span	why(10);

	why.addNumber_set(10);
	std::cout << "Longest Span: " << why.longestSpan() << std::endl;
	std::cout << "Shortest Span: " << why.shortestSpan() << std::endl;
	
	std::cout << std::endl;
	std::cout << "----------------Normal Use of Span (Individual Set/Full Test)----------------" << std::endl << std::endl;
	
	Span	sure(5);

	try
	{
		sure.addNumber(10);
		sure.addNumber(20);
		sure.addNumber(0);
		sure.addNumber(30);
		sure.addNumber(40);
		sure.addNumber(55);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Longest Span: " << sure.longestSpan() << std::endl;
	std::cout << "Shortest Span: " << sure.shortestSpan() << std::endl;
	
	std::cout << std::endl;
	std::cout << "----------------Empty Vector Test----------------" << std::endl << std::endl;

	try
	{
		Span pleb;

		// pleb.addNumber(5);

		std::cout << "Longest Span: " << pleb.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << pleb.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Span lone(1);

		lone.addNumber(5);
		
		std::cout << "Longest Span: " << lone.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << lone.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}