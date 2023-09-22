/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:19:54 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/18 16:36:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdint.h>

struct Data
{
	std::string 	data_title;
	int				number;
};

class Serializer
{
	private:

		Serializer(void);
		Serializer(Serializer const & copy);
		Serializer & operator=(Serializer const & rhs);

	public:

		~Serializer(void);
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);	
};

#endif