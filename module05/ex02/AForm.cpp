/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:16:36 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/15 20:32:49 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(std::string const &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	try {
		if (signGrade < 1 || execGrade < 1)
			throw GradeTooHighException();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		if (signGrade > 150 || execGrade > 150)
			throw GradeTooLowException();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()) {}

AForm::~AForm() {}

AForm &AForm::operator=(AForm const &src) {
	if (this != &src) {
		this->_signed = src._signed;
		this->_target = src._target;
	}
	return *this;
}

std::string const &AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

std::string const &AForm::getTarget() const {
	return _target;
}

void AForm::setTarget(std::string const &target) {
	_target = target;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (this->getSigned())
		throw FormAlreadySignedException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (this->getSigned())
		throw FormAlreadySignedException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::FormAlreadySignedException::what() const throw() {
	return "Form is already signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &src) {
	out << "Form " << src.getName() << " is " << (src.getSigned() ? "" : "not ") << "signed";
	out << " and requires grade " << src.getSignGrade() << " to sign and grade " << src.getExecGrade() << " to execute";
	return out;
}
