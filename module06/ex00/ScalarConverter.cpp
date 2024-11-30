/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:34:40 by marboccu          #+#    #+#             */
/*   Updated: 2024/11/30 19:05:37 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <string>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string &value) {
	if (value.length() == 1 && !std::isdigit(value[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &value) {
	char *end;
	strtol(value.c_str(), &end, 10);
	if (*end == '\0')
		return true;
	return false;
}

bool ScalarConverter::isFloat(const std::string &value) {
	char *end;
	strtof(value.c_str(), &end);
	if (*end == 'f')
		end++;
	if (*end == '\0')
		return true;
	return false;
}

bool ScalarConverter::isDouble(const std::string &value) {
	char *end;
	strtod(value.c_str(), &end);
	if (*end == '\0')
		return true;
	return false;
}

void ScalarConverter::charConverter(const std::string &value)
{
	char c = value[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: " << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::intConverter(const std::string &value)
{
	int i = strtol(value.c_str(), NULL, 10);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	std::cout << "char: ";
	if (c >= 32 && c <= 126)
		std::cout << "'" << c << "'" << std::endl;
	else if ((c >= 0 && c <= 31) || c == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::floatConverter(const std::string &value)
{
	float f = strtof(value.c_str(), NULL);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	std::cout << "char: ";
	if (c >= 32 && c <= 126)
		std::cout << "'" << c << "'" << std::endl;
	else if ((c >= 0 && c <= 31) || c == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	 if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            std::cout << "impossible" << std::endl;
        else
            std::cout << "'" << i << "'" << std::endl;

	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::_handleImpossible(const std::string &value) {
	if (value == "nan" || value == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}

	if (value == "+inf" || value == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
		return true;
	}

	if (value == "+inff" || value == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << value << std::endl;
		std::cout << "double: " << value.substr(0,4) << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::convert(const std::string input)
{
	ScalarConverter sc;
	if (sc._handleImpossible(input))
		return;
	
	if (sc.isChar(input))
		charConverter(input);
	else if (sc.isInt(input))
		intConverter(input);
	// else if (sc.isFloat(input))
	// 	floatConverter(input);
	// else if (sc.isDouble(input))
	// 	doubleConverter(input);
	else
		std::cout << "impossible" << std::endl;

}

// void ScalarConverter::_printResult(char c, int i, std::string &f, std::string &d) {
// 	std::cout << "char: ";
// 	if (c >= 32 && c <= 126)
// 		std::cout << "'" << c << "'" << std::endl;
// 	else if ((c >= 0 && c <= 31) || c == 127)
// 		std::cout << "Non displayable" << std::endl;
// 	else
// 		std::cout << "impossible" << std::endl;

// 	std::cout << "int: ";
// 	if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max())
// 		std::cout << i << std::endl;
// 	else
// 		std::cout << "impossible" << std::endl;

// 	std::cout << "float: " << f << std::endl;
// 	std::cout << "double: " << d << std::endl;
// }


// template <typename T>
// std::string customToString(T value) {
//     std::stringstream ss;
//     ss << value;
//     return ss.str();
// }

// void ScalarConverter::convert(std::string const &literal) {
// 	ScalarConverter sc;

// 	if (sc._handleImpossible(literal))
// 		return;

// 	if (literal.length() == 1 && !std::isdigit(literal[0])) {
// 		if (std::isprint(literal[0]))
// 		{
// 			std::string floatStr = customToString(literal[0]) + 'f';
// 			std::string doubleStr = customToString(literal[0]) + ".0";
// 			sc._printResult(literal[0], static_cast<int>(literal[1]), floatStr, doubleStr);
// 		}
// 		else
// 			sc._printImpossible();
// 		return;
// 	}

// 	try {
// 		bool isNegative = false;
// 		size_t start = 0;
// 		if (literal[0] == '-' || literal[0] == '+') {
// 			isNegative = literal[0] == '-';
// 			start = 1;
// 		}

// 		// Parse integer part
// 		int intPart = 0;
// 		for (size_t i = start; i < literal.size() && std::isdigit(literal[i]); ++i) {
// 			intPart = intPart * 10 + (literal[i] - '0');
// 		}
// 		if (isNegative)
// 			intPart = -intPart;

// 		// Check for float/double (fractional part)
// 		float floatVal = static_cast<float>(intPart);
// 		double doubleVal = static_cast<double>(intPart);
// 		size_t dotPos = literal.find('.');
// 		if (dotPos != std::string::npos) {
// 			float fraction = 0.0f;
// 			double divisor = 1.0;
// 			for (size_t i = dotPos + 1; i < literal.size() && std::isdigit(literal[i]); ++i) {
// 				fraction = fraction * 10.0f + (literal[i] - '0');
// 				divisor *= 10.0;
// 			}
// 			floatVal += fraction / divisor;
// 			doubleVal += static_cast<double>(fraction) / divisor;
// 		}

// 		// Handle float suffix 'f'
// 		if (literal[literal.size() - 1] == 'f')
// 			floatVal = static_cast<float>(doubleVal);

// 		// Handle char conversion manually
// 		char charVal = (intPart >= std::numeric_limits<char>::min() && intPart <= std::numeric_limits<char>::max()) ? static_cast<char>(intPart) : '\0';

// 		std::stringstream floatStream;
// 		floatStream << std::fixed << std::setprecision(1) << floatVal << 'f';
// 		std::string floatStr = floatStream.str();

// 		std::stringstream doubleStream;
// 		doubleStream << std::fixed << std::setprecision(1) << doubleVal;
// 		std::string doubleStr = doubleStream.str();

// 		sc._printResult(charVal, intPart, floatStr, doubleStr);
// 	} catch (std::exception &e) {
// 		sc._printImpossible();
// 	}
// }
