/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:31 by digoncal          #+#    #+#             */
/*   Updated: 2023/11/08 11:36:32 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Contact::Contact(){}
Contact::~Contact(){}

std::string Contact::_getInput(std::string msg) const
{
	std::string input = "";

	while (true)
	{
		std::cout << msg << ": " << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			return input;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input (Please try again)" << std::endl;
		}
	}
}

std::string Contact::_truncate(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void		Contact::set_index(int index)
{
	this->index = index;
}

void	Contact::get_contact(void)
{
	this->first_name = this->_getInput("First Name");
	this->last_name = this->_getInput("Last Name");
	this->nickname  = this->_getInput("Nickname");
	this->number = this->_getInput("Phone Number");
	this->dark_secret = this->_getInput("Your darkest secret");
	std::cout << std::endl;
}

void	Contact::print_contact(int index) const
{
	if (this->first_name.empty() || this->last_name.empty() || this->nickname.empty())
		return ;
	std::cout << std::endl;
	std::cout << "== CONTACT #" << index << " ==" << std::endl;
	std::cout << "FIRST NAME: " << this->first_name << std::endl;
	std::cout << "LAST NAME: " << this->last_name << std::endl;
	std::cout << "NICKNAME: " << this->nickname << std::endl;
	std::cout << "PHONE NUMBER: " << this->number << std::endl;
	std::cout << "DARKEST SECRET: " << this->dark_secret << std::endl;
	std::cout << std::endl;
}

void	Contact::list_contact(int index) const
{
	if (this->first_name.empty() || this->last_name.empty() || this->nickname.empty())
		return ;
	std::cout << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << _truncate(this->first_name) << std::flush;
	std::cout << "|" << std::setw(10) << _truncate(this->last_name) << std::flush;
	std::cout << "|" << std::setw(10) << _truncate(this->nickname) << std::flush;
	std::cout << std::endl;
}
