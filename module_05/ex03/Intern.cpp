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

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern&	Intern::operator=(const Intern&) {
	return *this;
}

Intern::~Intern() {}

static AForm* shrubberyCreationForm(const std::string& target) {
	return (new ShrubberyCreationForm(target));
}

static AForm* robotomyRequestForm(const std::string& target) {
	return (new RobotomyRequestForm(target));
}

static AForm* presidentialPardonForm(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	function	funcs[] = {&shrubberyCreationForm, &robotomyRequestForm, &presidentialPardonForm};
	std::string	forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			AForm*	form = (funcs[i])(target);
			std::cout << "Intern creates " << formName  << " form\n";
			return form;
		}
	}
	std::cout << "Intern couldn't find " << formName << " form\n";
	return NULL;
}
