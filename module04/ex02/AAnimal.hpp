/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:54:47 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/08 12:02:47 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &copy);

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif
