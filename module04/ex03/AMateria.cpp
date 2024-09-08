/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:55:29 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/08 17:02:50 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "AMateria constructor" << std::endl;
}

AMateria::AMateria(AMateria const &src) {
	std::cout << "AMateria copy constructor" << std::endl;
	*this = src;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &src) {
	std::cout << "AMateria assignation operator" << std::endl;
	if (this != &src)
		_type = src._type;
	return *this;
}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}
