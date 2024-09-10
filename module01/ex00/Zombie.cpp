/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:57:42 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/10 09:05:37 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// **** Constructor and Distructor ****

Zombie::Zombie( std::string name ) : _name(name) 
{
	std::cout << "Zombie " << this->_name << " is born" << std::endl;
	return;
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->_name << " is dead" << std::endl;
	return;
}

// **** Member functions ****

void Zombie::announce() const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
