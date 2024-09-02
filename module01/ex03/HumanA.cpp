/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:53:58 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/02 19:12:44 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {};

HumanA::~HumanA() {};

void HumanA::attack() const 
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
