/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:49:06 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/15 11:19:00 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form();
	Form(std::string const &name, const int signGrade, const int execGrade);
	Form(Form const &src);
	~Form();
	Form &operator=(Form const &src);

	std::string const &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
	class FormAlreadySignedException : public std::exception {
	public:
		const char *what() const throw();
	};

private:
	std::string const _name;
	bool _signed;
	int const _signGrade;
	int const _execGrade;
};

std::ostream &operator<<(std::ostream &out, Form const &src);

#endif
