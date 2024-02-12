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
	this->_value = 0;
}

Fixed::Fixed(const Fixed& value) {
	*this = value;
}

Fixed::Fixed(const int nbr) {
	this->_value = nbr * (1 << Fixed::_bits);
}

Fixed::Fixed(const float nbr) {
	this->_value = roundf(nbr * (1 << Fixed::_bits));
}

Fixed& Fixed::operator=(const Fixed& value) {
	this->setRawBits(value.getRawBits());
	return *this;
}

Fixed::~Fixed() {
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

/*------------------------ comparison ops ---------------------------*/

bool	Fixed::operator>(const Fixed &value) const {
	return this->getRawBits() > value.getRawBits();
}

bool	Fixed::operator<(const Fixed &value) const {
	return this->getRawBits() < value.getRawBits();
}

bool	Fixed::operator>=(const Fixed &value) const {
	return this->getRawBits() >= value.getRawBits();
}

bool	Fixed::operator<=(const Fixed &value) const {
	return this->getRawBits() <= value.getRawBits();
}

bool	Fixed::operator!=(const Fixed &value) const {
	return this->getRawBits() != value.getRawBits();
}

/*------------------------ arithmetic ops ---------------------------*/

Fixed	Fixed::operator+(const Fixed& value) const {
	return Fixed(this->toFloat() + value.toFloat());
}

Fixed	Fixed::operator-(const Fixed& value) const {
	return Fixed(this->toFloat() - value.toFloat());
}

Fixed	Fixed::operator*(const Fixed& value) const {
	return Fixed(this->toFloat() * value.toFloat());
}

Fixed	Fixed::operator/(const Fixed& value) const {
	return Fixed(this->toFloat() / value.toFloat());
}

/*-------------------- Increment/Decrement ops -----------------------*/

Fixed&   Fixed::operator++(void) {
	++this->_value;
	return *this;
}

Fixed   Fixed::operator++(int) {
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed&   Fixed::operator--(void) {
	--this->_value;
	return *this;
}

Fixed   Fixed::operator--(int) {
	Fixed tmp = *this;
	--(*this);
	return tmp;
}

/*-------------------------- Min & Max -----------------------------*/

Fixed&	Fixed::min(Fixed& v1, Fixed& v2) {
	return (v1 > v2) ? v2 : v1;
}

Fixed&	Fixed::min(const Fixed& v1, const Fixed& v2) {
	return (Fixed&)((v1 > v2) ? v2 : v1);
}

Fixed&	Fixed::max(Fixed& v1, Fixed& v2) {
	return (v1 > v2) ? v1 : v2;
}

Fixed&	Fixed::max(const Fixed& v1, const Fixed& v2) {
	return (Fixed&)((v1 > v2) ? v1 : v2);
}
