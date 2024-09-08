/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:16:55 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 19:59:44 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &copy): Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain();
	*this = copy;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(const Cat &copy) {
	std::cout << "Cat assignation overload operator called" << std::endl;
	if (this != &copy)
	{
		this->_type = copy._type;
		*_brain = *copy._brain;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "MEOW MEOW" << std::endl;
}
