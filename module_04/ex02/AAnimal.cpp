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

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal default constructor called\n";
	type = "none";
}

AAnimal::AAnimal(const AAnimal& value) {
	std::cout << "AAnimal copy constructor called\n";
	*this = value;
	type = value.type;
}

AAnimal& AAnimal::operator=(const AAnimal& value) {
	std::cout << "AAnimal copy assignment operator called\n";
	this->type = value.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal Destructor called\n";
}

void	AAnimal::makeSound() const {
	std::cout << "AAnimal makes a sound\n";
}

std::string	AAnimal::getType() const {
	return this->type;
}
