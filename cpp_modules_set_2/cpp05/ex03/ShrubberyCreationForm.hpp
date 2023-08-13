/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:04:27 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/12 19:26:09 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:

	std::string _target;

	class FileNotOpened : public std::exception
	{
		public:

		const char *what() const throw();
	};
	
	public:
	
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & copy);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
	~ShrubberyCreationForm(void);

	std::string	getTarget(void) const;
	void		writeAsciiTree() const;
	void		execute(Bureaucrat const & executor) const ;
};

#endif