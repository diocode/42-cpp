/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/04/15 12:56:33 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other) {
	this->btcPrices = other.btcPrices;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void	BitcoinExchange::closestDate(std::string date, float value) {
	std::map<std::string, float>::const_iterator tmp = this->btcPrices.begin();
	for (std::map<std::string, float>::const_iterator it = this->btcPrices.begin(); it != this->btcPrices.end(); ++it) {
		if (it->first < date)
			tmp = it;
		if (it->first > tmp->first)
			break;
	}
	std::cout << date << " => " << value << " = " << value * tmp->second << std::endl;
}

void	BitcoinExchange::printInfo(std::string date, float value) {
	if (value < 0)
		std::cerr << "Error: not a positive number.\n";
	else if (value > 1000)
		std::cerr << "Error: too large a number.\n";
	else {
		for (std::map<std::string, float>::const_iterator it = this->btcPrices.begin(); it != this->btcPrices.end(); ++it) {
			if (it->first == date) {
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
				return;
			}
		}
		closestDate(date, value);
	}
}

void	BitcoinExchange::exchangeRates() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		std::cerr << "Error: could not open .csv file." << std::endl;
		return;
	}

	std::string	line;

	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t	i = line.find(',');
		this->btcPrices[line.substr(0, i)] = strToFloat(line.substr(i + 1));
	}
	file.close();
}

void	BitcoinExchange::exchange(const std::string &input) {
	this->exchangeRates();
	std::ifstream file(input.c_str());

	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		size_t i = line.find('|');
		struct tm date;
		if (i == std::string::npos || line[i + 1] != ' ' || strptime(line.substr(0, i - 1).c_str(), "%Y-%m-%d", &date) == NULL) {
			std::cerr << "Error: bad input => " << line.substr(0, i - 1) << std::endl;
			continue;
		}

		struct tm firstDate;
		strptime("2009-01-02", "%Y-%m-%d", &firstDate);

		time_t inputTime = mktime(&date);
		time_t firstTime = mktime(&firstDate);

		if (difftime(inputTime, firstTime) < 0) {
			std::cerr << "Error: date too early => " << line.substr(0, i - 1) << std::endl;
			continue;
		}
		
		std::istringstream	iss(line.substr(i + 2));
		
		float tmp;
		if (!(iss >> tmp))
			std::cerr << "Error: bad input => " << line.substr(i + 2) << std::endl;
		else
			this->printInfo(line.substr(0, i - 1), strToFloat(line.substr(i + 2)));
	}
}
