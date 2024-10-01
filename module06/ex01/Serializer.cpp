/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:16:19 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/01 11:20:28 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

std::ostream &operator<<(std::ostream &os, Data const &data)
{
	os << "addr: " << &data << std::endl;
	os << "str1: " << data.str1 << std::endl;
	os << "num: " << data.num << std::endl;
	os << "trueBool: " << data.trueBool << std::endl;
	return os;
}
