/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:27:06 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/06 11:39:06 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

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

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_fractionalBits));
}

void Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

int Fixed::getRawBits( void ) const {
	return this->_value;
}

float Fixed::toFloat( void ) const {
	return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const {
	return this->_value >> this->_fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &src) {
	out << src.toFloat();
	return out;
}
