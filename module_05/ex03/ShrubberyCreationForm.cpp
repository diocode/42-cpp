/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/02/24 13:48:48 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& value) : AForm(value.getName(), value.getSignGrade(), value.getExecGrade()), target(value.target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &value) {
	const_cast<std::string&>(target) = value.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > getExecGrade())
		throw GradeTooHighException();
	if (getIsSigned()) {
		std::string fileName = target + "_shrubbery";
		std::fstream fs;

		fs.open(fileName.c_str(), std::fstream::out | std::fstream::trunc);
		if (fs.is_open()) {
			fs << "       _-_\n"
				  "    /~~   ~~\\\n"
				  " /~~         ~~\\\n"
				  "{               }\n"
				  " \\  _-     -_  /\n"
				  "   ~  \\\\ //  ~\n"
				  "_- -   | | _- _\n"
				  "  _ -  | |   -_\n"
				  "      // \\\\\n";
			fs.close();
		}
	}
}
