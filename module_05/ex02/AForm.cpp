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

#include "AForm.hpp"

AForm::AForm() : isSigned(false), signGrade(0), execGrade(0) {}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (signGrade > 150 || execGrade > 150)
		throw (AForm::GradeTooLowException());

	const_cast<std::string&>(name) = name;
	isSigned = false;
	const_cast<int&>(signGrade) = signGrade;
	const_cast<int&>(execGrade) =execGrade;
}

AForm::AForm(const AForm& value) : name(value.name), isSigned(value.isSigned), signGrade(value.signGrade), execGrade(value.execGrade) {}

AForm&	AForm::operator=(const AForm &value) {
	const_cast<std::string&>(name) = value.name;
	isSigned = value.isSigned;
	const_cast<int&>(signGrade) = value.signGrade;
	const_cast<int&>(execGrade) = value.execGrade;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return name;
}

bool	AForm::getIsSigned() const {
	return isSigned;
}

int	AForm::getSignGrade() const {
	return signGrade;
}

int AForm::getExecGrade() const {
	return execGrade;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "The grade is to high\n";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "The grade is to low\n";
}

std::ostream&	operator<<(std::ostream& out, const AForm& form) {
	out << "Name: " << form.getName() << std::endl;
	out << "Grade to sign: " << form.getSignGrade() << std::endl;
	out << "Grade to execute: " << form.getExecGrade() << std::endl;
	if (form.getIsSigned())
		out << "Signed: True" << std::endl;
	else
		out << "Signed: False" << std::endl;
	return out;
}
