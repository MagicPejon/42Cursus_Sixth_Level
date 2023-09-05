/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:42:45 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/29 18:06:25 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template < typename T >
MutantStack<T>::MutantStack()
{
	
}

template < typename T >
MutantStack<T>::MutantStack(MutantStack const & copy)
{
	*this = copy;
}

template < typename T >
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & rhs)
{
	if (this != &rhs)
	{
		this->c = rhs.c;
	}
	return (*this);
}

template < typename T >
MutantStack<T>::~MutantStack()
{
	
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template < typename T >
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template < typename T >
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

#endif