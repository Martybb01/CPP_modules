/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:29:03 by marboccu          #+#    #+#             */
/*   Updated: 2024/11/30 19:03:20 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>

class ScalarConverter {
	public:
		static void	convert(std::string const literal);

	private:
		ScalarConverter();
		~ScalarConverter();
		static bool _handleImpossible(const std::string &value);
		static bool isChar(const std::string &value);
		static bool isInt(const std::string &value);
		static bool isFloat(const std::string &value);
		static bool isDouble(const std::string &value);
		
		static void charConverter(const std::string &value);
		static void intConverter(const std::string &value);
		static void floatConverter(const std::string &value);
		// static void doubleConverter(const std::string &value);
		


};


#endif
