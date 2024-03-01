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

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class	Bureaucrat {
private:
	const std::string	_name;
	int	_grade;
	static const int maxGrade = 1;
	static const int minGrade = 150;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& value);
	Bureaucrat& operator=(const Bureaucrat& value);
	~Bureaucrat();

	std::string const& getName() const;
	int	getGrade() const;

	void	increaseGrade();
	void	decreaseGrade();

	class	GradeTooHighException : public std::exception {
	public:
		virtual const char*	what() const throw();
	};

	class	GradeTooLowException : public std::exception {
	public:
		virtual	const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& value);

#endif //BUREAUCRAT_HPP