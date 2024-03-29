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

int main(void) {
	ClapTrap a("ClapTrack");
	ScavTrap b("ScavTrap");
	ScavTrap c;

	a.attack("ScavTrap");
	b.takeDamage(20);
	b.beRepaired(20);
	b.guardGate();
	c.attack("ClapTrap");
	c.takeDamage(30);
	c.beRepaired(10);
	c.guardGate();
}