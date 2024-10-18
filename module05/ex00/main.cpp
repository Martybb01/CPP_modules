/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:46:46 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/18 16:52:15 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	try {
		Bureaucrat minion("Bob", 50);
		Bureaucrat minion2("Carla", 2);
		std::cout << minion << std::endl;
		std::cout << minion2 << std::endl;
		
		minion.decrementGrade();
		std::cout << minion << std::endl;

		minion2.incrementGrade();
		std::cout << minion2 << std::endl;
		minion2.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat minion3("Jim", 150);
		std::cout << minion3 << std::endl;
		minion3.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat minion4("luca", 0);
		std::cout << minion4 << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
