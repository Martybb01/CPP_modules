/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:28:33 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/07 12:53:29 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
	private:
		T* _array;
		unsigned int _size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		~Array(void);
		Array &operator=(Array const &src);

		T &operator[](unsigned int index);
		T const &operator[](unsigned int index) const;

		unsigned int size(void) const;
};

#include "Array.tpp"


#endif
