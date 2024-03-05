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

Bureaucrat::Bureaucrat() {}

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

void	Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what();
	}
}

void	Bureaucrat::executeForm(AForm const& form)
{
	if (!form.getIsSigned())
		std::cout << getName() << " couldn't execute " << form.getName() << " | Error: Form not signed\n";
	else {
		try {
			form.execute(*this);
			std::cout << getName() << " executed " << form.getName() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << getName() << " couldn't execute " << form.getName() << " | Error: " << e.what();
		}
	}
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
