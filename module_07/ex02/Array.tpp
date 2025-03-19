/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/12 14:20:16 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(new T[0]), arrSize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), arrSize(n) {
	for (unsigned int i = 0; i < n; i++)
		elements[i] = 0;
}

template <typename T>
Array<T>::Array(const Array& value) : elements(new T[value.size()]), arrSize(value.size()) {
	for (unsigned int i = 0; i < arrSize; i++)
		elements[i] = value.elements[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& value) {
	if (this == &value)
		return *this;

	delete[] elements;

	arrSize = value.size();
	elements = new T[arrSize];
	for (unsigned int i = 0; i < arrSize; i++)
		elements[i] = value.elements[i];

	return *this;
}

template <typename T>
Array<T>::~Array() { delete[] elements; }

template <typename T>
unsigned int Array<T>::size() const {
	return arrSize;
}

template <typename T>
T& Array<T>::operator[](unsigned int n) {
	if (n >= size())
		throw (Array<T>::OutOfBoundsException());
	return elements[n];
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const {
	if (n >= size())
		throw (Array<T>::OutOfBoundsException());
	return elements[n];
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return "The index is out of bounds\n";
}
