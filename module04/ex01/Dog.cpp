/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:18:18 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 20:00:47 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &copy): Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain();
	*this = copy;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Dog assignation overload operator called" << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		*_brain = *copy._brain;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "WOOF WOOF" << std::endl;
}
