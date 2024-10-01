/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:20:34 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/01 11:25:02 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.str1 = "Spiderman";
	data.num = 69;
	data.trueBool = true;
	std::cout << "Data before serialization: " << std::endl << data << std::endl;

	uintptr_t serializedData = Serializer::serialize(&data);
	Data *deserializedData = Serializer::deserialize(serializedData);

	std::cout << "Data after serialization and deserialization: " << std::endl << *deserializedData << std::endl;

	return 0;
}
