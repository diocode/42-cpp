/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:31 by digoncal          #+#    #+#             */
/*   Updated: 2023/11/08 11:36:32 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main()
{
	Phonebook 	phonebook;
	std::string	input = "";

	phonebook.welcome_msg();
	std::cout << "> " <<std::flush;
	while (getline(std::cin, input).good())
	{
		if (!input.compare("ADD"))
			phonebook.add_contact();
		else if (!input.compare("SEARCH"))
			phonebook.search();
		else if (!input.compare("EXIT"))
			return 0;
		std::cout << "> " <<std::flush;
	}
	std::cout << std::endl;
	return 0;
}