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

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
private:
	int					_value;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed(const Fixed& value);
	Fixed(const int nbr);
	Fixed(const float nbr);
	Fixed& operator=(const Fixed& value);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed&	min(Fixed& v1, Fixed& v2);
	static Fixed&	min(const Fixed& v1, const Fixed& v2);
	static Fixed&	max(Fixed& v1, Fixed& v2);
	static Fixed&	max(const Fixed& v1, const Fixed& v2);

	bool	operator>(const Fixed& value) const;
	bool	operator<(const Fixed& value) const;
	bool	operator>=(const Fixed& value) const;
	bool	operator<=(const Fixed& value) const;
	bool	operator!=(const Fixed& value) const;
	bool	operator==(const Fixed& value) const;

	Fixed	operator+(const Fixed& value) const;
	Fixed	operator-(const Fixed& value) const;
	Fixed	operator*(const Fixed& value) const;
	Fixed	operator/(const Fixed& value) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);
};

std::ostream& operator<<(std::ostream& out, Fixed const& value);

#endif // FIXED_HPP