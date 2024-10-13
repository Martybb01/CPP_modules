/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:30:13 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/13 13:22:31 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <cstdlib>
# include <ctime>

class Span {
 public:
  Span(unsigned int N);
  Span(Span const &src);
  ~Span();
  Span &operator=(Span const &src);

  void addNumber(int n);
  void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
  int shortestSpan();
  int longestSpan();

 private:
  Span();
  unsigned int max_size;
  std::vector<int> _numbers;
};

#endif
