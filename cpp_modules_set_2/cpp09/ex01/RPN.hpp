/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:42:29 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/27 17:13:32 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <exception>
# include <iostream>
# include <stack>
# include <string>
# include <ctype.h>

# define DEFAULT	"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[1;36m"

class RPN
{
	private:
		
		std::string			_rpn;
		std::stack<char>	_operations;
		std::stack<int>		_numbers;
		bool				_explain;
		int 				_count;
		
		class DivideByZero : public std::exception
		{
			public:

			const char * what() const throw();
		};

		class Inusfficient : public std::exception
		{
			public:

			const char * what() const throw();
		};

		void				_fillStack(std::string argv);
		void				_check_argument(std::string argv);
		void				_doOperation(void);

	public:
	
		RPN(void);
		RPN(RPN const & copy);
		RPN & operator=(RPN const & rhs);
		~RPN(void);
		
		RPN(std::string argv, int ac);
};

#endif