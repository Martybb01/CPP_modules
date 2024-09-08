/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:05:38 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/08 17:14:06 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(Ice const &src) {
	std::cout << "Ice copy constructor" << std::endl;
	*this = src;
}

Ice::~Ice() {
	std::cout << "Ice destructor" << std::endl;
}

Ice &Ice::operator=(Ice const &src) {
	std::cout << "Ice assignation operator" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return *this;
}

AMateria* Ice::clone() const {
	std::cout << "Ice clone" << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
