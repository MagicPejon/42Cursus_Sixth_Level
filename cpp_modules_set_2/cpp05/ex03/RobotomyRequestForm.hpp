/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:05:07 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/12 19:26:04 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:

	std::string _target;

	public:
	
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & copy);
	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
	~RobotomyRequestForm(void);

	std::string	getTarget(void) const;
	void		execute(Bureaucrat const & executor) const ;
};

#endif