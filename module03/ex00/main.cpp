/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:04:00 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/06 18:24:00 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) 
{
	ClapTrap defaultTrap;
	ClapTrap clap("CL4P-TP");
	ClapTrap clap2("CL4P-TP2");
	
	std::cout << "Default ClapTrap Name: " << defaultTrap.getName() << std::endl;

	clap.attack("Skag");
	clap.takeDamage(5);
	clap.beRepaired(3);

	for (int i = 0; i < 10; i++)
		clap.attack("Skag");

	clap2.takeDamage(15);
	clap2.attack("Skag");
	clap2.beRepaired(10);
	

	return 0;
}
