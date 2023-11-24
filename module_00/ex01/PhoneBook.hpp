/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:31 by digoncal          #+#    #+#             */
/*   Updated: 2023/11/08 11:36:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.h"

class	Phonebook
{
	Contact	contacts[8];
	int 	len;

public:
	Phonebook();
	~Phonebook();
	void	welcome_msg(void) const;
	void	add_contact(void);
	void	search(void);

private:
	void	_searchContact(void);
};

#endif