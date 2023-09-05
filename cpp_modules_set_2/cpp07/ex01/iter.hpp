/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:24:18 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/26 12:28:58 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template < typename I >
void iterate(I & letter)
{
	std::cout << "BEFORE: " << letter << std::endl;
	letter += 1;
	std::cout << "AFTER: " << letter << std::endl;
	std::cout << "-----------------------" << std::endl;
}

template < typename T >
void iter(T * str, int const size, void (*func)(T & letter))
{
	for(int i = 0; i < size; i++)
	{
		func(str[i]);
	}
}

#endif