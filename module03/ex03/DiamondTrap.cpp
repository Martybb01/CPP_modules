/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:44:34 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/13 13:25:15 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name") {
	std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "hitPoints: " << FragTrap::_hitPoints << "Attack: " << this->_attackDamage << "energy: " << this->_energyPoints << std::endl;
	std::cout << "DiamondTrap " << name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src._name + "_clap_name"), ScavTrap(src), FragTrap(src) {
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " is destroyed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return *this;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

std::string DiamondTrap::getName(void) const {
	return this->_name;
}
