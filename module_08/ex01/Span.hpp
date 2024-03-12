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

#pragma once

#include <vector>
#include <exception>
#include <algorithm>

class Span {
	unsigned int 		capacity;
	std::vector<int>	container;

public:
	Span();
	Span(unsigned int capacity);
	Span(const Span& value);
	Span&	operator=(const Span& value);
	~Span();

	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
	void	addRange(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd);

	class IsFullException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class NotEnoughElementsException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

};
