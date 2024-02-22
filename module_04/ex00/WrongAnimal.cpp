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

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called\n";
	type = "none";
}

WrongAnimal::WrongAnimal(const WrongAnimal& value) {
	std::cout << "WrongAnimal copy constructor called\n";
	*this = value;
	type = value.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& value) {
	std::cout << "WrongAnimal copy assignment operator called\n";
	this->type = value.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called\n";
}

void	WrongAnimal::makeSound() const {
	std::cout << "I'm a failure! Why was I born this way?!\n";
}

std::string	WrongAnimal::getType() const {
	return this->type;
}
