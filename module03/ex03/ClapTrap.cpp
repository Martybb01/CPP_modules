/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:03:54 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 12:02:18 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << this->_name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " is destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	if (this != &src)
	{
		_name = src.getName();
		_hitPoints = src.getHitPoints();
		_energyPoints = src.getEnergyPoints();
		_attackDamage = src.getAttackDamage();
	}
	return *this;
}

std::string ClapTrap::getName(void) const {
	return this->_name;
}

unsigned int ClapTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}

unsigned int ClapTrap::getMaxHitPoints(void) const {
	return 10;
}

unsigned int ClapTrap::getMaxEnergyPoints(void) const {
	return 10;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " is already dead!" << std::endl;
		return;
	}
	if (amount > this->_hitPoints) {
		this->_hitPoints = 0;
		std::cout << this->_name << " is dead!" << std::endl;
	} else {
		this->_hitPoints -= amount;
		std::cout << this->_name << " takes " << amount << " damage!" << std::endl;
	}
}

void ClapTrap::attack(const std::string &target) {
	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has no energy and cannot attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " is dead and cannot be repaired!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << this->_name << " has no energy and cannot be repaired!" << std::endl;
		return;
	}
	if (this->_hitPoints + amount >= getMaxHitPoints())
		this->_hitPoints = getMaxHitPoints();
	else
		this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << this->_name << " is repaired and has now " << _hitPoints << " hit points!" << std::endl;
}
