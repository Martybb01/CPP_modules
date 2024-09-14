/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:46:46 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/14 20:20:39 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	Bureaucrat minion("Bob", 50);
	Bureaucrat minion2("Carla", 2);
	std::cout << minion << std::endl;
	std::cout << minion2 << std::endl;
	
	minion.decrementGrade();
	std::cout << minion << std::endl;

	minion2.incrementGrade();
	std::cout << minion2 << std::endl;
	minion2.incrementGrade();

	Bureaucrat minion3("Jim", 150);
	std::cout << minion3 << std::endl;
	minion3.decrementGrade();

	Bureaucrat minion4("luca", 0);
	std::cout << minion4 << std::endl;

	return 0;
}
