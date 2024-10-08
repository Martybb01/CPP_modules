/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:47:34 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/10 09:13:46 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie {
	private:
		std::string _name;


	public:
		Zombie( std::string name );
		~Zombie( void );

		void announce() const;
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );

#endif
