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

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &value) {
	this->stk = value.stk;
}

RPN &RPN::operator=(const RPN &value) {
	this->stk = value.stk;
	return *this;
}

RPN::~RPN() {}

int RPN::calc(const std::string& str) {

	int a, b, res;
	std::stringstream	ss(str);
	std::string	curr;

	while (ss >> curr) {
		if (curr == "/" || curr == "*" || curr == "-" || curr == "+") {
			if (stk.size() < 2)
				throw std::runtime_error("Error");
			b = stk.top();
			stk.pop(); //WIP
		}
	}
}
