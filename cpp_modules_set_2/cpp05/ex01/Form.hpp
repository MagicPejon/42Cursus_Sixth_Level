/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:29:47 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/11 21:06:33 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:

	std::string	_name;
	bool		_tick;
	int			_req_tick;
	int			_req_exe;
	
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
	
	public:

	Form(void);
	Form(std::string name, int req_to_tick, int req_to_execute);
	Form(Form const & copy);
	Form & operator=(Form const & rhs);
	~Form(void);

	std::string getName(void) const;
	bool		getTick(void) const;
	int			getReq_Tick(void) const;
	int			getReq_Exe(void) const;

	void		beSigned(Bureaucrat & personnel);
};

std::ostream & operator<<(std::ostream & out, Form const & rhs);

#endif