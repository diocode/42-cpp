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
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
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