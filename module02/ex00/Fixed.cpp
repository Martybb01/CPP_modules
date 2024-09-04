/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:14:45 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/04 20:25:31 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

/* se avessi messo *this->src, allora avrei invocato l'operatore di
assegnazione e si sarebbe prodotta la stampa extra */
Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = src.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=( const Fixed &src ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

void Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}


