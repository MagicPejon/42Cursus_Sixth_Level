/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:21:09 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/13 20:03:50 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor Used" << std::endl;
}

Intern::Intern(Intern const & copy)
{
	std::cout << "Intern Copy Constructor Used" << std::endl;
	*this = copy;
}

Intern & Intern::operator=(Intern const & rhs)
{
	std::cout << "Intern Equal Operator Used" << std::endl;
	if (this != &rhs)
	{}
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Used" << std::endl;
}

const char * Intern::NoFormFound::what() const throw()
{
	return ("No Form Found with name given");
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string list_of_forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	for (int i = 0; i < 3; i++)
	{
		if (list_of_forms[i] == name)
		{
			delete (forms[(i + 1) % 3]);
			delete (forms[(i + 2) % 3]);
			return (forms[i]);
		}
	}
	for (int i = 0; i < 3; i++)
		delete forms[i];
	throw Intern::NoFormFound();
}