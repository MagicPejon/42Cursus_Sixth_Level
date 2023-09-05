/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:42:39 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/26 19:16:12 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template < typename T >
Array<T>::Array(): _size(0), _content(0)
{
	
}

template < typename T >
Array<T>::Array(Array const & copy): _size(copy._size)
{
	this->_content = new T[copy.size()];
	for (unsigned int i = 0; i < copy._size; i++)
		this->_content[i] = copy._content[i];
}

template < typename T >
Array<T> & Array<T>::operator=(Array const & rhs)
{
	if (this != &rhs)
	{
		if (this->_content && this->_size)
			delete [] this->_content;
		this->_size = rhs._size;
		this->_content = new T[rhs._size];
		for (unsigned int i = 0; i < rhs._size; i++)
			this->_array[i] = rhs._content[i];
	}
	return (*this);
}

template < typename T >
Array<T>::~Array()
{
	delete [] this->_content;
}

template < typename T >
Array<T>::Array(unsigned int n): _size(n), _content(new T[n])
{
	
}

template < typename T >
T & Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index >= this->_size)
	{
		throw Array<T>::OutOfBoundsException();
	}
	return (this->_content[index]);
}

template < typename T >
const char * Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index Out Of Bounds");
}

template < typename T >
unsigned int Array<T>::size() const
{
	return (this->_size);
}

#endif