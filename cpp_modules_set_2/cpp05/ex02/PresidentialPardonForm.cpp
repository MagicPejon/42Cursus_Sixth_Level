/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:05:31 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/12 18:54:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("Notarget")
{
	std::cout << "Presidential Default Constructor Used" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Presidential Parametrized Constructor Used" << std::endl;
	std::cout << this->getName() << " is made" << std::endl;
	std::cout << "with " << this->_target << " as its target" << std::endl;
	std::cout << "and it requires " << this->getReq_Tick() << " to sign it" << std::endl;
	std::cout << "and it requires " << this->getReq_Exe() << " to execute it" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy): AForm(copy), _target(copy.getTarget())
{
	std::cout << "Presidential Copy Constructor Used" << std::endl;
	*this = copy;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << "Presidential Equals Operator Is Used" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs.getTarget();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default Destructor Used" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getTick())
	{
		if (executor.getGrade() <= this->getReq_Exe())
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSigned();
}