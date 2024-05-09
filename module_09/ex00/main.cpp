/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: digoncal                                     +:+ +:+         +:+     */
/*   <digoncal@student.42porto.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Project:                                          #+#    #+#             */
/*   -> C++ Modules                                   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float	strToFloat(std::string str) {
	std::istringstream	iss(str);
	float value;

	if (!(iss >> value))
		return -1;
	return value;
}

int main(int ac, char **av) {

	if (ac != 2)
		return std::cerr << "Error: could not open file." << std::endl, 1;

	std::ifstream file(av[1]);
	if (!file.is_open())
		return std::cerr << "Error: could not open file." << std::endl, 1;
	file.close();

	BitcoinExchange	btc;
	btc.exchange(av[1]);
}
