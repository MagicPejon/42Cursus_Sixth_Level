/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:07:35 by amalbrei          #+#    #+#             */
/*   Updated: 2023/09/15 18:22:32 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <ctype.h>
# include <time.h>

# define DEFAULT	"\033[0m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[1;36m"

class PmergeMe
{
	private:

		std::vector<int>	_vec;
		std::deque<int>		_deq;

		void				_fill_containers(char **av);
		void				_sort_containers(void);
		bool				_already_sorted(void);
		void				_sort_vector(void);
		void				_sort_deque(void);
		void				_print_arranged(void);
		
		template <typename T>
		T					_transfer(T &container);
		template <typename T>
		void				_rearrange(T &container, T &temp);
		template <typename T>
		void				_return(T &container, T &temp);
		
	public:

		PmergeMe(void);
		PmergeMe(PmergeMe const & copy);
		PmergeMe & operator=(PmergeMe const & rhs);
		~PmergeMe(void);
	
		PmergeMe(char **argv);
	
	
};

#endif