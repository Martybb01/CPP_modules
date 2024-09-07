/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:07:28 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 18:24:56 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string const &type): _type(type) {
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy) {
	std::cout << "Animal assignation overload operator called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

std::string const &Animal::getType() const {
	return (this->_type);
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}
