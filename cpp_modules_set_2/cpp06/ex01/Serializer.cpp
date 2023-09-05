/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:19:36 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/23 12:41:01 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <sys/_types/_uintptr_t.h>
#include <sys/types.h>

Serializer::Serializer()
{
	
}

Serializer::Serializer(Serializer const & copy)
{
	*this = copy;
}

Serializer & Serializer::operator=(Serializer const & rhs)
{
	if (this == &rhs)
	{}
	return (*this);
}

Serializer::~Serializer()
{
	
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}