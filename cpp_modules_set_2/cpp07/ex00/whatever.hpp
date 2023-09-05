/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:49:21 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/25 18:40:01 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template < typename T >
void swap(T & x, T & y)
{
	T tmp = 0;
	
	tmp = x;
	x = y;
	y = tmp;
}

template < typename T >
T min( T const & x, T const & y)
{
	return ( (x < y) ? x : y);
}

template < typename T >
T max( T const & x, T const & y)
{
	return ( (x > y) ? x : y);
}

#endif