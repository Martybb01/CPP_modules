/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:34:40 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/03 23:27:24 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cmath>
#include <string.h>
#include <vector>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void printSpecial(const std::string &c, const std::string &i, const std::string &f, const std::string &d) {
    std::cout << "Char: " << c << std::endl;
    std::cout << "Int: " << i << std::endl;
    std::cout << "Float: " << f << std::endl;
    std::cout << "Double: " << d << std::endl;
}

void printChar(char c) {
    std::cout << "Char: " << c << std::endl;
    std::cout << "Int: " << static_cast<int>(c) << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void printInt(int num) {
    if (num >= 32 && num <= 126) {
        std::cout << "Char: " << static_cast<char>(num) << std::endl;
    } else {
        std::cout << "Char: Non displayable\n";
    }

    std::cout << "Int: " << num << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
}

void printFloat(float f) {

    if (!std::isprint(static_cast<char>(f)) || std::fmod(f, 1) == 0.0f) {
        std::cout << "Char: impossible" << std::endl;
    } else {
        std::cout << "Char: " << static_cast<char>(f) << std::endl;
    }
    std::cout << "Int: " << static_cast<int>(f) << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void printDouble(double d) {
    if (!std::isprint(static_cast<char>(d)) || std::fmod(d, 1) != 0.0) {
        std::cout << "Char: impossible" << std::endl;
    } else {
        std::cout << "Char: " << static_cast<char>(d) << std::endl;
    }
    std::cout << "Int: " << static_cast<int>(d) << std::endl;
    std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

bool ScalarConverter::handleSpecialOnes(const std::string &input) {
    if (input == "nan" || input == "nanf") {
        printSpecial("impossible", "Impossible", "nanf", "nan");
        return true;
    }
    if (input == "-inff" || input == "+inff") {
        printSpecial("impossible", "Impossible", input, input.substr(0, 4));
        return true;
    }
    if (input == "-inf" || input == "+inf") {
        printSpecial("impossible", "Impossible", input + "f", input);
        return true;
    }
    return false;
}

bool ScalarConverter::isChar(const std::string &input) {
    return input.length() == 1 && !isdigit(input[0]);
}

bool ScalarConverter::isInt(const std::string &input) {
    std::stringstream ss(input);
    int i;
    return (ss >> i) && ss.eof();
}

bool ScalarConverter::isFloat(const std::string &input) {
    return input[input.length() - 1] == 'f' && isDisplayable(input.substr(0, input.length() - 1));
}

bool ScalarConverter::isDouble(const std::string &input) {
    return input.find('.') != std::string::npos && isDisplayable(input);
}

void ScalarConverter::intConverter(const std::string &input) {
    char *end;
    int value = std::strtol(input.c_str(), &end, 10);
    if (*end != '\0') {
        std::cerr << "Invalid integer input" << std::endl;
        return;
    }
    printInt(value);
}

void ScalarConverter::floatConverter(const std::string &input) {
    float value = strtof(input.c_str(), nullptr);
    printFloat(value);
}

void ScalarConverter::doubleConverter(const std::string &input) {
    double value = strtod(input.c_str(), nullptr);
    printDouble(value);
}

bool ScalarConverter::isDisplayable(const std::string &input) {
    if (input.empty()) {
        return false;
    }

    bool dotSeen = false;
    size_t len = input.length();

    for (size_t i = 0; i < len; ++i) {
        char ch = input[i];

        if (i == 0 && (ch == '+' || ch == '-'))
            continue;

        if (ch == '.') {
            if (dotSeen || i == 0 || i == len - 1 || !isdigit(input[i - 1]) || !isdigit(input[i + 1]))
                return false;
            dotSeen = true;
            continue;
        }

        if (ch == 'f' && i == len - 1)
            continue;

        if (!isdigit(ch))
            return false;
    }
    return true;
}

void ScalarConverter::convert(const std::string &input) {
    if (handleSpecialOnes(input))
        return;

    if (isChar(input))
        printChar(input[0]);
    else if (isInt(input))
        intConverter(input);
    else if (isFloat(input))
        floatConverter(input);
    else if (isDouble(input))
        doubleConverter(input);
    else
        std::cout << "lol impossible" << std::endl;
}
