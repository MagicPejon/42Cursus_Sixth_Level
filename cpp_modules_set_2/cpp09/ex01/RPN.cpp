/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:42:13 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/29 12:54:41 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <_ctype.h>

RPN::RPN()
{
}

RPN::RPN(RPN const & copy)
{
	*this = copy;
}

RPN & RPN::operator=(RPN const & rhs)
{
	if (this != &rhs)
	{
		this->_operations = rhs._operations;
		this->_numbers = rhs._numbers;
	}
	return (*this);
}

RPN::~RPN()
{
}

void RPN::_doOperation()
{
	int		operand1, operand2;
	char	operation;
	
	operand2 = this->_numbers.top();
	this->_numbers.pop();
	operand1 = this->_numbers.top();
	this->_numbers.pop();
	operation = this->_operations.top();
	this->_operations.pop();
	if (this->_explain)
	{
		if (this->_count == 2)
			std::cout << CYAN;
		std::cout << operand1;
		if (this->_count == 2)
			std::cout << DEFAULT;
		std::cout << " ";
		std::cout << operation;
		if (this->_count > 2)
			std::cout << CYAN;
		std::cout << " " << operand2;
		if (this->_count > 2)
			std::cout << DEFAULT;
	}
	if (operand2 == 0 && operation == '/')
	{
		if (this->_explain)
			std::cerr << std::endl;
		throw RPN::DivideByZero();
	}
	else if (operation == '+')
		this->_numbers.push(operand1 + operand2);
	else if (operation == '-')
		this->_numbers.push(operand1 - operand2);
	else if (operation == '*')
		this->_numbers.push(operand1 * operand2);
	else if (operation == '/')
		this->_numbers.push(operand1 / operand2);
	if (this->_explain)
		std::cout << " = " << CYAN << this->_numbers.top() << DEFAULT << std::endl;
}

void RPN::_check_argument(std::string argv)
{
	int num_count = 0;
	int op_count = 0;

	for(size_t i = 0; i < argv.size(); i++)
	{
		if (isdigit(argv[i]))
			num_count++;
		else if (argv[i] == '+' || (argv[i] == '-' && !isdigit(argv[i + 1])) || argv[i] == '*' || argv[i] == '/')
			op_count++;
	}
	if (num_count - 1 != op_count)
		throw RPN::Inusfficient();
}

void RPN::_fillStack(std::string argv)
{
	int size;

	this->_check_argument(argv);
	size = argv.size();
	for (int i = 0; i < size; i++)
	{
		if (argv[i] == ' ')
			continue ;
		else if (isdigit(argv[i]))
		{
			this->_numbers.push(argv[i] - '0');
			this->_count++;
		}
		else if (argv[i] == '-' && isdigit(argv[i + 1]))
		{
			i++;
			this->_numbers.push((argv[i] - '0') * -1);
			this->_count++;
		}
		else
			this->_operations.push(argv[i]);
		if (this->_operations.size() == 1 && this->_numbers.size() >= 2)
		{
			_doOperation();
			this->_count--;
		}
	}	
}

RPN::RPN(std::string argv, int ac): _explain(false), _count(0)
{
	if (ac == 3)
		this->_explain = true;
	try
	{
		this->_fillStack(argv);
		std::cout << this->_numbers.top() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl; 
	}
}


const char * RPN::DivideByZero::what() const throw()
{
	return ("Dividing by zero");
}

const char * RPN::Inusfficient::what() const throw()
{
	return ("Not enough numbers or operators");
}
