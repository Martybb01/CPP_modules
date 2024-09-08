/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:19:15 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/08 11:11:09 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	const int arraySize = 10;
	const Animal *animals[arraySize];

	for (int i = 0; i < arraySize; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < arraySize; i++)
		animals[i]->makeSound();
	
	for (int i = 0; i < arraySize; i++)
		delete animals[i];

	return 0;
}
