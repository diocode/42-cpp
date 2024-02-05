/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:30 by digoncal          #+#    #+#             */
/*   Updated: 2023/11/08 11:36:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->weapon = NULL;
}

HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon& weaponVal)
{
	this->weapon = &weaponVal;
}

void	HumanB::attack(void)
{
	if (weapon && weapon->getType() != "")
		std::cout << _name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << _name << " doesn't have a weapon to attack." << std::endl;
}

