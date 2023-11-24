/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:31 by digoncal          #+#    #+#             */
/*   Updated: 2023/11/08 11:36:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Phonebook::Phonebook()
{
	this->len = 0;
}

Phonebook::~Phonebook(){}

void	Phonebook::welcome_msg(void) const
{
	std::cout << std::endl;
	std::cout << "       ** PhoneBook 📞 **" << std::endl;
	std::cout << std::endl;
	std::cout << "------------ USAGE ---------------" << std::endl;
	std::cout << "ADD - to add a contact." << std::endl;
	std::cout << "SEARCH - to search for a contact." << std::endl;
	std::cout << "EXIT - to quite the PhoneBook." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}

void	Phonebook::add_contact(void)
{
	static int i;

	this->contacts[i % 8].get_contact();
	this->contacts[i % 8].set_index(i % 8);
	if (this->len <= 8)
		this->len += 1;
	i++;
}

void	Phonebook::_searchContact(void)
{
	int	input = -1;

	while (true)
	{
		std::cout << "Contact index: " << std::flush;
		std::cin >> input;
		if (std::cin.good() && (input >= 0 && input < this->len))
		{
			contacts[input].print_contact(input);
			return;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Invalid index (Please try again)" << std::endl;
		}
	}
}

void	Phonebook::search(void)
{
	if (!this->len)
	{
		std::cout << std::setw(10) << "|  No contacts in the phonebook  |" << std::endl << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "----------- PHONEBOOK CONTACTS ------------" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(10) << "INDEX" << std::flush;
	std::cout << "|" << std::setw(10) << "FIRST NAME" << std::flush;
	std::cout << "|" << std::setw(10) << "LAST NAME" << std::flush;
	std::cout << "|" << std::setw(10) << "NICKNAME" << std::flush;
	std::cout << std::endl;

	for (int i = 0; i < len; i++)
	{
		this->contacts[i].list_contact(i);
		std::cout << "-------------------------------------------" << std::endl;
	}
	std::cout << std::endl;
	_searchContact();
}
