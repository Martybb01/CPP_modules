/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:33:22 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/16 16:41:05 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(Intern const &src);
	virtual ~Intern();
	Intern &operator=(Intern const &src);

	AForm *makeForm(std::string const &name, std::string const &target);

private:
	AForm *createShrubberyCreationForm(std::string const &target);
	AForm *createRobotomyRequestForm(std::string const &target);
	AForm *createPresidentialPardonForm(std::string const &target);
};

#endif
