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

#include "iter.hpp"
#include <iostream>

static void	addNbr(int& value) {
	value += 1;
}

static void	lessChar(char& value) {
	if (value == 65)
		value = 90;
	else
		value -= 1;
}

int	main() {
	char	stringArr[5] = {'A', 'B', 'C', 'D', 'E'};
	int 	intArr[3] = {1, 2, 3};

	std::cout << "Original Arr: " << stringArr[0] << stringArr[1] << stringArr[2] << stringArr[3] << stringArr[4] << std::endl;
	::iter(stringArr, 5, lessChar);
	std::cout << "Altered Arr: " << stringArr[0] << stringArr[1] << stringArr[2] << stringArr[3] << stringArr[4] << std::endl;

	std::cout << "\nOriginal Arr: " << intArr[0] << intArr[1] << intArr[2] << std::endl;
	::iter(intArr, 3, addNbr);
	std::cout << "Altered Arr: " << intArr[0] << intArr[1] << intArr[2] << std::endl;

	return 0;
}