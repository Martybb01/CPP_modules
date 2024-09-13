/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:44:09 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/13 13:16:54 by marboccu         ###   ########.fr       */
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
		std::string getName(void) const;
	
		using ScavTrap::attack;
	
};

#endif
