/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:46:46 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/19 14:47:36 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		// Valid form and bureaucrat
		Bureaucrat bureaucrat("Marcel", 40);
		Form form("Tax Form", 50, 30);
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		std::cout << "Signing form" << std::endl;
		bureaucrat.signForm(form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		// Bureauacrat grade too low
		Bureaucrat bureaucrat("Marcel", 40);
		Form form2("Top secret", 20, 10);
		std::cout << form2 << std::endl;
		bureaucrat.signForm(form2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		// Form with invalid grades
		Form form3("Invalid", 0, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		// Form with invalid grades
		Form form5("Invalid", 151, 10);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		// Try to sign an already signed form
		Form form4("Simple Form",100, 100);
		Bureaucrat bureaucrat2("Alice", 1);
		bureaucrat2.signForm(form4);
		bureaucrat2.signForm(form4);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
