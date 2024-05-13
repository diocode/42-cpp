/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: digoncal                                     +:+ +:+         +:+     */
/*   <digoncal@student.42porto.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Project:                                          #+#    #+#             */
/*   -> C++ Modules                                   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <ctime>

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