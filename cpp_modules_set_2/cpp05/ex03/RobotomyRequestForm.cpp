/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:04:57 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/12 19:29:09 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("Notarget")
{
	std::cout << "Robotomy Default Constructor Used" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Robotomy Parametrized Constructor Used" << std::endl;
	std::cout << this->getName() << " is made" << std::endl;
	std::cout << "with " << this->_target << " as its target" << std::endl;
	std::cout << "and it requires " << this->getReq_Tick() << " to sign it" << std::endl;
	std::cout << "and it requires " << this->getReq_Exe() << " to execute it" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy): AForm(copy), _target(copy.getTarget())
{
	std::cout << "Robotomy Copy Constructor Used" << std::endl;
	*this = copy;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << "Robotomy Equals Operator Is Used" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default Destructor Used" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getTick())
	{
		if (executor.getGrade() <= this->getReq_Exe())
		{
			if (rand() % 99 < 50)
			{
				std::cout << "skrrrrraaaaaaa.....bub drub bud da" << std::endl;
				std::cout << "Congratulations " << this->_target << " has been robotomized" << std::endl;
			}
			else
				std::cout << "Robotomization failed, try again later" << std::endl;
		}	
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSigned();
}