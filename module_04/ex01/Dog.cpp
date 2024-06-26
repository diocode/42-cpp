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

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called\n";
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& value) : Animal(value) {
	std::cout << "Dog copy constructor called\n";
	*this = value;
	type = value.type;
}

Dog& Dog::operator=(const Dog& value) {
	std::cout << "Dog copy assignment operator called\n";
	if (this == &value)
		return (*this);
	this->_brain = new Brain(*value._brain);
	this->type = value.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called\n";
	delete(_brain);
}

void	Dog::makeSound() const {
	std::cout << "Bark Bark\n";
}
