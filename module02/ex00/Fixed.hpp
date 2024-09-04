/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:14:52 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/04 11:28:13 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>


class Fixed {
	private:
		int _value;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &src);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
