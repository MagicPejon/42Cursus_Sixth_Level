/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:27:30 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/05 21:30:49 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <_types/_intmax_t.h>
# include <iostream>
# include <fstream>
# include <string>
# include <stdlib.h>
# include <iomanip>
# include <map>

# define DEFAULT	"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[1;36m"

class BitcoinExchange
{
	private:

		std::map<std::string, float> _rate; 
	
	class InvalidFile: public std::exception
	{
		private:
		
		const char *	_msg;
		
		public:
		
		InvalidFile(const char * infile);
		const char * what() const throw();
		
	};

	class InvalidFormat : public std::exception
	{
		private:

		const char *	_msg;
		
		public:
		
		InvalidFormat(const char * infile);
		const char * what() const throw();
		
	};
	
	class InvalidNumber : public std::exception
	{
		private:

		const char *	_msg;
		
		public:
		
		InvalidNumber(int ln, const char * infile);
		const char * what() const throw();
		
	};

	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & copy);
		BitcoinExchange & operator=(BitcoinExchange const & rhs);
		~BitcoinExchange(void);
		
		BitcoinExchange(std::string infile);
		void		readFile();
		void		convert(std::string infile);
		bool		validateHeading(std::string line);
		void		split(std::string line, std::string infile, int line_no);
		float		validateValue(std::string value);
		bool		validateDate(std::string date);
		bool		validateDelimiter(std::string line);
		void		printConversion(std::string date, float con_val);
		std::string	closestDate(std::string date);
		
};

#endif