/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/18 14:58:46 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	Span sp2 = Span(15000);
	std::vector<int>	vector(15000);

	std::srand(std::time(0));
	std::generate(vector.begin(), vector.end(), std::rand);
	sp2.addRange(vector.begin(), vector.end());

	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

	std::cout << std::endl;

	try {
		Span sp3 = Span(2);

		sp3.addNumber(6);
		sp3.addNumber(3);
		sp3.addNumber(17);
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		Span sp4 = Span(1);

		sp4.addNumber(6);
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
