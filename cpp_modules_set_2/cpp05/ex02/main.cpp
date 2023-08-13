/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:04:13 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/13 15:56:15 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int main()
{
	std::cout << "------------Invalid Grade Test----------" << std::endl << std::endl;
	
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
	
	std::cout << std::endl;
	std::cout << "------------Regular Bureaucrat Creation----------" << std::endl << std::endl;

	Bureaucrat rest("Tim", 150);
	Bureaucrat best("Troy", 1);
	Bureaucrat jest("Samantha", 75);
	Bureaucrat next(rest);
	Bureaucrat endme;

	std::cout << std::endl;
	std::cout << "--------------Equal Operator Test---------------" << std::endl << std::endl;
	
	endme = next;

	std::cout << endme.getName() << std::endl;
	std::cout << endme.getGrade() << std::endl;

	std::cout << std::endl;
	std::cout << "--------------Increment Protection Test--------------" << std::endl << std::endl;
	
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
	
	std::cout << std::endl;
	std::cout << "------------Form Tests Start----------" << std::endl << std::endl;
	std::cout << "------------Shrubbery Creation----------" << std::endl << std::endl;

	ShrubberyCreationForm A("My_House");
	A.beSigned(jest);
	A.execute(jest);

	std::cout << std::endl;
	std::cout << "------------Shrubbery Creation Failed to Sign----------" << std::endl << std::endl;
	
	ShrubberyCreationForm B("Wub");
	try
	{
		B.beSigned(rest);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		B.execute(rest);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "------------Shrubbery Creation Failed to Execute----------" << std::endl << std::endl;
	
	try
	{
		B.beSigned(jest);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		B.execute(rest);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "------------Robotomy Request----------" << std::endl << std::endl;
	std::cout << "------------Robotomy Request Probability Test----------" << std::endl << std::endl;

	RobotomyRequestForm C("My_Cat");
	
	C.beSigned(best);
	for (int i = 0; i <= 10; i++)
		C.execute(best);
	
	std::cout << std::endl;
	std::cout << "------------Robotomy Request Failed to Sign----------" << std::endl << std::endl;
	
	RobotomyRequestForm D("Whoa_There");
	
	try
	{
		D.beSigned(jest);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		D.execute(jest);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "------------Robotomy Request Failed to Execute----------" << std::endl << std::endl;
	
	try
	{
		D.beSigned(best);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		D.execute(jest);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "------------Presidential Pardon----------" << std::endl << std::endl;
	std::cout << "------------Presidential Pardon Achieved----------" << std::endl << std::endl;

	PresidentialPardonForm E("Paulice");
	
	E.beSigned(best);
	E.execute(best);
	
	std::cout << std::endl;
	std::cout << "------------Presidential Pardon Failed to Sign----------" << std::endl << std::endl;
	
	PresidentialPardonForm F("Grade_F");

	try
	{
		F.beSigned(jest);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		F.execute(jest);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "------------Presidential Pardon Failed to Execute----------" << std::endl << std::endl;
	
	try
	{
		F.beSigned(best);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		F.execute(jest);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}