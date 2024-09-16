/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:34:47 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/16 16:41:49 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &src) {
	*this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &src) {
	if (this != &src) {
	}
	return *this;
}

AForm *Intern::createShrubberyCreationForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {

	typedef AForm *(Intern::*form)(std::string const &target);

	form forms[3] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*forms[i])(target);
		}
	}

	std::cout << "Intern cannot create " << name << std::endl;
	return nullptr;
}

