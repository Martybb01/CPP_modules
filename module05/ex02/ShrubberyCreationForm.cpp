/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:41:26 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/19 15:03:54 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
	if (this != &src) {
		AForm::operator=(src);
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src) {
	if (this != &src)
		AForm::operator=(src);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137) {
	setTarget(target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream fileOut(filename.c_str());
	if (fileOut.is_open()) {
		fileOut << TREE;
		fileOut.close();
	}
	else
		std::cerr << "Error: could not open file" << std::endl;
}
