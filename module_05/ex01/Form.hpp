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

#pragma once

# include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {
private:
	const std::string name;
	bool	isSigned;
	const int	signGrade;
	const int	execGrade;

public:
	Form();
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form& value);
	Form& operator=(const Form& value);
	~Form();

	std::string	getName() const;
	bool	getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void	beSigned(const Bureaucrat& bureaucrat);

	class	GradeTooHighException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};

	class	GradeTooLowException : public std::exception {
	public:
		virtual	const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& form);
