/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:29:42 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/12 18:28:56 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Blank"), _tick(false), _req_tick(75), _req_exe(75)
{
	std::cout << "Default AForm Constructor Used" << std::endl;
	
}

AForm::AForm(std::string name, int req_to_tick, int req_to_exe): _name(name), _tick(false), _req_tick(req_to_tick), _req_exe(req_to_exe)
{
	if (req_to_tick > 150 || req_to_exe > 150)
		throw AForm::GradeTooLowException();
	if (req_to_tick < 1 || req_to_exe < 1)
		throw AForm::GradeTooHighException();
	std::cout << "Parameterized AForm Constructor Used" << std::endl;
	std::cout << "The Aform's name is " << name << std::endl;
	std::cout << "and the grade required to sign it: " << req_to_tick << std::endl;
	std::cout << "and the grade required to execute it: " << req_to_exe << std::endl;
}

AForm::AForm(AForm const & copy)
{
	std::cout << "AForm Copy Constructor Used" << std::endl;
	*this = copy;
}

AForm & AForm::operator=(AForm const & rhs)
{
	std::cout << "AForm Equal Operator Used" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_tick = rhs._tick;
		this->_req_tick = rhs._req_tick;
		this->_req_exe = rhs._req_exe;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Default AForm Destructor Used" << std::endl;
}

std::string AForm::getName() const
{
	return(this->_name);
}

bool AForm::getTick() const
{
	return(this->_tick);
}

int AForm::getReq_Tick() const
{
	return(this->_req_tick);
}

int AForm::getReq_Exe() const
{
	return(this->_req_exe);
}

void AForm::beSigned(Bureaucrat & personnel)
{
	if (personnel.getGrade() > this->_req_tick)
	{
		personnel.signForm(this->_name, false);
		throw AForm::GradeTooLowException();
	}
	else
	{
		this->_tick = true;
		personnel.signForm(this->_name, true);
	}
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

const char * AForm::FormNotSigned::what() const throw()
{
	return ("Form is not signed");
}

std::ostream & operator<<(std::ostream & out, AForm const & rhs)
{
	out << "Name: "<< rhs.getName() << std::endl;
	out << "Ticked (0 for no, 1 for yes): "<< rhs.getTick() << std::endl;
	out << "Grade required to sign this Aform: "<< rhs.getReq_Tick() << std::endl;
	out << "Grade required to execute this Aform: " << rhs.getReq_Exe() << std::endl;
	return (out);
}
