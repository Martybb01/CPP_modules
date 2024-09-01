/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:48:02 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/01 19:48:03 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumbr;
		std::string _darkestSecret;

	public:
		void setFirstName(const std::string &firstName);
		void setLastName(const std::string &lastName);
		void setNickname(const std::string &nickname);
		void setPhoneNumbr(const std::string &phoneNumbr);
		void setDarkestSecret(const std::string &darkestSecret);
	
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumbr() const;
		std::string getDarkestSecret() const;

		bool isEmpty() const;

};

#endif
