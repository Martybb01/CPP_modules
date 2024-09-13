/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:38:48 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/13 13:29:50 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
	std::cout << "ScavTrap default constructor" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " enters the wastelands" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) {
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " abandon the wastelands" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return *this;
}

void ScavTrap::guardGate() {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	else
		std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " has no energy and cannot attack!" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " is so powerful and attack " << target << ", for a blasting " << this->_attackDamage << " damage pointsss!" << std::endl;
	
}
