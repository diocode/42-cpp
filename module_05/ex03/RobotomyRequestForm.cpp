/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/30 15:11:49 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& value) : AForm(value.getName(), value.getSignGrade(), value.getExecGrade()), target(value.target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &value) {
	const_cast<std::string&>(target) = value.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > getExecGrade())
		throw GradeTooHighException();
	if (getIsSigned()) {
		std::cout << "Drill drill drill and more drilling\n";
		int flg = std::rand() % 2;
		if (flg)
			std::cout << target << " has been robotomized\n";
		else
			std::cout << "The robotomy for " << target << " failed\n";
	}
}
