/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:29:03 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/01 11:09:36 by marboccu         ###   ########.fr       */
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
		static void	convert(std::string const &literal);

	private:
		ScalarConverter();
		~ScalarConverter();
		void _printResult(char c, int i, std::string &f, std::string &d);
		bool _handleImpossible(const std::string &value);
		void _printImpossible();
		
		template<class T> 
		std::string convertToString(T value);

};


#endif
