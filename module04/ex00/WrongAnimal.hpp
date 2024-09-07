/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 18:34:01 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/07 19:47:44 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
	protected:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal(std::string const &type);
		WrongAnimal(const WrongAnimal &copy);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &copy);

		std::string const &getType() const;
		void makeSound() const;
};

#endif
