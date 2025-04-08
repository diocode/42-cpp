/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/04/08 15:09:05 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, float>	btcPrices;

	void	exchangeRates();
	void	printInfo(std::string date, float value);
	void	closestDate(std::string date, float value);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& value);
	BitcoinExchange&	operator=(const BitcoinExchange& value);
	~BitcoinExchange();

	void	exchange(const std::string &input);
};

float	strToFloat(std::string str);
