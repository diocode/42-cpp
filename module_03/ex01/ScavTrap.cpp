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

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	std::cout << "ScavTrap Default constructor called\n";
	hitPoints = 100;
	energy = 50;
	atk = 20;
}

ScavTrap::ScavTrap(const std::string& name) {
	std::cout << "ScavTrap Copy constructor with params called\n";
	this->name = name;
	hitPoints = 100;
	energy = 50;
	atk = 20;
}

ScavTrap::ScavTrap(const ScavTrap &value) : ClapTrap(value) {
	std::cout << "ScavTrap Copy constructor called\n";
	*this = value;
	this->name = value.name;
	this->hitPoints = value.hitPoints;
	this->energy = value.energy;
	this->atk = value.atk;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &value) {
	std::cout << "ScavTrap Copy assignment operator called\n";
	this->name = value.name;
	this->hitPoints = value.hitPoints;
	this->energy = value.energy;
	this->atk = value.atk;
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap Destructor called\n";
}

void	ScavTrap::attack(const std::string& target) {
	if (energy > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << atk << " points of damage!\n";
		energy--;
	}
	else
		std::cout << "ScavTrap " << name << " can't attack\n";
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}
