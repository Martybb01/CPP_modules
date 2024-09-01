/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:47:57 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/01 19:47:58 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void Contact::setFirstName(const std::string &firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
	this->_nickname = nickname;
}

void Contact::setPhoneNumbr(const std::string &phoneNumbr)
{
	this->_phoneNumbr = phoneNumbr;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return _firstName;
}

std::string Contact::getLastName() const
{
	return _lastName;
}

std::string Contact::getNickname() const
{
	return _nickname;
}

std::string Contact::getPhoneNumbr() const
{
	return _phoneNumbr;
}

std::string Contact::getDarkestSecret() const
{
	return _darkestSecret;
}

bool Contact::isEmpty() const
{
	if (_firstName.empty() && _lastName.empty() && _nickname.empty() && _phoneNumbr.empty() && _darkestSecret.empty())
		return true;
	return false;
}
