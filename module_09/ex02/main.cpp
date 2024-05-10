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

#include "PmergeMe.hpp"

int validArgs(char **av) {
	for (int i = 1; av[i]; ++i)
		if (std::string(av[i]).find_first_not_of("0123456789 ") != std::string::npos)
			return 0;
	return 1;
}

unsigned int	strToU(const std::string& str) {
	unsigned int	n;
	std::stringstream ss(str);

	ss >> n;
	return n;
}

int	hasRepeats(std::vector<unsigned int>& vector) {
	std::vector<unsigned int>::iterator it1;
	std::vector<unsigned int>::iterator it2;

	for(it1 = vector.begin(); it1 != vector.end(); it1++) {
		for(it2 = it1 + 1; it2 != vector.end(); it2++) {
			if (*it1 == *it2)
				return 1;
		}
	}
	return 0;
}

int main(int ac, char **av) {
	if (ac == 1 || !validArgs(av))
		return std::cerr << "Error: Invalid arguments.\n", 1;

	PmergeMe pmm;

	for (int i = 1; av[i]; ++i) {
		pmm.vec.push_back(strToU(av[i]));
		pmm.lst.push_back(strToU(av[i]));
	}
	if (hasRepeats(pmm.vec))
		return std::cerr << "Error: Invalid arguments.\n", 1;

	pmm.sortVector(ac);
	pmm.sortList(ac);
}
