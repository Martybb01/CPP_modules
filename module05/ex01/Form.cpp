/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:51:40 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/19 14:41:49 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string const &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &src) : _name(src._name), _signed(src._signed), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()) {}

Form::~Form() {}

Form &Form::operator=(Form const &src) {
	if (this != &src) {
		this->_signed = src._signed;
	}
	return *this;
}

std::string const &Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (this->getSigned())
		throw FormAlreadySignedException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *Form::FormAlreadySignedException::what() const throw() {
	return "Form is already signed";
}

std::ostream &operator<<(std::ostream &out, Form const &src) {
	out << "Form " << src.getName() << " is " << (src.getSigned() ? "" : "not ") << "signed";
	out << " and requires grade " << src.getSignGrade() << " to sign and grade " << src.getExecGrade() << " to execute";
	return out;
}
