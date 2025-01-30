/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/30 15:24:13 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main() {
	try {
		Bureaucrat joe("Joe", 30);

		Intern someRandomIntern;
		AForm* tform = someRandomIntern.makeForm("robotomy request", "Bender");

		joe.signForm(*tform);
		joe.executeForm(*tform);
		delete tform;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "========================================\n";

	try {
		Bureaucrat joe("Joe", 30);

		Intern someIntern;
		AForm* form = someIntern.makeForm("what_is_this", "Bender");

		if (form)
		{
			joe.signForm(*form);
			joe.executeForm(*form);
		}
		delete form;
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}