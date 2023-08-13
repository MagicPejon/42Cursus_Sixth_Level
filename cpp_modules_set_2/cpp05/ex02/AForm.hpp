/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:29:47 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/12 18:40:02 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat; 
class AForm
{
	private:

	std::string	_name;
	bool		_tick;
	int			_req_tick;
	int			_req_exe;
	
	protected:
	
	class GradeTooHighException : public std::exception
	{
		public:
		
		const char *what() const throw();
		
	};

	class GradeTooLowException : public std::exception
	{
		public:
		
		const char *what() const throw();
		
	};

	class FormNotSigned : public std::exception
	{
		public:

		const char *what() const throw();
	};
	
	public:

	AForm(void);
	AForm(std::string name, int req_to_tick, int req_to_execute);
	AForm(AForm const & copy);
	AForm & operator=(AForm const & rhs);
	virtual ~AForm(void) = 0;

	std::string 	getName(void) const;
	bool			getTick(void) const;
	int				getReq_Tick(void) const;
	int				getReq_Exe(void) const;

	void			beSigned(Bureaucrat & personnel);
	virtual void	execute(Bureaucrat const & executor) const  = 0;
};

std::ostream & operator<<(std::ostream & out, AForm const & rhs);

#endif