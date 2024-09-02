/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:53:58 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/02 19:04:26 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {};

HumanA::~HumanA() {};

void HumanA::attack() const 
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
