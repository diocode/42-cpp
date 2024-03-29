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

class	Fixed
{
private:
	int					_value;
	static const int	_bits = 8;

public:
	Fixed();
	Fixed(const Fixed& value);
	Fixed& operator=(const Fixed& value);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif // FIXED_HPP