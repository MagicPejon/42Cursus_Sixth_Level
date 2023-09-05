/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:23:59 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/26 12:33:37 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	char test[5] = {'a', 'b', 'c', 'd', 'e'};
	iter(test, 5, iterate);
	int num[3] = {1, 2, 3};
	iter(num, 3, iterate);
}