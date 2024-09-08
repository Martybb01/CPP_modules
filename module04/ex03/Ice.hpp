/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:05:01 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/08 17:05:19 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice();
		Ice(Ice const &src);
		virtual ~Ice();
		Ice &operator=(Ice const &src);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
