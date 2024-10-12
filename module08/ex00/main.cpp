/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:13:37 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/12 17:26:40 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	try {
		std::cout << easyFind(vec, 3) << std::endl;
		std::cout << easyFind(vec, 6) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);
	try {
		std::cout << easyFind(lst, 3) << std::endl;
		std::cout << easyFind(lst, 6) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
