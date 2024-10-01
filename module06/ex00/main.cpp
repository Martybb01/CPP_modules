/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:47:35 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/17 11:47:41 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./convert literal" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
