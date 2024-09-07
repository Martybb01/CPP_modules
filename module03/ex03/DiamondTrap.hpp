/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:44:09 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 12:20:33 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(std::string &name);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &src);

		void whoAmI(void);
	
		unsigned int getMaxHitPoints(void) const;
		unsigned int getMaxEnergyPoints(void) const;
		using ScavTrap::attack;
	
};

#endif
