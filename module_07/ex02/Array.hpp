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

#include <exception>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array {
	T*	elements;
	unsigned int	arrSize;

public:
	Array();
	Array(unsigned int	n);
	Array(const Array& value);
	Array&	operator=(const Array& value);
	~Array();

	unsigned int	size() const;
	T& operator[](unsigned int n);

	class OutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};