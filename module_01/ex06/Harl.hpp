/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:30 by digoncal          #+#    #+#             */
/*   Updated: 2023/11/08 11:36:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class	Harl
{
private:
	char	_filter;

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Harl();
	Harl(std::string filter);
	~Harl();

	void	complain(std::string level);
};

typedef void (Harl::*t_cmd) ( void );

#endif // HARL_HPP