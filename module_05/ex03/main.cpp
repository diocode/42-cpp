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

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main() {
	try {
		Bureaucrat joe("Joe", 30);

		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		joe.signForm(*rrf);
		joe.executeForm(*rrf);
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
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}