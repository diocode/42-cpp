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

int	main( void ) {
	/*Valid test*/
	if (bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15) ))
		std::cout << "1:The point is inside the triangle\n";
	else
		std::cout << "1:The point is NOT inside the triangle\n";

	/*Invalid test*/
	if (bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15) ))
		std::cout << "2:The point is inside the triangle\n";
	else
		std::cout << "2:The point is NOT inside the triangle\n";
	return 0;
}