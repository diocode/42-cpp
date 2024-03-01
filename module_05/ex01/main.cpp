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
#include "Form.hpp"

int	main() {
	try
	{
		Bureaucrat joe("Joe", 55);
		Form	form1("contract_1", 75, 30);
		Form	form2("contract_2", 30, 20);

		joe.signForm(form1);
		joe.signForm(form2);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}
/*	try
	{

		std::cout << "Bureaucrats:\n" << mark << john;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << "Error: " << e.what();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << "Error: " << e.what();
	}

	try
	{
		Bureaucrat jeff;
		Bureaucrat mark("Mark", 5);
		Bureaucrat john("John", 80);

		std::cout << "Bureaucrats:\n" << jeff << mark << john;

		mark.decreaseGrade();
		john.increaseGrade();

		std::cout << "Bureaucrats:\n" << jeff << mark << john;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << "Error: " << e.what();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << "Error: " << e.what();
	}

	try
	{
		Bureaucrat mark("Mark", 1);
		mark.increaseGrade();
		std::cout << "Bureaucrat:\n" << mark;
		mark.increaseGrade();
		std::cout << "Bureaucrat:\n" << mark;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << "Error: " << e.what();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << "Error: " << e.what();
	}*/

	return 0;
}