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

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &value) {
	*this = value;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &value) {
	this->vec = value.vec;
	this->lst = value.lst;
	return *this;
}

PmergeMe::~PmergeMe() {}

template<typename Container>
void	printElements(const Container& con, const std::string& str) {
	std::cout << str << ": ";
	typename Container::const_iterator it;
	for(it = con.begin(); it != con.end(); it++) {
		std::cout << *it;
		typename Container::const_iterator tmp = it;
		++tmp;
		if (tmp != con.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::mergeInList() {

}

void	PmergeMe::mergeInVector() {

}

void	PmergeMe::sortVector(int ac) {
	printElements(vec, "Before");

	std::clock_t start = std::clock();
	mergeInVector();
	double time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;

	printElements(vec, "After");
	std::cout << "Time to process a range of " << ac - 1 << " elements "
		<< "with std::vector<unsigned int> : " << time << " µs" << std::endl;
}

void	PmergeMe::sortList(int ac) {
	std::clock_t start = std::clock();
	mergeInList();
	double time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;
	std::cout << "Time to process a range of " << ac - 1 << " elements "
			  << "with std::list<unsigned int> : " << time << " µs" << std::endl;
}