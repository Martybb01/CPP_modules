/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:28:11 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/07 12:28:56 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	int lenInt = sizeof(intArray) / sizeof(int);

	std::cout << "intArray:" << std::endl;
	::iter(intArray, lenInt, ::print<int>);
	std::cout << std::endl;
	::iter(intArray, lenInt, ::addOne<int>);
	::iter(intArray, lenInt, ::print<int>);
	std::cout << std::endl;
	::iter(intArray, lenInt, ::minusOne<int>);
	::iter(intArray, lenInt, ::print<int>);

	/* -------------------------------------------------- */

	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	int lenFloat = sizeof(floatArray) / sizeof(float);

	std::cout << std::endl << "floatArray:" << std::endl;
	::iter(floatArray, lenFloat, ::print<float>);
	std::cout << std::endl;
	::iter(floatArray, lenFloat, ::addOne<float>);
	::iter(floatArray, lenFloat, ::print<float>);
	std::cout << std::endl;
	::iter(floatArray, lenFloat, ::minusOne<float>);
	::iter(floatArray, lenFloat, ::print<float>);

	/* -------------------------------------------------- */

	std::string stringArray[] = {"one", "two", "three", "four", "five"};
	int lenString = sizeof(stringArray) / sizeof(std::string);

	std::cout << std::endl << "stringArray:" << std::endl;
	::iter(stringArray, lenString, ::print<std::string>);

	/* -------------------------------------------------- */
	
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	int lenChar = sizeof(charArray) / sizeof(char);

	std::cout << std::endl << "charArray:" << std::endl;
	::iter(charArray, lenChar, ::print<char>);
	std::cout << std::endl;
	::iter(charArray, lenChar, ::addOne<char>);
	::iter(charArray, lenChar, ::print<char>);
	std::cout << std::endl;
	::iter(charArray, lenChar, ::minusOne<char>);
	::iter(charArray, lenChar, ::print<char>);

	return 0;
}
