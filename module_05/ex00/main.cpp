/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/21 16:28:33 by digoncal         ###   ########.fr       */
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

		std::cout << "\nBureaucrats:\n" << mark << john;
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

		std::cout << "\nBureaucrats:\n" << jeff << mark << john;

		mark.decreaseGrade();
		john.increaseGrade();

		std::cout << "\nBureaucrats:\n" << jeff << mark << john;
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
		std::cout << "\nBureaucrat:\n" << mark;
		mark.increaseGrade();
		std::cout << "\nBureaucrat:\n" << mark;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cerr << "Error: " << e.what();
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cerr << "Error: " << e.what();
	}

	return 0;
}