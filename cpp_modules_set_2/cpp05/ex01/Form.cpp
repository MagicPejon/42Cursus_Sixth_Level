/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:29:42 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/11 20:40:39 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Blank"), _tick(false), _req_tick(75), _req_exe(75)
{
	std::cout << "Default Form Constructor Used" << std::endl;
	
}

Form::Form(std::string name, int req_to_tick, int req_to_exe): _name(name), _tick(false), _req_tick(req_to_tick), _req_exe(req_to_exe)
{
	if (req_to_tick > 150 || req_to_exe > 150)
		throw Form::GradeTooLowException();
	if (req_to_tick < 1 || req_to_exe < 1)
		throw Form::GradeTooHighException();
	std::cout << "Parameterized Form Constructor Used" << std::endl;
	std::cout << "The form's name is " << name << std::endl;
	std::cout << "and the grade required to sign it: " << req_to_tick << std::endl;
	std::cout << "and the grade required to execute it: " << req_to_exe << std::endl;
}

Form::Form(Form const & copy)
{
	std::cout << "Form Copy Constructor Used" << std::endl;
	*this = copy;
}

Form & Form::operator=(Form const & rhs)
{
	std::cout << "Form Equal Operator Used" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_tick = rhs._tick;
		this->_req_tick = rhs._req_tick;
		this->_req_exe = rhs._req_exe;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Default Form Destructor Used" << std::endl;
}

std::string Form::getName() const
{
	return(this->_name);
}

bool Form::getTick() const
{
	return(this->_tick);
}

int Form::getReq_Tick() const
{
	return(this->_req_tick);
}

int Form::getReq_Exe() const
{
	return(this->_req_exe);
}

void Form::beSigned(Bureaucrat & personnel)
{
	if (personnel.getGrade() > this->_req_tick)
	{
		personnel.signForm(this->_name, false);
		throw Form::GradeTooLowException();
	}
	else
	{
		this->_tick = true;
		personnel.signForm(this->_name, true);
	}
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream & operator<<(std::ostream & out, Form const & rhs)
{
	out << "Name: "<< rhs.getName() << std::endl;
	out << "Ticked (0 for no, 1 for yes): "<< rhs.getTick() << std::endl;
	out << "Grade required to sign this form: "<< rhs.getReq_Tick() << std::endl;
	out << "Grade required to execute this form: " << rhs.getReq_Exe() << std::endl;
	return (out);
}
