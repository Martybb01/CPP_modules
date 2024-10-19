/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:42:37 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/19 15:19:51 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {

	Intern minion;
	AForm *scf;
	AForm *rrf;
	AForm *ppf;
	AForm *invalidForm;
	Bureaucrat boss("Boss", 1);
	Bureaucrat clerk("Clerk", 150);

	try {
		std::cout << "--- Testing valid form creation ---\n";
		scf = minion.makeForm("shrubbery creation", "home");
		rrf = minion.makeForm("robotomy request", "Bender");
		ppf = minion.makeForm("presidential pardon", "Zaphod Beeblebrox");
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- Testing invalid form creation ---\n";
		invalidForm = minion.makeForm("invalid form", "Nobody");
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- Testing form execution and sign ---\n";
		boss.signForm(*scf);
		boss.executeForm(*scf);
		clerk.signForm(*scf);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Displaying created forms ---\n";
	std::cout << *scf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *ppf << std::endl;

	delete scf;
	delete rrf;
	delete ppf;

	if (invalidForm)
		delete invalidForm;

	return 0;
}
