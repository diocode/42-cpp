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
	ClapTrap	a("Brian");
	ScavTrap	b("Jeff");
	ScavTrap	c(b);

	a.attack("Jeff");
	b.takeDamage(10);

	c.attack("Jeff");
	c.beRepaired(10);
	b.takeDamage(200);
	b.attack("Jeff");
	c.guardGate();
	return 0;
}