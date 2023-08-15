/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:04:35 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/09 18:55:49 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

class Bureaucrat
{
	private:
	
	std::string _name;
	int			_grade;

	class GradeTooHighException : public std::exception
	{
		public:
		
		const char * what() const throw();
		
	};

	class GradeTooLowException : public std::exception
	{
		public:
		
		const char * what() const throw();
		
	};
	
	public:

	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & copy);
	Bureaucrat & operator=(Bureaucrat const & rhs);
	~Bureaucrat(void);
	
	std::string getName(void) const;
	int			getGrade(void) const;
	void		gradeIncrement(void);
	void		gradeDecrement(void);
};

std::ostream &operator<<(std::ostream & out, Bureaucrat const & rhs);

#endif