/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:27:19 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/27 16:43:00 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
	*this = copy;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
	{

	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(std::string infile)
{
	try
	{
		this->readFile();
		this->convert(infile);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}	
}

void	BitcoinExchange::readFile()
{
	std::string		name("data.csv");
	std::ifstream	data("data.csv");
	
	if (data.fail())
	{
		data.close();
		throw BitcoinExchange::InvalidFile(name.c_str());
	}
	std::string line;
	std::string key;
	std::string value;
	getline(data, line);
	while(!data.eof())
	{
		getline(data, line);
		if (line.empty())
			break ;
		std::stringstream str(line);
		getline(str, key, ',');
		getline(str, value);
		this->_rate[key] = atof(value.c_str());
	}
	data.close();
}

std::string BitcoinExchange::closestDate(std::string date, int line_no, std::string infile)
{
	std::stringstream	read(date);
	std::string			year, month, day;

	getline(read, year, '-');
	getline(read, month, '-');
	getline(read, day);
	int	y = atoi(year.c_str());
	int m = atoi(month.c_str());
	int d = atoi(day.c_str());
	if (d > 1)
		d--;
	else if (m > 1)
	{
		d = 31;
		m--;
	}
	else if (y > 2008)
	{
		d = 31;
		m = 12;
		y--;
	}
	if (y <= 2008)
	{
		std::cerr << YELLOW << "DATE: date not in proper range: " << DEFAULT;
		throw BitcoinExchange::InvalidNumber(line_no, infile.c_str());
	}
	std::string			updated_date;
	std::stringstream	new_date;
	new_date << y << '-' << std::setw(2) << std::setfill('0')\
	 << m << '-' << std::setw(2) << std::setfill('0') << d;
	updated_date = new_date.str();
	return (updated_date);
}

void BitcoinExchange::printConversion(std::string date, float con_val, int line_no, std::string infile)
{
	if (this->_rate.find(date) != this->_rate.end())
	{
		float output = con_val * this->_rate[date];
		std::cout << date << " => " << std::fixed << std::setprecision(2) << con_val;
		std::cout << " * " << this->_rate[date]; 
		std::cout << " = " << output << std::endl;
		return ;
	}
	else
	{
		date = this->closestDate(date, line_no, infile);
		this->printConversion(date, con_val, line_no, infile);
	}
}

bool BitcoinExchange::validateDelimiter(std::string line)
{
	int space_i = line.find(' ');
	if (line[space_i] == ' ' && line[space_i + 1] == '|' && line[space_i + 2] == ' ')
		return (true);
	else
	{
		std::cerr << YELLOW << "DELIMITER: extra spaces or incorrect delimiter: " << DEFAULT;
		return (false);
	}
}

bool BitcoinExchange::validateDate(std::string date)
{
	std::stringstream	str(date);
	std::string			day,month,year;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << YELLOW << "DATE: incorrect date format or separators: " << DEFAULT;
		return (false);
	}
	getline(str, year, '-');
	getline(str, month, '-');
	getline(str, day);
	int	y = atoi(year.c_str());
	int	m = atoi(month.c_str());
	int	d = atoi(day.c_str());
	if ((y < 2009 || y > 2022) || (m < 1 || m > 12) || (d < 1 || d > 31))
	{
		std::cerr << YELLOW << "DATE: date not in proper range: " << DEFAULT;
		return (false);
	}
	else if ((m == 2 && d > 28) && (y != 2012 && y != 2016 && y != 2020))
	{
		std::cerr << YELLOW << "DATE: date not in proper range: " << DEFAULT;
		return (false);
	}
	else if ((m == 2 && d > 29) && (y == 2012 || y == 2016 || y == 2020))
	{
		std::cerr << YELLOW << "DATE: date not in proper range: " << DEFAULT;
		return (false);
	}
	return (true);
}

float BitcoinExchange::validateValue(std::string value)
{
	float rate = atof(value.c_str());
	
	if (value[0] == '.')
	{
		std::cerr << YELLOW << "VALUE: only decimal point found: " << DEFAULT;
		return (-1);
	}
	if (rate < 0)
	{
		std::cerr << YELLOW << "VALUE: negative value: " << DEFAULT;
		return (-1);
	}
	else if (rate > 1000)
	{
		std::cerr << YELLOW << "VALUE: " << "value above 1000: " << DEFAULT;
		return (-1);
	}
	return (rate);
		
}

void BitcoinExchange::split(std::string line, std::string infile, int line_no)
{
	std::stringstream	str(line);
	std::string			date, delimiter, value, extra;
	float				con_val;

	str >> date >> delimiter >> value >> extra;
	if (!extra.empty())
	{
		std::cerr << YELLOW << "VALUE: " << "invalid number (extra spaces etc.): " << DEFAULT;
		throw BitcoinExchange::InvalidNumber(line_no, infile.c_str());
	}
	con_val = this->validateValue(value);
	if (!this->validateDate(date) || !this->validateDelimiter(line) || con_val == -1)
		throw BitcoinExchange::InvalidNumber(line_no, infile.c_str());
	this->printConversion(date, con_val, line_no, infile);
}

bool BitcoinExchange::validateHeading(std::string line)
{
	if (line != "date | value")
		return (false);
	return (true);
}

void BitcoinExchange::convert(std::string infile)
{
	std::ifstream	collect(infile.c_str());

	if(collect.fail())
	{
		collect.close();
		throw BitcoinExchange::InvalidFile(infile.c_str());
	}
	std::string line;
	getline(collect, line);
	if (!this->validateHeading(line))
	{
		collect.close();
		throw BitcoinExchange::InvalidFormat(infile.c_str());
	}
	int line_no = 2;
	while (!collect.eof())
	{
		getline(collect, line);
		try
		{
			this->split(line, infile, line_no);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		line_no++;
	}
	collect.close();
}

BitcoinExchange::InvalidFile::InvalidFile(const char * infile)
{
	std::string append = infile;
	append = GREEN + append + DEFAULT;
	std::string msg = "Could not open or invalid file: " + append;
	this->_msg = msg.c_str();
	std::cerr << this->_msg;
}

const char * BitcoinExchange::InvalidFile::what() const throw()
{
	return ("");
}

BitcoinExchange::InvalidFormat::InvalidFormat(const char * infile)
{
	std::string append = infile;
	append = GREEN + append + DEFAULT;
	std::string msg = "File: \"" + append \
	+ "\" contains an invalid format, which should be \"date | value\"";
	this->_msg = msg.c_str();
	std::cerr << this->_msg;
	
}

const char * BitcoinExchange::InvalidFormat::what() const throw()
{
	return ("");
}

BitcoinExchange::InvalidNumber::InvalidNumber(int ln, const char * infile)
{
	std::stringstream convert;
	std::string append_n;
	convert << ln;
	convert >> append_n;
	std::string append_s = infile;
	append_s = GREEN + append_s + DEFAULT;
	std::string msg = "Error found in: \"" + append_s \
	+ "\" file, specifically at line: " + append_n;
	this->_msg = msg.c_str();
	std::cerr << this->_msg;
}

const char * BitcoinExchange::InvalidNumber::what() const throw()
{
	return ("");
}