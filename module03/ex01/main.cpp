/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:51:06 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 10:22:12 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {

	std::string clapName = "CL4P-TP";
	std::string scavName = "SC4V-TP";
	ClapTrap clap(clapName);
	ScavTrap scav(scavName);

	// print values for ClapTrap and ScavTrap
	std::cout << "ClapTrap " << clap.getName() << " has " << clap.getHitPoints() << " hit points, " << clap.getEnergyPoints() << " energy points and " << clap.getAttackDamage() << " attack damage." << std::endl;
	std::cout << "ScavTrap " << scav.getName() << " has " << scav.getHitPoints() << " hit points, " << scav.getEnergyPoints() << " energy points and " << scav.getAttackDamage() << " attack damage." << std::endl;

	clap.attack("Skag");
	clap.takeDamage(5);
	clap.beRepaired(3);

	for (int i = 0; i < 10; i++)
		clap.attack("Skag");

	scav.attack("Skag");
	scav.takeDamage(15);
	std::cout << "ScavTrap " << scav.getName() << " has " << scav.getHitPoints() << " hit points." << std::endl;
	scav.beRepaired(150);

	for (int i = 0; i < 10; i++)
		scav.attack("Skag");
	
	scav.guardGate();
	

	return 0;
}
