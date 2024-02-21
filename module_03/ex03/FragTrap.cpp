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

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap Default constructor called\n";
	hitPoints = 100;
	energy = 100;
	atk = 30;
}

FragTrap::FragTrap(const std::string& value) : ClapTrap(value) {
	std::cout << "FragTrap Copy constructor with params called\n";
	hitPoints = 100;
	energy = 100;
	atk = 30;
}

FragTrap::FragTrap(const FragTrap &value) : ClapTrap(value) {
	std::cout << "FragTrap Copy constructor called\n";
	*this = value;
	this->name = value.name;
	this->hitPoints = value.hitPoints;
	this->energy = value.energy;
	this->atk = value.atk;
}

FragTrap&	FragTrap::operator=(const FragTrap &value) {
	std::cout << "FragTrap Copy assignment operator called\n";
	this->name = value.name;
	this->hitPoints = value.hitPoints;
	this->energy = value.energy;
	this->atk = value.atk;
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap Destructor called\n";
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " high five anyone??\n";
}
