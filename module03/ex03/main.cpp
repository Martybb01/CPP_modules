/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:51:06 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 12:21:58 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {

	std::string clapName = "CL4P-TP";
	std::string scavName = "SC4V-TP";
	std::string fragName = "FR4G-TP";
	std::string diamondName = "DI4M-TP";
	ClapTrap clap(clapName);
	ScavTrap scav(scavName);
	FragTrap frag(fragName);
	DiamondTrap diamond(diamondName);

	// print values for ClapTrap and ScavTrap
	std::cout << "ClapTrap " << clap.getName() << " has " << clap.getHitPoints() << " hit points, " << clap.getEnergyPoints() << " energy points and " << clap.getAttackDamage() << " attack damage." << std::endl;
	std::cout << "ScavTrap " << scav.getName() << " has " << scav.getHitPoints() << " hit points, " << scav.getEnergyPoints() << " energy points and " << scav.getAttackDamage() << " attack damage." << std::endl;
	std::cout << "FragTrap " << frag.getName() << " has " << frag.getHitPoints() << " hit points, " << frag.getEnergyPoints() << " energy points and " << frag.getAttackDamage() << " attack damage." << std::endl;
	std::cout << "DiamondTrap " << diamond.getName() << " has " << diamond.getHitPoints() << " hit points, " << diamond.getEnergyPoints() << " energy points and " << diamond.getAttackDamage() << " attack damage." << std::endl;

	frag.highFivesGuys();

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

	frag.attack("Skag");
	frag.takeDamage(150);
	std::cout << "FragTrap " << frag.getName() << " has " << frag.getHitPoints() << " hit points." << std::endl;
	frag.beRepaired(90);
	frag.highFivesGuys();

	diamond.attack("Skag");
	diamond.whoAmI();
	

	return 0;
}
