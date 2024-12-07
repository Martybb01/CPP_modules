/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:44:20 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/07 12:57:24 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

class Custom {
public:
    int value;
    Custom(int v = 0) : value(v) {}
};

std::ostream &operator<<(std::ostream &out, const Custom &c) {
    out << c.value;
    return out;
}

int main(void)
{
	// Test 1: Array with integers
    std::cout << "Test 1: Array of integers\n";
    Array<int> a(5);
    Array<int> b(10);

    for (unsigned int i = 0; i < a.size(); i++) {
        a[i] = i;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    for (unsigned int i = 0; i < b.size(); i++) {
        b[i] = i;
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

	// Test 2: Copy constructor
    std::cout << "\nTest 2: Copy constructor\n";
    Array<int> c(a);
    for (unsigned int i = 0; i < c.size(); i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

	// Test 3: Assignment operator
    std::cout << "\nTest 3: Assignment operator\n";
    c = b;
    for (unsigned int i = 0; i < c.size(); i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

	// Test 4: Access out of range
    std::cout << "\nTest 4: Access out of range\n";
    try {
        std::cout << c[10] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << c[-1] << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

	// Test 5: Empty array
    std::cout << "\nTest 5: Empty array\n";
    Array<int> emptyArray;
    std::cout << "Size of empty array: " << emptyArray.size() << std::endl;
    try {
        emptyArray[0] = 10;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

	// Test 6: Array with complex types
    std::cout << "\nTest 6: Array with complex types\n";
    Array<Custom> customArray(3);
    for (unsigned int i = 0; i < customArray.size(); i++) {
        customArray[i] = Custom(i * 10);
    }

    for (unsigned int i = 0; i < customArray.size(); i++) {
        std::cout << customArray[i] << " ";
    }
    std::cout << std::endl;

	// Test 7: Const array access
    std::cout << "\nTest 7: Const array access\n";
    const Array<int> constArray(a);
    for (unsigned int i = 0; i < constArray.size(); i++) {
        std::cout << constArray[i] << " ";
    }
    std::cout << std::endl;
    //constArray[0] = 100; // Compilation error
}
