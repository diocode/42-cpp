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

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include <cstring>

#include "Brain.hpp"

class	AAnimal {
protected:
	std::string	type;

public:
	AAnimal();
	AAnimal(const AAnimal& value);
	AAnimal& operator=(const AAnimal& value);
	virtual ~AAnimal();

	virtual void	makeSound() const = 0;
	std::string	getType() const;
};

#endif //AANIMAL_HPP