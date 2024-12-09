/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:41:35 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/09 11:13:51 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    try {
        RPN calculator;
        calculator.processInput(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
