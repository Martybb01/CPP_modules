/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:03:43 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/08 17:04:39 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure();
		Cure(Cure const &src);
		virtual ~Cure();
		Cure &operator=(Cure const &src);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
