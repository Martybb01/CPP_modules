/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:44:20 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/07 17:53:53 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
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


	Array<int> c(a);

	for (unsigned int i = 0; i < c.size(); i++) {
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;

	c = b;

	for (unsigned int i = 0; i < c.size(); i++) {
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;

	// try to access an element out of range
	try {
		std::cout << c[10] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}


