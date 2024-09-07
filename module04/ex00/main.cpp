/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:19:15 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 18:39:07 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal *alfa = new Animal();
	const Animal *bravo = new Dog();
	const Animal *charlie = new Cat();
	const WrongAnimal *delta = new WrongAnimal();
	const WrongAnimal *echo = new WrongCat();

	std::cout << bravo->getType() << " " << std::endl;
	std::cout << alfa->getType() << " " << std::endl;
	std::cout << charlie->getType() << " " << std::endl;
	std::cout << delta->getType() << " " << std::endl;
	std::cout << echo->getType() << " " << std::endl;
	charlie->makeSound();
	alfa->makeSound();
	bravo->makeSound();
	delta->makeSound();
	echo->makeSound();

	delete alfa;
	delete bravo;
	delete charlie;
	delete delta;
	delete echo;

	return 0;
}
