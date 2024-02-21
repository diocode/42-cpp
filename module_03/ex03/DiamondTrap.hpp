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

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string diamondName;

public:
	DiamondTrap();
	DiamondTrap(const std::string& value);
	DiamondTrap(const DiamondTrap& value);
	DiamondTrap& operator=(const DiamondTrap& value);
	~DiamondTrap();

	using	ScavTrap::attack;
	void	whoAmI();
};

#endif //DIAMONDTRAP_HPP