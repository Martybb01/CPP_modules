/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:20:21 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/08 12:22:22 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"


int main() {
	
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;
	delete i;

	const int arraySize = 10;
	const AAnimal *animals[arraySize];

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

	// const AAnimal* k = new AAnimal(); --> this won't work because AAnimal is an abstract class and can't be instantiated

	return 0;
}
