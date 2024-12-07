/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:30:24 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/07 19:18:21 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : max_size(0) {}

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(Span const &src) {
  *this = src;
}

Span::~Span() {}

Span &Span::operator=(Span const &src) {
  if (this != &src) {
	this->max_size = src.max_size;
	this->_numbers = src._numbers;
  }
  return *this;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_numbers.size() + std::distance(begin, end) > this->max_size)
		throw std::out_of_range("Span is full");
	this->_numbers.insert(this->_numbers.end(), begin, end);
}

void Span::addNumber(int n) {
	if (this->_numbers.size() < this->max_size)
		this->_numbers.push_back(n);
	else
		throw std::out_of_range("Span is full");
}

int Span::shortestSpan() {
	if (this->_numbers.size() < 2)
		throw std::out_of_range("Not enough numbers");
	
	std::vector<int> tmp = this->_numbers;
	std::sort(tmp.begin(), tmp.end());

	std::vector<int> diffs(tmp.size() - 1);
    std::adjacent_difference(tmp.begin(), tmp.end(), diffs.begin());
    diffs.erase(diffs.begin());
	return *std::min_element(diffs.begin(), diffs.end());
}

int Span::longestSpan() {
	if (this->_numbers.size() < 2)
		throw std::out_of_range("Not enough numbers");

	int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());

	return max - min;
}

