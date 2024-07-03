/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:29:12 by adhaka            #+#    #+#             */
/*   Updated: 2024/07/02 23:48:14 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

void testSerializer()
{
	Data myData;
	myData.n = 42;
	myData.s = "Hello, world!";

	std::cout << "Original Data:" << std::endl;
	std::cout << "Number: " << myData.n << ", Text: " << myData.s << std::endl;

	uintptr_t raw = Serializer::serialize(&myData);

	Data *deserializedData = Serializer::deserialize(raw);

	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "Number: " << deserializedData->n << ", Text: " << deserializedData->s << std::endl;

	if (deserializedData->n != myData.n || deserializedData->s != myData.s)
	{
		std::cout << "Test failed: Deserialized data does not match the original." << std::endl;
	}
	else
	{
		std::cout << "Test passed: Serialization and deserialization are correct." << std::endl;
	}
}

int main()
{
	testSerializer();
	return 0;
}
