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

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const std::string& value);
	ScavTrap(const ScavTrap& value);
	ScavTrap& operator=(const ScavTrap& value);
	~ScavTrap();

	void attack(const std::string& target);
	void guardGate();
};

#endif //SCAVTRAP_HPP