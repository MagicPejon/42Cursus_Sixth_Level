/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:41:35 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/30 14:13:21 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _size(0)
{
	
}

Span::Span(Span const & copy)
{
	*this = copy;
}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs._size;
		this->_storage = rhs._storage;
	}
	return (*this);
}

Span::~Span()
{
	
}

Span::Span(unsigned int size): _size(size)
{
	
}

void Span::addNumber(int num)
{
	if (this->_storage.size() == this->_size)
		throw Span::MaxStorageLimitReached();
	this->_storage.push_back(num);
}

int Span::longestSpan()
{
	int lspan;

	if (this->_storage.size() < 2)
		throw Span::InvalidStorageUsed();
	std::sort(this->_storage.begin(), this->_storage.end());
	lspan = this->_storage[this->_storage.size() - 1] - this->_storage[0];
	return (lspan);
}

int Span::shortestSpan()
{
	int sspan;

	if (this->_storage.size() < 2)
		throw Span::InvalidStorageUsed();
	std::sort(this->_storage.begin(), this->_storage.end());
	sspan = this->_storage[1] - this->_storage[0];
	for (unsigned int i = 1; i < (this->_storage.size() - 1); i++)
	{
		if (this->_storage[i + 1] - this->_storage[i] < sspan)
			sspan = this->_storage[i + 1] - this->_storage[i];
	}
	return (sspan);
}

void Span::addNumber_set(int nums)
{
	srand(time(NULL));
	for (int i = 0; i < nums; i++)
		this->_storage.insert(this->_storage.begin(), rand() % 500);
	std::cout << "Numbers added are: ";
	for (int i = 0; i < nums; i++)
		std::cout << this->_storage[i] << " ";
	std::cout << std::endl;
		
}

const char * Span::MaxStorageLimitReached::what() const throw()
{
	return ("Maximum Size Reached: can't add more numbers");
}

const char * Span::InvalidStorageUsed::what() const throw()
{
	return ("Invalid Storage Used: empty, has only one number or no span can be found");
}