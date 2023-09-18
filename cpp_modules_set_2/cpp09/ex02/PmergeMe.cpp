/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:07:14 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/18 18:03:09 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	
}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
	*this = copy;	
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
	if (this != &rhs)
	{
		
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	
}

void PmergeMe::_print_arranged()
{
	for(unsigned long i = 0; i < this->_vec.size(); i++)
	{
		std::cout << this->_vec.at(i) << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::_return(T &container, T &temp)
{
	size_t	pointer;
	size_t	save;

	pointer = 0;
	save = -1;
	while(!temp.empty())
	{
		if (temp[0] > container[pointer] && container[pointer] != 0)
			save = pointer;
		pointer++;
		if ((container.begin() + pointer) == container.end())
		{
			save++;
			container.insert(container.begin() + save, temp[0]);
			temp.erase(temp.begin());
			save = -1;
			pointer = 0;
		}
	}
}

template <typename T>
void PmergeMe::_rearrange(T &container, T &temp)
{
	size_t	pointer;

	pointer = 0;
	while (container[pointer] && pointer < container.size() - 1)
	{
		if (container[pointer] > container[pointer + 1])
		{
			std::swap(container[pointer], container[pointer + 1]);
			std::swap(temp[pointer], temp[pointer + 1]);
			pointer = 0;
		}
		pointer++;
	}
}

template <typename T>
T PmergeMe::_transfer(T &container)
{
	size_t	pointer;
	int		size;
	int		true_size;
	T		temp;

	pointer = 0;
	size = container.size();
	true_size = container.size();
	while (size != 0 && size != 1)
	{
		if (container[pointer] > container[pointer + 1])
		{
			temp.push_back(container[pointer]);
			container.erase(container.begin() + pointer);
		}
		else 
		{
			temp.push_back(container[pointer + 1]);
			container.erase(container.begin() + (pointer + 1));
		}
		pointer++;
		size -= 2;
	}
	if ((container.size() % 2 != 0 && container.size() != 1) || (true_size == 3))
	{
		temp.push_back(container[pointer]);
		container.erase(container.begin() + pointer);
	}
	return (temp);
}

void PmergeMe::_sort_deque()
{
	std::deque<int>	temp;
	
	temp = this->_transfer(this->_deq);
	this->_rearrange(this->_deq, temp);
	this->_return(this->_deq, temp);
}

void PmergeMe::_sort_vector()
{
	std::vector<int>	temp;
	
	temp = this->_transfer(this->_vec);
	// _print_arranged();
	// for(unsigned long i = 0; i < temp.size(); i++)
	// {
	// 	std::cout << "temp: " << temp.at(i) << " ";
	// }
	// std::cout << std::endl;
	this->_rearrange(this->_vec, temp);
	this->_return(this->_vec, temp);
}

bool PmergeMe::_already_sorted()
{
	std::vector<int>::iterator it;

	it = this->_vec.begin();
	while (it != this->_vec.end() - 1)
	{
		if (*it < *(it + 1))
			it++;
		else
			return (false);
	}
	return (true);
}

void PmergeMe::_sort_containers()
{
	clock_t	start, finish;
	double	vec_time, deq_time;

	
	if (!(_already_sorted()))
	{
		std::cout << "After: ";
		start = clock();
		this->_sort_vector();
		finish = clock();
		vec_time = ((double)(finish - start)) / 1000000;
		
		start = clock();
		this->_sort_deque();
		finish = clock();
		deq_time = ((double)(finish - start)) / 1000000;

		this->_print_arranged();
		std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::vector : " << std::fixed << vec_time << std::endl;
		std::cout << "Time to process a range of " << this->_deq.size() << " elements with std::deque : " << std::fixed <<  deq_time << std::endl;
	}
	else
		std::cout << "This set is already sorted" << std::endl;
}

void	PmergeMe::_fill_containers(char **av)
{
	int 		i;
	int			fill;

	i = 0;
	std::cout << "Before: ";
	while (av[++i])
	{
		fill = atoi(av[i]);
		this->_vec.push_back(fill);
		this->_deq.push_back(fill);
		std::cout << fill << " ";
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(char **av)
{
	this->_fill_containers(av);
	this->_sort_containers();
}