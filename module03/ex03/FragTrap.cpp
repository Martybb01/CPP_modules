/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:56:20 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/13 13:29:59 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap") {
	std::cout << "FragTrap default constructor" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string &name): ClapTrap(name) {
	std::cout << "FragTrap " << name << " now appears" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) {
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " is going on vacation" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (this->_hitPoints == 0) 
		std::cout << "FragTrap " << this->_name << " needs a BIG high five to recover!" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " is asking for a high five!" << std::endl;
	return;
}
