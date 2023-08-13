/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:04:17 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/13 14:52:59 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("Notarget")
{
	std::cout << "Shrubbery Default Constructor Used" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Shrubbery Parametrized Constructor Used" << std::endl;
	std::cout << this->getName() << " is made" << std::endl;
	std::cout << "with " << this->_target << " as its target" << std::endl;
	std::cout << "and it requires " << this->getReq_Tick() << " to sign it" << std::endl;
	std::cout << "and it requires " << this->getReq_Exe() << " to execute it" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy): AForm(copy), _target(copy.getTarget())
{
	std::cout << "Shrubbery Copy Constructor Used" << std::endl;
	*this = copy;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << "Shrubbery Equals Operator Is Used" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default Destructor Used" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::writeAsciiTree() const
{
	std::ofstream file;
			
	file.open(this->_target + "_shrubbery");
	if (file.fail())
		throw ShrubberyCreationForm::FileNotOpened();
	file << " \\\\   //  \\\\   //  \\\\   //  \\\\   //" << std::endl;
	file << "   | |      | |      | |      | |" << std::endl;
	file << "   | |      | |      | |      | |" << std::endl;
	file << "  / | \\    / | \\    / | \\    / | \\ " << std::endl;
	file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getTick())
	{
		if (executor.getGrade() <= this->getReq_Exe())
		{
			this->writeAsciiTree();
			std::cout << this->_target << "_shrubbery created, give them time to grow" << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSigned();
}

const char * ShrubberyCreationForm::FileNotOpened::what() const throw()
{
	return ("File Could Not Open");
}