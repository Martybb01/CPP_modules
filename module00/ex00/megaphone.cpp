/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:47:44 by marboccu          #+#    #+#             */
/*   Updated: 2024/09/01 19:47:46 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char toUpper(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 32;
	return c;
}

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl;
	
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j]; j++)
			std::cout << toUpper(av[i][j]);
		std::cout << " ";
	}
	return 0;
}
