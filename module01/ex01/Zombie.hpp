/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:26:46 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/01 20:34:22 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIEE_H
# define ZOMBIEE_H

# include <string>
# include <iostream>

class Zombie {
	private:
		std::string _name;


	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void announce() const;
		void setName(std::string name);
};

#endif
