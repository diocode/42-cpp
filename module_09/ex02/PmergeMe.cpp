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

std::vector<unsigned int>	insertSortVector(std::vector<unsigned int>& left, std::vector<unsigned int>& right) {
	std::vector<unsigned int> res;

	while (!left.empty() && !right.empty()) {
		if (left.front() <= right.front()) {
			res.push_back(left.front());
			left.erase(left.begin());
		}
		else {
			res.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!left.empty()) {
		res.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty()) {
		res.push_back(right.front());
		right.erase(right.begin());
	}

	return res;
}

std::vector<unsigned int>	mergeInVector(std::vector<unsigned int>& vector) {
	if (vector.size() < 2)
		return vector;

	int	split = vector.size() / 2;
	std::vector<unsigned int> left(vector.begin(), vector.begin() + split);
	std::vector<unsigned int> right(vector.begin() + split, vector.end());

	left = mergeInVector(left);
	right = mergeInVector(right);
	return insertSortVector(left, right);
}

void	PmergeMe::sortVector(int ac) {
	printElements(vec, "Before");

	std::clock_t start = std::clock();
	std::vector<unsigned int> sorted = mergeInVector(vec);
	double time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;

	printElements(sorted, "After");
	std::cout << "Time to process a range of " << ac - 1 << " elements "
		<< "with std::vector<unsigned int> : " << time << " µs" << std::endl;
}


std::list<unsigned int>	insertSortList(std::list<unsigned int>& left, std::list<unsigned int>& right) {
	std::list<unsigned int> res;

	while (!left.empty() && !right.empty()) {
		if (left.front() <= right.front()) {
			res.push_back(left.front());
			left.erase(left.begin());
		}
		else {
			res.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!left.empty()) {
		res.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty()) {
		res.push_back(right.front());
		right.erase(right.begin());
	}

	return res;
}

std::list<unsigned int>	mergeInList(std::list<unsigned int>& list) {
	if (list.size() < 2)
		return list;

	int	split = list.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;

	for (int i = 0; i < split; i++) {
		left.push_back(list.front());
		list.pop_front();
	}
	right = list;

	left = mergeInList(left);
	right = mergeInList(right);
	return insertSortList(left, right);
}

void	PmergeMe::sortList(int ac) {
	std::clock_t start = std::clock();
	mergeInList(lst);
	double time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;
	std::cout << "Time to process a range of " << ac - 1 << " elements "
			  << "with std::list<unsigned int> : " << time << " µs" << std::endl;
}