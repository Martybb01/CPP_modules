/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:42:37 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/16 16:50:12 by marboccu         ###   ########.fr       */
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

	std::cout << "--- Testing valid form creation ---\n";
	scf = minion.makeForm("shrubbery creation", "home");
	rrf = minion.makeForm("robotomy request", "Bender");
	ppf = minion.makeForm("presidential pardon", "Zaphod Beeblebrox");

	std::cout << "\n--- Testing invalid form creation ---\n";
	invalidForm = minion.makeForm("invalid form", "Nobody");

	std::cout << "\n--- Displaying created forms ---\n";
	std::cout << *scf << std::endl;
	std::cout << *rrf << std::endl;
	std::cout << *ppf << std::endl;

	std::cout << "\n--- Testing form execution and sign ---\n";
	boss.executeForm(*scf);
	clerk.signForm(*scf);
	boss.signForm(*scf);

	delete scf;
	delete rrf;
	delete ppf;

	if (invalidForm)
		delete invalidForm;

	return 0;
}
