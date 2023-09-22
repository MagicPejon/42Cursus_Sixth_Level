/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:42:52 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/18 17:22:28 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iterator>
#include <vector>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	// std::stack<int> lel;
	// std::stack<int>::iterator nope; no iterator for stack :(
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	std::cout << std::endl;
	std::cout << "-------------Iterating through mstack------------" << std::endl << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	MutantStack<int> s(mstack);
	it = s.begin();
	ite = s.end();
	
	std::cout << std::endl;
	std::cout << "-------------Iterating through s(copy of mstack)------------" << std::endl << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return (0);
}