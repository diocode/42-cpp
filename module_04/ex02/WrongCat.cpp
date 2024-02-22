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

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& value) : WrongAnimal(value) {
	std::cout << "WrongCat copy constructor called\n";
	*this = value;
	type = value.type;
}

WrongCat& WrongCat::operator=(const WrongCat& value) {
	std::cout << "WrongCat copy assignment operator called\n";
	this->type = value.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called\n";
}

void	WrongCat::makeSound() const {
	std::cout << "Meow? Bark?\n";
}
