/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:44:34 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 12:19:27 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	this->_name = name;
	std::cout << "DiamondTrap " << name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) {
	*this = src;
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

unsigned int DiamondTrap::getMaxHitPoints(void) const {
	return FragTrap::getMaxHitPoints();
}

unsigned int DiamondTrap::getMaxEnergyPoints(void) const {
	return ScavTrap::getMaxEnergyPoints();
}
