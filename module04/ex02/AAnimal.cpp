/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:02:50 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/20 18:48:35 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal constructor called" << std::endl;
	_type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &copy): _type(copy._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->_type = copy._type;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return *this;
}

std::string AAnimal::getType() const {
	return _type;
}
