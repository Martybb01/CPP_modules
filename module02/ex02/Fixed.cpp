/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:42:14 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/11 19:03:21 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//**** Constructors - Destructors ****
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

Fixed::Fixed(const int value): _value(value << this->_fractionalBits) {};

Fixed::Fixed(const float value): _value(roundf(value * (1 << this->_fractionalBits))) {};

//**** Operators ****

Fixed &Fixed::operator=(const Fixed &src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed Fixed::operator+(const Fixed &src) const {
	return ( Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed &src) const {
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed &src) const {
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed &src) const {
	return (Fixed(this->toFloat() / src.toFloat()));
}

bool Fixed::operator>(const Fixed &src) const {
	return (this->_value > src.getRawBits());
}

bool Fixed::operator<(const Fixed &src) const {
	return (this->_value < src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src) const {
	return (this->_value >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src) const {
	return (this->_value <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src) const {
	return (this->_value == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src) const {
	return (this->_value != src.getRawBits());
}

Fixed &Fixed::operator++() {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}

Fixed &Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

//**** Getters - Setters ****

int Fixed::getRawBits( void ) const {
	return this->_value;
}

void Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

float Fixed::toFloat( void ) const {
	return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const {
	return this->_value >> this->_fractionalBits;
}

//**** Static functions ****

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
	return (a > b ? a : b);
}

//**** Non-member function ****/

std::ostream &operator<<(std::ostream &out, const Fixed &src) {
	out << src.toFloat();
	return out;
}
