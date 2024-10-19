/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:09:18 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/19 15:03:09 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(std::string const &name, int signGrade, int execGrade);
	AForm(AForm const &src);
	virtual ~AForm();
	AForm &operator=(AForm const &src);

	std::string const &getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	std::string const &getTarget() const;
	void setTarget(std::string const &target);

	void beSigned(Bureaucrat const &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const = 0;

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
	class FormNotSignedException : public std::exception {
	public:
		const char *what() const throw();
	};

private:
	std::string const _name;
	bool _signed;
	int const _signGrade;
	int const _execGrade;
	std::string _target;
};

std::ostream &operator<<(std::ostream &out, AForm const &src);

#endif
