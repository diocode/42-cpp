/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/27 17:18:17 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : isSigned(false), signGrade(150), execGrade(150) {}

Form::Form(std::string name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw (Form::GradeTooHighException());
	else if (signGrade > 150 || execGrade > 150)
		throw (Form::GradeTooLowException());

	const_cast<std::string&>(name) = name;
	isSigned = false;
	const_cast<int&>(signGrade) = signGrade;
	const_cast<int&>(execGrade) = execGrade;
}

Form::Form(const Form& value) : name(value.name), isSigned(value.isSigned), signGrade(value.signGrade), execGrade(value.execGrade) {}

Form&	Form::operator=(const Form &value) {
	const_cast<std::string&>(name) = value.name;
	isSigned = value.isSigned;
	const_cast<int&>(signGrade) = value.signGrade;
	const_cast<int&>(execGrade) = value.execGrade;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const {
	return name;
}

bool	Form::getIsSigned() const {
	return isSigned;
}

int	Form::getSignGrade() const {
	return signGrade;
}

int Form::getExecGrade() const {
	return execGrade;
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "The grade is to high\n";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "The grade is to low\n";
}

std::ostream&	operator<<(std::ostream& out, const Form& form) {
	out << "Name: " << form.getName() << std::endl;
	out << "Grade to sign: " << form.getSignGrade() << std::endl;
	out << "Grade to execute: " << form.getExecGrade() << std::endl;
	if (form.getIsSigned())
		out << "Signed: True" << std::endl;
	else
		out << "Signed: False" << std::endl;
	return out;
}
