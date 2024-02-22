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

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called\n";
	type = "none";
}

Animal::Animal(const Animal& value) {
	std::cout << "Animal copy constructor called\n";
	*this = value;
	type = value.type;
}

Animal& Animal::operator=(const Animal& value) {
	std::cout << "Animal copy assignment operator called\n";
	this->type = value.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called\n";
}

void	Animal::makeSound() const {
	std::cout << "Animal makes a sound\n";
}

std::string	Animal::getType() const {
	return this->type;
}
