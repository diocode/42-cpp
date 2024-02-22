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

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include <cstring>

class	WrongAnimal {
protected:
	std::string	type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& value);
	WrongAnimal& operator=(const WrongAnimal& value);
	virtual ~WrongAnimal();

	void	makeSound() const;
	std::string	getType() const;
};

#endif //WRONGANIMAL_HPP