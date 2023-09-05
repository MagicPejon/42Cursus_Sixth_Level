/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:25:08 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/24 14:23:00 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <exception>

Base *generate()
{
	srand(time(NULL));
	int num = rand() % 3;
	if (num == 0)
		return new A;
	else if (num == 1)
		return new B;
	else
		return new C;
}

void identify(Base *base)
{
	if (dynamic_cast<A*>(base))
		std::cout << "Base is A" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "Base is B" << std::endl;
	else if (dynamic_cast<C*>(base))
		std ::cout << "Base is C" << std::endl;
}

void identify(Base &base)
{
	try
	{
		A &a = dynamic_cast<A&>(base);
		(void)a;
		std::cout << "Base is A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(base);
			(void)b;
			std::cout << "Base is B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(base);
				(void)c;
				std::cout << "Base is C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Base is not A, B nor C" << std::endl;
			}
		}
	}
}