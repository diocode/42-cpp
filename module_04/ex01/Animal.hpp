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

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <cstring>

#include "Brain.hpp"

class	Animal {
protected:
	std::string	type;

public:
	Animal();
	Animal(const Animal& value);
	Animal& operator=(const Animal& value);
	virtual ~Animal();

	virtual void	makeSound() const;
	std::string	getType() const;
};

#endif //ANIMAL_HPP