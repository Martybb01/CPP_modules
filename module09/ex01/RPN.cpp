/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:34:49 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/09 11:25:20 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &src) {
	*this = src;
}

RPN &RPN::operator=(RPN const &src) {
	if (this != &src) {
		_stack = src._stack;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::doOperation(char op) {
	if (_stack.size() < 2) {
		throw std::runtime_error("Error: Not enough values in stack");
	}
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	switch (op) {
		case '+':
			_stack.push(b + a);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '*':
			_stack.push(b * a);
			break;
		case '/':
			if (a == 0) {
				throw std::runtime_error("Error: Division by zero");
			}
			_stack.push(b / a);
			break;
	}
}

void RPN::processInput(const std::string &str) {
	std::istringstream iss(str);
	std::string token;

	while (iss >> token) {
		if (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
			doOperation(token[0]);
		} else if (isdigit(token[0]) && token.length() == 1) {
			_stack.push(std::stoi(token));
		} else {
			throw std::runtime_error("Error: Invalid token");
		}
	}

	if (_stack.size() != 1) {
		throw std::runtime_error("Error: Invalid expression");
	}
	std::cout << _stack.top() << std::endl;
	_stack.pop();
}
