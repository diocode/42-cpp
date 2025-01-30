/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/30 14:56:34 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	try {
		Bureaucrat joe("Joe", 55);
		ShrubberyCreationForm	form1("test_file");
		std::cout << form1 << std::endl;

		joe.executeForm(form1);
		joe.signForm(form1);
		joe.executeForm(form1);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "========================================\n";

	try {
		Bureaucrat joe("Joe", 55);
		Bureaucrat mark("Mark", 20);
		RobotomyRequestForm	form2("targetTest");
		std::cout << form2 << std::endl;

		joe.signForm(form2);
		joe.executeForm(form2);
		mark.executeForm(form2);
		mark.executeForm(form2);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "========================================\n";

	try {
		Bureaucrat mark("Mark", 2);
		Bureaucrat joe("Joe", 130);
		PresidentialPardonForm	form3("targetTest");
		std::cout << form3 << std::endl;

		mark.signForm(form3);
		mark.executeForm(form3);
		joe.executeForm(form3);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}