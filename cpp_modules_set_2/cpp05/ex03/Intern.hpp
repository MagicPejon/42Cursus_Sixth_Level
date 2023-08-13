/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:21:35 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/13 19:43:57 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:

	class NoFormFound : public std::exception
	{
		public:
		
		const char * what() const throw();
	};
	
	public:

	Intern(void);
	Intern(Intern const & copy);
	Intern & operator=(Intern const & rhs);
	~Intern(void);

	AForm *makeForm(std::string name, std::string target);
};

#endif