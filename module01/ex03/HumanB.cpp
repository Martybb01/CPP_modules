/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:57:44 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/11 18:37:50 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {
	this->_weapon = NULL;
};

HumanB::~HumanB() {};

void HumanB::attack() const
{
	if (_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with his bare hands, so powerful!" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) 
{
	this->_weapon = &weapon;
}
