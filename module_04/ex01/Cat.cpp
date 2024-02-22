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

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called\n";
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& value) : Animal(value) {
	std::cout << "Cat copy constructor called\n";
	*this = value;
	type = value.type;
}

Cat& Cat::operator=(const Cat& value) {
	std::cout << "Cat copy assignment operator called\n";
	this->type = value.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called\n";
	delete(_brain);
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow\n";
}
