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

int	main() {
	try
	{
		Bureaucrat mark("Mark", 50);
		Bureaucrat john("John", 200);
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << "Error: " << e.what();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << "Error: " << e.what();
	}

	try
	{
		Bureaucrat mark("Mark", 70);
		Bureaucrat john("John", 10);

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
	}

	return 0;
}