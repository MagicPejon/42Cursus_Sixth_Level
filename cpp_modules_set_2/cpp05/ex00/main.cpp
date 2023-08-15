/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:04:13 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/11 19:18:35 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "------------Invalid Grade Test----------" << std::endl;
	try
	{
		Bureaucrat test("George", 0);
		
		std::cout << "------------------------------------" << std::endl;
		test.gradeIncrement();
		std::cout << test.getGrade() << std::endl;
		test.gradeDecrement();
		std::cout << test.getGrade() << std::endl;

		std::cout << test << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
		Bureaucrat rest("Tim", 150);
		Bureaucrat best("Troy", 1);
		Bureaucrat next(rest);
		Bureaucrat endme;
	
		std::cout << "--------------Equal Operator Test---------------" << std::endl;
		endme = next;
	
		std::cout << endme.getName() << std::endl;
		std::cout << endme.getGrade() << std::endl;
	
		
		std::cout << "--------------Increment Protection Test--------------" << std::endl;
		try
		{
			rest.gradeDecrement();
		}
		catch(const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << rest.getGrade() << std::endl;
		try
		{
			rest.gradeIncrement();
		}
		catch(const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << rest.getGrade() << std::endl;
		try
		{
			best.gradeIncrement();
		}
		catch(const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << best.getGrade() << std::endl;
		try
		{
			best.gradeDecrement();
		}
		catch(const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << best.getGrade() << std::endl;
		std::cout << rest << std::endl;
		std::cout << next << std::endl;
		std::cout << best << std::endl;
}