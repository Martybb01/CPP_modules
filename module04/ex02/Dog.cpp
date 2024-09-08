/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:16:56 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/08 12:22:38 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal() {
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
	_type = "Dog";
}

Dog::Dog(const Dog &copy): AAnimal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*copy._brain);
	_type = copy._type;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &copy) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
		*_brain = *copy._brain;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "WOOF WOOF" << std::endl;
}
