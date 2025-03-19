/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/06 15:37:20 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
	} catch (std::exception& exception) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
	} catch (std::exception& exception) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
	} catch (std::exception& exception) {}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

Base * generate(void) {
	srand(time(0));
	char c = "ABC"[rand() % 3];
	switch (c) {
		case 'A':
			return new A;
		case 'B':
			return new B;
		case 'C':
			return new C;
		default:
			return NULL;
	}
}

int	main() {
	Base* test = generate();

	identify(test);
	identify(*test);
	delete test;

	return (0);
}
