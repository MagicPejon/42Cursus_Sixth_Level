/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:15:19 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/22 15:42:57 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_H
# define SCALARCONVERSION_H

# include <iostream>
# include <limits>
# include <stdlib.h>

class ScalarConverter
{
	private:
	
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & copy);
		ScalarConverter & operator=(ScalarConverter const & rhs);

	public:
	
		~ScalarConverter(void);
		
		static void	convert(std::string str);
		static void	toChar(std::string str);
		static void	toInt(std::string str);
		static void	toDouble(std::string str);
		static void	toFloat(std::string str);
};

#endif