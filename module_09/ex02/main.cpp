/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/04/16 16:05:46 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//============================== Parcing =======================================
static int validArgs(char **av) {
	for (int i = 1; av[i]; ++i)
		if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
			return 0;
	return 1;
}

static unsigned int	strToU(const std::string& str) {
	unsigned long	n;
	std::stringstream ss(str);

	ss >> n;

	if (ss.fail() || !ss.eof() || n > static_cast<unsigned long>(std::numeric_limits<unsigned int>::max()))
		throw std::runtime_error("Error: Not an unsigned int.");

	return static_cast<unsigned int>(n);
}

static bool	hasRepeats(std::vector<unsigned int>& vector) {
	std::vector<unsigned int>::iterator it1;
	std::vector<unsigned int>::iterator it2;

	for(it1 = vector.begin(); it1 != vector.end(); it1++) {
		for(it2 = it1 + 1; it2 != vector.end(); it2++) {
			if (*it1 == *it2)
				return true;
		}
	}
	return false;
}

// =============================== Main ========================================
int main(int ac, char **av) {
	try {
		if (ac == 1 || !validArgs(av))
			throw std::runtime_error("Error: Invalid arguments.");

		PmergeMe pmm;

		for (int i = 1; av[i]; ++i) {
			unsigned int n = strToU(av[i]);
			
			pmm.vec.push_back(n);
			pmm.lst.push_back(n);
		}
		if (hasRepeats(pmm.vec))
			throw std::runtime_error("Error: Repeated arguments.");

		pmm.sortVector(ac);
		pmm.sortList(ac);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
