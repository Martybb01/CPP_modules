/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:49:49 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/10 09:06:46 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie *firstZombie = newZombie("Lola");
	Zombie *secondZombie = newZombie("Jack");
	Zombie *thirdZombie = newZombie("Gus");

	randomChump("Martis");
	randomChump("Lores");
	randomChump("Fras");

	firstZombie->announce();
	secondZombie->announce();
	delete firstZombie;
	delete secondZombie;
	thirdZombie->announce();
	delete thirdZombie;
	return 0;
}
