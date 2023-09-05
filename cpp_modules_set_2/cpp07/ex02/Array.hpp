/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:42:24 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/26 16:22:01 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <exception>

template < typename T >
class Array
{
	private:

		unsigned int	_size;
		T				*_content;
		
		class OutOfBoundsException : public std::exception
		{
			public:

			const char * what() const throw();
			
		};

	public:

		Array(void);
		Array(Array const & copy);
		Array & operator=(Array const & rhs);
		~Array();
		
		Array(unsigned int n);
		T & operator[](unsigned int index);
		unsigned int size() const;
};

# include "Array.tpp"

#endif