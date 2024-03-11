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
#include "Array.hpp"
#include "Array.tpp"

int main()
{
	Array<int> aArr(3);
	Array<int> bArr(5);

	std::cout << "====================================" << std::endl;
	for (unsigned int i = 0; i < aArr.size(); i ++) {
		std::cout << "aArr" << "[" << i << "] = " << aArr[i] << "\n";
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < bArr.size(); i ++) {
		std::cout << "bArr" << "[" << i << "] = " << bArr[i] << "\n";
	}

	bArr[0] = 1;
	bArr[1] = 2;
	bArr[2] = 3;
	bArr[3] = 4;
	bArr[4] = 5;
	aArr = bArr;

	std::cout << "====================================" << std::endl;
	for (unsigned int i = 0; i < aArr.size(); i ++) {
		std::cout << "aArr" << "[" << i << "] = " << aArr[i] << "\n";
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < bArr.size(); i ++) {
		std::cout << "bArr" << "[" << i << "] = " << bArr[i] << "\n";
	}

	Array<int> empty;

	std::cout << "====================================" << std::endl;
	for (unsigned int i = 0; i < empty.size(); i ++) {
		std::cout << "empty" << "[" << i << "] = " << empty[i] << "\n";
	}

	try { std::cout << aArr[aArr.size() + 1] << std::endl; }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	return (0);
}
