/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/05 18:14:57 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int	main() {
	Data*	testData = new Data;
	uintptr_t	uData;

	std::cout << "Original data: " << testData << std::endl;
	uData = Serializer::serialize(testData);
	std::cout << "Serealized data: " << uData << std::endl;
	testData = Serializer::deserialize(uData);
	std::cout << "Deserialized data: " << testData << std::endl;
	delete testData;

	return (0);
}
