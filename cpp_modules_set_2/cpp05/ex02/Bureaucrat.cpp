/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:04:27 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/12 18:41:13 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat(): _name("Noname"), _grade(75)
{
	std::cout << "Default Bureaucrat Constructor Used" << std::endl;
	std::cout << "No inputs given therefore they'll have the name \"";
	std::cout << this->_name;
	std::cout << "\" and their grade will be \"";
	std::cout << this->_grade;
	std::cout << "\"" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Parameterized Bureaucrat Constructor Used" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Their name is \"" << this->_name;
	std::cout << "\" and their grade is -> " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy)
{
	std::cout << "Copy Constructor Used" << std::endl;
	*this = copy;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Equal Operator Used" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat Destructor Used" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::gradeIncrement()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else	
		this->_grade--;
}

void Bureaucrat::gradeDecrement()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(std::string Form_name, bool status)
{
	if (status == true)
		std::cout << this->_name << " signed " << Form_name << std::endl;
	if (status == false)
	{
		std::cout << this->_name << " couldn't sign " << Form_name
			<< " because "; 
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << this->_name << " could not execute " << form.getName()\
		 << " because " << e.what() << std::endl;
	}
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream &operator<<(std::ostream & out, Bureaucrat const & rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (out);
}
