/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:15:19 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/20 15:21:07 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_H
# define SCALARCONVERSION_H

# include <iostream>
# include <string>
# include <cstddef>

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