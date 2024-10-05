/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:11:36 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/05 13:16:40 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>


template <typename T>
void swap(T &num, T &num2) {
	T tmp = num;
	num = num2;
	num2 = tmp;
}

template <typename T>
T min(T &num, T &num2) {
	return (num < num2 ? num : num2);
}

template <typename T>
T max(T &num, T &num2) {
	return (num > num2 ? num : num2);
}

#endif
