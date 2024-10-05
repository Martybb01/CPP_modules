/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:15:14 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/05 13:17:18 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	int num = 42;
	int num2 = 21;
	::swap(num, num2);
	std::cout << "num = " << num << ", num2 = " << num2 << std::endl;
	std::cout << "min = " << ::min(num, num2) << std::endl;
	std::cout << "max = " << ::max(num, num2) << std::endl;

	std::string str = "spiderman";
	std::string str2 = "superman";
	::swap(str, str2);
	std::cout << "str = " << str << ", str2 = " << str2 << std::endl;
	std::cout << "min = " << ::min(str, str2) << std::endl;
	std::cout << "max = " << ::max(str, str2) << std::endl;

	float f = 42.42f;
	float f2 = 21.21f;
	::swap(f, f2);
	std::cout << "f = " << f << ", f2 = " << f2 << std::endl;
	std::cout << "min = " << ::min(f, f2) << std::endl;
	std::cout << "max = " << ::max(f, f2) << std::endl;

	return (0);
}
