/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:23:31 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/07 12:28:51 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <functional>

template <typename T, typename Len, typename Func>
void iter(T *array, Len length, Func f) {
	for (Len i = 0; i < length; i++) {
		f(array[i]);
	}
}

// func templates to test iter
template <typename T>
void print(T &x) {
	std::cout << x << " ";
}

template <typename T>
void addOne(T &x) {
	x++;
}

template <typename T>
void minusOne(T &x) {
	x--;
}

#endif
