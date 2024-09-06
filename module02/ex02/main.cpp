/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:42:05 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/06 16:59:09 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cassert>

int main( void )
{
	Fixed a(5);
    Fixed b(2);
    Fixed c(10.5f);

    std::cout << "--- Testing Arithmetic Operators ---\n";
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "c - a = " << (c - a) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "c / b = " << (c / b) << std::endl;

    std::cout << "\n--- Testing Comparison Operators ---\n";
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < c: " << (a < c) << std::endl;
    std::cout << "b >= b: " << (b >= b) << std::endl;
    std::cout << "c <= a: " << (c <= a) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;

    std::cout << "\n--- Testing Increment/Decrement Operators ---\n";
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a after increment: " << a << std::endl;
    std::cout << "++b: " << ++b << std::endl;
    std::cout << "c--: " << c-- << std::endl;
    std::cout << "c after decrement: " << c << std::endl;
    std::cout << "--a: " << --a << std::endl;

    std::cout << "\n--- Testing Static Min/Max Functions ---\n";
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, c): " << Fixed::max(a, c) << std::endl;

    const Fixed d(15);
    const Fixed e(7.5f);
    std::cout << "min(const d, const e): " << Fixed::min(d, e) << std::endl;
    std::cout << "max(const d, const e): " << Fixed::max(d, e) << std::endl;

    return 0;
}
