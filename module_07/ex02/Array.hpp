/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/12 14:22:34 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

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
	const T& operator[](unsigned int n) const;

	class OutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};
