/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:27:40 by marboccu          #+#    #+#             */
/*   Updated: 2024/12/16 19:32:41 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src) {
		this->_database = src._database;
	}
	return *this;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file");
	}
	std::string line;
	while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr;
        float rate;

        if (std::getline(iss, dateStr, ',') && (iss >> rate)) {
            time_t date = parseDate(dateStr);
            _database[date] = rate;
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;

	if (!std::getline(file, line)) {
        throw std::runtime_error("Error: input file is empty or invalid.");
    }
	
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        double value;

        if (std::getline(iss, dateStr, '|') && std::getline(iss, valueStr)) {
            dateStr = dateStr.erase(dateStr.find_last_not_of(" \t") + 1);
            valueStr = valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

            try {
                time_t date = parseDate(dateStr);
                std::istringstream valueStream(valueStr);

                if (!(valueStream >> value) || value < 0 || value > 1000)
                    throw std::runtime_error("Invalid value.");

                const_iterator it = _database.lower_bound(date);
                if (it == _database.end() || (it != _database.begin() && it->first > date))
                    --it;

                double rate = it->second;
                 std::cout << dateToString(date) << " => " << value << " = " << (value * rate) << std::endl;

            } catch (const std::exception &e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        } else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
    file.close();
}

time_t BitcoinExchange::parseDate(const std::string &date) const {
    struct tm tm = {};
    if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
        throw std::runtime_error("Invalid date format.");
    return mktime(&tm);
}

std::string BitcoinExchange::dateToString(time_t date) const {
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&date));
    return std::string(buffer);
}

const std::map<time_t, float> &BitcoinExchange::getDatabase() const {
	return _database;
}
