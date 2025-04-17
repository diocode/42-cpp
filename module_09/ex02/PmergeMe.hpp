/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/04/17 14:48:35 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <limits>
#include <algorithm>

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
