/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:14:11 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/08 17:15:38 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {
	std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(Cure const &src) {
	std::cout << "Cure copy constructor" << std::endl;
	*this = src;
}

Cure::~Cure() {
	std::cout << "Cure destructor" << std::endl;
}

Cure &Cure::operator=(Cure const &src) {
	std::cout << "Cure assignation operator" << std::endl;
	if (this != &src)
		AMateria::operator=(src);
	return *this;
}

AMateria* Cure::clone() const {
	std::cout << "Cure clone" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
