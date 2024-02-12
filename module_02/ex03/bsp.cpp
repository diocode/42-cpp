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

#include "Point.hpp"


static Fixed   abs(Fixed x) {
	if (x < 0)
		return x * -1;
	return x;
}

static Fixed   getArea( Point const a, Point const b, Point const c ) {
	return (((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
	Fixed	triangle = abs(getArea(a, b, c));
	Fixed	pab = abs(getArea(p, a, b));
	Fixed	pbc = abs(getArea(p, b, c));
	Fixed	pac = abs(getArea(p, a, c));

	if (triangle == pab + pbc + pac)
		return true;
	return false;
}
