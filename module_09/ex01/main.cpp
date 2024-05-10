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

#include "RPN.hpp"

bool	isValid(const std::string& str) {
	if (str.find_first_not_of("0123456789+-/* ") == std::string::npos)
		return true;
	return false;
}

int main(int ac, char **av) {
	if (ac != 2 || !av[1][0] || !isValid(av[1])) {
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
