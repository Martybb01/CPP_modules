/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:37:08 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/02 18:43:58 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {};

Weapon::~Weapon() {};

const std::string& Weapon::getType() {
	return _type;
}

void Weapon::setType(std::string type) {
	_type = type;
}

