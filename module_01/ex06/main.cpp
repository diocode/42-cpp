/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:30 by digoncal          #+#    #+#             */
/*   Updated: 2023/11/08 11:36:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl		Harl;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac != 2)
	{
		std::cout << "Invalid arguments\n";
		return 1;
	}

	int stop = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!levels[i].compare(av[1]))
		{
			stop = ++i;
			break;
		}
	}
	switch (stop)
	{
		case 1:
			Harl.complain("DEBUG");
			std::cout << std::endl;
			__attribute__ ((fallthrough));
		case 2:
			Harl.complain("INFO");
			std::cout << std::endl;
			__attribute__ ((fallthrough));
		case 3:
			Harl.complain("WARNING");
			std::cout << std::endl;
			__attribute__ ((fallthrough));
		case 4:
			Harl.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
