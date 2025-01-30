/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/01/21 16:34:30 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("undefined"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade > minGrade)
		throw GradeTooLowException();
	else if (grade < maxGrade)
		throw GradeTooHighException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& value) : _name(value._name), _grade(value._grade) {
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &value) {
	const_cast<std::string&>(_name) = value._name;
	_grade = value._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

std::string const&	Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::increaseGrade() {
	if (_grade > minGrade)
		throw GradeTooLowException();
	else if (_grade < maxGrade)
		throw GradeTooHighException();
	else
		_grade -= 1;
}

void	Bureaucrat::decreaseGrade() {
	if (_grade > minGrade)
		throw GradeTooLowException();
	else if (_grade < maxGrade)
		throw GradeTooHighException();
	else
		_grade += 1;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	return "The grade is to high\n";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	return "The grade is to low\n";
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& value) {
	out << value.getName() << ", bureaucrat grade " << value.getGrade() << std::endl;
	return out;
}
