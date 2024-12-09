/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:58:52 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/09 10:33:34 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

class BitcoinExchange {
	public:
		typedef std::map<time_t, float>::iterator iterator;
		typedef std::map<time_t, float>::const_iterator const_iterator;
	private:
		std::map<time_t, float> _database;
		time_t parseDate(const std::string &date) const;
		std::string dateToString(time_t date) const;
	
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void loadDatabase(const std::string &filename);
		void processInput(const std::string &filename) const;

		const std::map<time_t, float> &getDatabase() const;
};

#endif
