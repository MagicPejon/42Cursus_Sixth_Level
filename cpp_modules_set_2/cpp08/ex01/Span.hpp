/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:41:28 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/20 15:11:39 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <ctime>

class Span
{
	private:

		unsigned int		_size;
		std::vector<int>	_storage;	
		
		class MaxStorageLimitReached : public std::exception
		{
			public:
			
			const char * what() const throw();
			
		};
	
		class InvalidStorageUsed : public std::exception
		{
			public:
	
			const char * what() const throw();
			
		};
	
	public:

		Span();
		Span(Span const & copy);
		Span & operator=(Span const & rhs);
		~Span();
		
		Span(unsigned int size);
		void				addNumber(int num);
		unsigned int		longestSpan();
		unsigned int		shortestSpan();
		void				addNumber_set(int nums);
	
};

#endif