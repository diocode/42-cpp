/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/04/16 14:21:49 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <limits>

class PmergeMe {
public:
	std::vector<unsigned int> vec;
	std::list<unsigned int> lst;

	PmergeMe();
	PmergeMe(const PmergeMe& value);
	PmergeMe& operator=(const PmergeMe& value);
	~PmergeMe();

	void	sortVector(int ac);
	void	sortList(int ac);
};
