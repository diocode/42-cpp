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

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point {
private:
	Fixed	_x;
	Fixed	_y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &src);
	~Point();

	Point&	operator=(const Point &src);

	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const p);

#endif //POINT_HPP