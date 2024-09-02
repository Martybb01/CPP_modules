/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:57:44 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/02 19:12:36 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {};

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
