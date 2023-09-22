/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:07:14 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/21 18:45:25 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

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

template <typename T>
void PmergeMe::_print_arranged(T container, std::string type)
{
	std::cout << "After  (" << YELLOW << type << DEFAULT << "): ";
	for(unsigned long i = 0; i < container.size(); i++)
	{
		std::cout << std::setw(4) << container.at(i) << " ";
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
		// if (temp[0] > container[pointer] && container[pointer] != 0)
		// 	save = pointer;
		// pointer++;
		// if ((container.begin() + pointer) == container.end())
		// {
		// 	save++;
		// 	container.insert(container.begin() + save, temp[0]);
		// 	temp.erase(temp.begin());
		// 	save = -1;
		// 	pointer = 0;
		// }
		if (temp[0] < container[pointer] && container[pointer] != 0)
		{
			container.insert(container.begin() + pointer, temp[0]);
			temp.erase(temp.begin());
			pointer = 0;
			continue ;
		}
		else if (container.begin() + pointer + 1 == container.end())
		{
			container.insert(container.begin() + pointer + 1, temp[0]);
			temp.erase(temp.begin());
			pointer = 0;
			continue ;
		}
		pointer++;
	}
}

template <typename T>
void PmergeMe::_rearrange(T &container, T &temp)
{
	size_t	pointer;
	size_t	pointer_end;
	
	pointer = 0;
	pointer_end = container.size() - 1;
	while (pointer < pointer_end)
	{
		if (container[pointer] > container[pointer + 1])
		{
			std::swap(container[pointer], container[pointer + 1]);
			std::swap(temp[pointer], temp[pointer + 1]);
			pointer = 0;
			pointer_end = container.size() - 1;
			continue ;
		}
		else if (container[pointer_end] < container[pointer_end - 1])
		{
			std::swap(container[pointer_end], container[pointer_end - 1]);
			std::swap(temp[pointer_end], temp[pointer_end - 1]);
			pointer = 0;
			pointer_end = container.size() - 1;
			continue ;
		}
		pointer++;
		pointer_end--;
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
	if ((true_size % 2 != 0))
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
		start = clock();
		this->_sort_vector();
		finish = clock();
		vec_time = ((double)(finish - start)) / 1000000;
		
		start = clock();
		this->_sort_deque();
		finish = clock();
		deq_time = ((double)(finish - start)) / 1000000;

		this->_print_arranged(this->_vec, "vector");
		this->_print_arranged(this->_deq, "deque-");
		std::cout << "Time to process a range of " << YELLOW << this->_vec.size() << DEFAULT << " elements with std::vector : " << std::fixed << vec_time << std::endl;
		std::cout << "Time to process a range of " << YELLOW << this->_deq.size() << DEFAULT << " elements with std::deque : " << std::fixed <<  deq_time << std::endl;
	}
	else
		std::cout << "This set is already sorted" << std::endl;
}

void	PmergeMe::_fill_containers(char **av)
{
	int 		i;
	int			fill;

	i = 0;
	std::cout << "Before (" << YELLOW << "given-" << DEFAULT << "): ";
	while (av[++i])
	{
		fill = atoi(av[i]);
		this->_vec.push_back(fill);
		this->_deq.push_back(fill);
		std::cout << std::setw(4) << fill << " ";
	}
	std::cout << std::endl;
}

PmergeMe::PmergeMe(char **av)
{
	this->_fill_containers(av);
	this->_sort_containers();
}