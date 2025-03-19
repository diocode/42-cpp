/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/18 16:16:40 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
public:
	virtual const char *what() const throw() {
		return "Not found.";
	};
};

template <typename T>
int	easyfind(T container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);

	if (it == container.end())
		throw (NotFoundException());
	return std::distance(container.begin(), it);
}
