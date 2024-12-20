/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:45:43 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/20 11:57:42 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) {
	parseInput(ac, av);
	vec = inputVector;
	deq = std::deque<int>(inputVector.begin(), inputVector.end());
}

void PmergeMe::run(void) {
	printBefore();
	long start = getTimeMs();
	fordJohnsonSort(vec);
	long end = getTimeMs();

	long startdeq = getTimeMs();
	fordJohnsonSort(deq);
	long enddeq = getTimeMs();
	printAfter();

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << (end - start) << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << (enddeq - startdeq) << " us" << std::endl;
}

void PmergeMe::parseInput(int ac, char **av) {
    if (ac < 2)
        throw std::runtime_error("No arguments provided.");

    for (int i = 1; i < ac; ++i) {
        std::string arg = av[i];
        if (!isPositive(arg))
            throw std::runtime_error("Invalid argument.");
        int val = std::atoi(arg.c_str());
        inputVector.push_back(val);
    }
}

void PmergeMe::printBefore() {
    std::cout << "Before: ";
    printSequence(this->inputVector);
	std::cout << std::endl;
}

void PmergeMe::printAfter() {
    std::cout << "After: ";
    printSequence(this->vec);
	std::cout << std::endl;
}


bool PmergeMe::isPositive(const std::string &str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) 
            return false;
    }
    if (str.empty()) return false;
    long val = std::atol(str.c_str());
    if (val <= 0 || val > std::numeric_limits<int>::max()) return false;
    return true;
}

long PmergeMe::getTimeMs() {	
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}
