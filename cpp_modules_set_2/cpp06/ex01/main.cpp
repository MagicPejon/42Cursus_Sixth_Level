/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:15:40 by amalbrei          #+#    #+#             */
/*   Updated: 2023/08/28 14:06:39 by amalbrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *data;
	data->data_title = "My paycheck";
	data->number = 42;
	
	uintptr_t serializedValue = Serializer::serialize(data);
	
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << "serializedValue  : " << serializedValue << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	
	Data *deserializedValue = Serializer::deserialize(serializedValue);

	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << "&data            : " << &data << std::endl;
	std::cout << "deserializeValue : " << deserializedValue << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << deserializedValue->data_title << " + " << deserializedValue->number << " = " << "nono" <<  std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	return (0);
}