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

#include "Sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4 || !av[1][0])
	{
		std::cout << "Invalid arguments" << std::endl;
		return EXIT_FAILURE;
	}
	Sed	sed(av[1]);
	sed.replace(av[2], av[3]);
}
