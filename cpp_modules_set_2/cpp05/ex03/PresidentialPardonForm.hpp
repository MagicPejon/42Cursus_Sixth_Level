/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:05:42 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/12 18:39:31 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

	std::string _target;

	public:
	
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & copy);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
	~PresidentialPardonForm(void);

	std::string	getTarget(void) const;
	void		execute(Bureaucrat const & executor) const;
};

#endif