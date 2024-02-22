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

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& value) {
	std::cout << "Brain copy constructor called\n";
	*this = value;
	std::copy(value.ideas->begin(), value.ideas->end(), ideas->begin());
}

Brain& Brain::operator=(const Brain& value) {
	std::cout << "Brain copy assignment operator called\n";
	std::copy(value.ideas->begin(), value.ideas->end(), ideas->begin());
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called\n";
}
