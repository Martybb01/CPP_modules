/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:48:09 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/01 19:48:10 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

void ft_printStart()
{
	std::cout << "Welcome in your phone book!" << std::endl;
	std::cout << "Please enter a command: ADD, SEARCH or EXIT" << std::endl;
}

int main()
{
	phoneBook phoneBook;
	Contact newContact;
	std::string input;

	ft_printStart();
	while (1)
	{
		std::cout << "> " << std::flush;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			std::cout << "Please enter the first name: ";
			std::getline(std::cin, input);
			newContact.setFirstName(input);

			std::cout << "Please enter the last name: ";
			std::getline(std::cin, input);
			newContact.setLastName(input);

			std::cout << "Please enter the nickname: ";
			std::getline(std::cin, input);
			newContact.setNickname(input);

			std::cout << "Please enter the phone number: ";
			std::getline(std::cin, input);
			newContact.setPhoneNumbr(input);

			std::cout << "Please enter the darkest secret: ";
			std::getline(std::cin, input);
			newContact.setDarkestSecret(input);

			if (!newContact.isEmpty())
				phoneBook.addContact(newContact);
			else
				std::cout << "Contact is empty, not added to the phone book." << std::endl;
		}
		else if (input == "SEARCH")
		{
			phoneBook.displayContacts();
			std::cout << "Please enter the index of the desired contact:" << std::endl;
			std::getline(std::cin, input);
			int index = atoi(input.c_str());
			phoneBook.displayContact(index);
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}
