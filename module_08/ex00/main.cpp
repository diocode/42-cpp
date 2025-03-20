/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/20 11:28:07 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	int	arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int>	vector(arr, arr + sizeof(arr) / sizeof(int));

	try {
		if (easyfind(vector, 0) >= 0)
			std::cout << "Found in index: " << easyfind(vector, 0) << std::endl;
		if (easyfind(vector,6) >= 0)
			std::cout << "Found in index: " << easyfind(vector, 6) << std::endl;	
		if (easyfind(vector, 10) >= 0)
			std::cout << "Found in index: " << easyfind(vector, 10) << std::endl;
		if (easyfind(vector, 42) >= 0)
			std::cout << "Found in index: " << easyfind(vector, 42) << std::endl;
	}
	catch(std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
