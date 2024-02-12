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
	*this = value;
}

Fixed::Fixed(const int nbr) {
	std::cout << "Int constructor called\n";
	this->_value = nbr * (1 << Fixed::_bits);
}

Fixed::Fixed(const float nbr) {
	std::cout << "Float constructor called\n";
	this->_value = roundf(nbr * (1 << Fixed::_bits));
}

Fixed& Fixed::operator=(const Fixed& value) {
	std::cout << "Copy assignment operator called\n";
	this->setRawBits(value.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	return ((float)this->_value / (float)(1 << Fixed::_bits));
}

int Fixed::toInt() const {
	return (this->_value >> Fixed::_bits);
}

std::ostream& operator<<(std::ostream& out, Fixed const& value) {
	out << value.toFloat();
	return (out);
}