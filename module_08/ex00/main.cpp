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

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int>	vector(arr, arr + sizeof(arr) / sizeof(int));

	if (easyfind(vector, 6) >= 0)
		std::cout << "Found in index: " << easyfind(vector, 6) << std::endl;
	else
		std::cout << "Not found.\n";

	if (easyfind(vector, 42) >= 0)
		std::cout << "Found in index: " << easyfind(vector, 42) << std::endl;
	else
		std::cout << "Not found.\n";
	return (0);
}
