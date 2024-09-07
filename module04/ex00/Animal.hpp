/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:05:04 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 19:49:12 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string const &type);
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &copy);

		std::string const &getType() const;
		virtual void makeSound() const;
};

#endif
