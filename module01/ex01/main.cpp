/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:38:19 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/01 20:50:41 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name );

int main( void )
{
	int zombieHordeSize = 20;
	Zombie *zombies = zombieHorde(zombieHordeSize, "Zombie");

	for (int i = 0; i < zombieHordeSize; i++)
		zombies[i].announce();
	
	delete [] zombies;
	return 0;
}
