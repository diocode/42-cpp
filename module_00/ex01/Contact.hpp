/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:31 by digoncal          #+#    #+#             */
/*   Updated: 2023/11/08 11:36:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "main.h"

class	Contact
{
	int 		index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string dark_secret;

public:
	Contact();
	~Contact();
	void		get_contact(void);
	void		print_contact(int index) const;
	void		list_contact(int index) const;
	void		set_index(int index);

private:
	std::string _getInput(std::string msg) const;
	std::string _truncate(std::string str) const;
};

#endif