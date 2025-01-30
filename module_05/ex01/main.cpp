/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/27 17:22:30 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	try {
		Bureaucrat joe("Joe", 55);
		Form	form1("contract_1", 75, 30);

		joe.signForm(form1);
		std::cout << form1;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "==========================" << std::endl;

	try {
		Bureaucrat joe("Joe", 55);
		Form	form2("contract_2", 30, 20);

		joe.signForm(form2);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "==========================" << std::endl;

	try {
		Bureaucrat joe("Joe", 55);
		Form	form3("contract_3", 200, 20);

		joe.signForm(form3);
		std::cout << form3;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}

	return 0;
}