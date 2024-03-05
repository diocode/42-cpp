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

class	AForm {
private:
	const std::string name;
	bool	isSigned;
	const int	signGrade;
	const int	execGrade;

public:
	AForm();
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm& value);
	AForm& operator=(const AForm& value);
	virtual ~AForm();

	std::string	getName() const;
	bool	getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void			beSigned(const Bureaucrat& bureaucrat);
	virtual	void	execute(Bureaucrat const& executor) const = 0;

	class	GradeTooHighException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};

	class	GradeTooLowException : public std::exception {
	public:
		virtual	const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);
