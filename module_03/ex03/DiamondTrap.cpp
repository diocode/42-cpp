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

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	std::cout << "DiamondTrap Default constructor called\n";
	FragTrap::hitPoints = 100;
	ScavTrap::energy = 50;
	FragTrap::atk = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &value) : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap Copy constructor called\n";
	*this = value;
	diamondName = value.diamondName;
	hitPoints = value.hitPoints;
	energy = value.energy;
	atk = value.atk;
}

DiamondTrap::DiamondTrap(const std::string& value) {
	std::cout << "DiamondTrap Copy constructor with params called\n";
	diamondName = value;
	ClapTrap::name = value + "_clap_name";
	FragTrap::hitPoints = 100;
	ScavTrap::energy = 50;
	FragTrap::atk = 30;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &value) {
	std::cout << "DiamondTrap Copy assignment operator called\n";
	this->diamondName = value.diamondName;
	this->hitPoints = value.hitPoints;
	this->energy = value.energy;
	this->atk = value.atk;
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap Destructor called\n";
}

void DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << diamondName << std::endl;
}
