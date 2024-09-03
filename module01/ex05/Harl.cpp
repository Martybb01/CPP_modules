/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:55:24 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/03 22:37:03 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve more bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*harlFunc)(void);

	harlFunc functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}

	std::cout << "Invalid level" << std::endl;
}
