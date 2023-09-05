/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:25:19 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/29 17:49:52 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

template < typename T >
int easyfind(T &container, int num_to_find)
{
	typename T::iterator index = std::find(container.begin(), container.end(), num_to_find);

	if (index == container.end())
		throw std::runtime_error("Could not find given element");
	return (*index);
}

#endif