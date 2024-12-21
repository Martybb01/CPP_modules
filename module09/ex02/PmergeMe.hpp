/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:45:50 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/21 10:02:00 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <sys/time.h>
#include <stdexcept>

class PmergeMe {
	public:
		PmergeMe(int ac, char **av);
		void run(void);
	
	private:
		std::vector<int> inputVector;
		std::vector<int> vec;
		std::deque<int> deq;

		void parseInput(int ac, char **av);
		void printBefore(void);
		void printAfter(void);

		static bool isPositive(const std::string &str);
		static long getTimeMs(void);

		template <typename T>
		static void printSequence(const T &data) {
			size_t size = data.size();
			if (size <= 20) {
				for (size_t i = 0; i < size; i++)
				{
					std::cout << data[i];
					std::cout << (i + 1 < size ? " " : "\n");
				}
			} else {
				for (size_t i = 0; i < 10; i++)
					std::cout << data[i] << " ";
				std::cout << "... ";
				for (size_t i = size - 10; i < size; i++)
					std::cout << data[i] << (i + 1 < size ? " " : "\n");
			}
		}

		template <typename T>
		static void binaryInsert(T &seq, int value) {
			typename T::iterator low = std::lower_bound(seq.begin(), seq.end(), value);
			seq.insert(low, value);
		}

		template <typename T>
		static void fordJohnsonSort(T &data) {
			if (data.size() < 2)
				return;

			T pairsFirst, pairsSecond;
			typename T::iterator it = data.begin();
			while (it != data.end()) {
				int first = *it;
				++it;
				if (it != data.end()) {
					int second = *it;
					++it;
					if (first > second) {
						int temp = first;
						first = second;
						second = temp;
					}
					pairsFirst.push_back(first);
					pairsSecond.push_back(second);
				} else {
					pairsFirst.push_back(first);
				}
			}
			std::sort(pairsFirst.begin(), pairsFirst.end());

			for (typename T::iterator sit = pairsSecond.begin(); sit != pairsSecond.end(); ++sit) {
				binaryInsert(pairsFirst, *sit);
			}
			data = pairsFirst;
		}
};

#endif
