/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:02:31 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/15 13:06:33 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &src);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
	PresidentialPardonForm(std::string const &target);

	virtual void execute(Bureaucrat const &executor) const;

private:
	std::string const _target;
};

#endif
