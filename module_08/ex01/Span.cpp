/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/18 13:01:20 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : capacity(0), container(0) {}

Span::Span(unsigned int capacity) : capacity(capacity), container(0) {}

Span::Span(const Span &value) : capacity(value.capacity) {
	std::copy(value.container.begin(), value.container.end(), container.begin());
}

Span &Span::operator=(const Span &value) {
	if (this == &value)
		return *this;
	std::copy(value.container.begin(), value.container.end(), container.begin());
	capacity = value.capacity;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int n) {
	if (container.size() == capacity)
		throw IsFullException();
	container.push_back(n);
}

void	Span::addRange(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd) {
	for (std::vector<int>::iterator it = itBegin; it != itEnd; ++it)
		this->addNumber(*it);
}
int	Span::shortestSpan() {
	if (container.size() < 2)
		throw NotEnoughElementsException();

	std::vector<int> tmp(container);
	std::sort(tmp.begin(), tmp.end());
	int res = *(tmp.begin() + 1) - *tmp.begin();

	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++) {
		if((*(it + 1) - *it) < res) {
			res = *(it + 1) - *it;
		}
	}
	return res;
}

int		Span::longestSpan() {
	if (container.size() < 2)
		throw NotEnoughElementsException();

	int res = 0;
	for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++) {
		if((*(it + 1) - *it ) > res) {
			res = *(it + 1) - *it;
		}
	}
	return res;
}

const char*	Span::IsFullException::what() const throw() {
	return "The container is full";
}

const char*	Span::NotEnoughElementsException::what() const throw() {
	return "There's not enough elements in the container to execute";
}
