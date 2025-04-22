/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/04/22 13:17:32 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isValid(const std::string& str) {
	if (str.find_first_not_of("0123456789+-/* ") == std::string::npos)
		return true;
	return false;
}

bool	onlyWhiteSpaces(const std::string& str) {
	size_t i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return true;
	return false;
}

int main(int ac, char **av) {
	if (ac != 2 || !av[1][0] || !isValid(av[1]) || onlyWhiteSpaces(av[1])) {
		std::cerr << "Error\n";
		return 1;
	}

	RPN	calculator;

	try {
		std::cout << calculator.calc(av[1]) << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
