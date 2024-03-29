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

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	this->_value = 0;
}

Fixed::Fixed(const Fixed& value) {
	std::cout << "Copy constructor called\n";
	this->setRawBits(value.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& value) {
	std::cout << "Copy assignment operator called\n";
	this->_value = value.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}