/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:20:40 by marboccu          #+#    #+#             */
/*   Updated: 2025/01/07 21:30:57 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>


class RPN {
	private:
		std::stack<int> _stack;

		void doOperation(char op);
	
	public:
		RPN();
		RPN(RPN const &src);
		RPN &operator=(RPN const &src);
		~RPN();

		void processInput(const std::string &str);
};

#endif
