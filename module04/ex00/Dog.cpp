/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:18:18 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 18:26:15 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &copy): Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Dog assignation overload operator called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "WOOF WOOF" << std::endl;
}
