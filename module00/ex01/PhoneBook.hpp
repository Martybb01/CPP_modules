/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:48:25 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/09 16:33:09 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {

private:
	Contact _contacts[8];
	int _contactCount;
	int _contactIndex;

public:
	PhoneBook();
	~PhoneBook();

	void addContact(const Contact &contact);
	void displayContact(int index) const;
	void displayContacts() const;

private:
	std::string truncate(std::string str) const;




};

#endif
