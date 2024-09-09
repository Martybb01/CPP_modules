/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:48:19 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/09 16:34:15 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _contactIndex(0) {};

PhoneBook::~PhoneBook() {};

void PhoneBook::addContact(const Contact &contact)
{
	if (!contact.isEmpty())
	{
		_contacts[_contactIndex] = contact;
		_contactIndex = (_contactIndex + 1) % 8;
		if (_contactCount < 8)
			_contactCount++;
	}
}

void PhoneBook::displayContact(int index) const
{
	if (index >= 0 && index < _contactCount)
	{
		std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
		std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
		std::cout << "Phone number: " << _contacts[index].getPhoneNumbr() << std::endl;
		std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "Invalid index." << std::endl;
}


void PhoneBook::displayContacts() const
{
	std::string PhoneBook;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < _contactCount; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << truncate(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << truncate(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << truncate(_contacts[i].getNickname()) << "|" << std::endl;
	}
}

std::string PhoneBook::truncate(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

