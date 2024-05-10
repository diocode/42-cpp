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
	*this = value;
}

RPN &RPN::operator=(const RPN &value) {
	this->stk = value.stk;
	return *this;
}

RPN::~RPN() {}

int strToInt(const std::string& str) {
	int n;
	std::stringstream	ss(str);

	ss >> n;
	return n;
}

int RPN::calc(const std::string& str) {

	int a, b, res;
	std::stringstream	ss(str);
	std::string	curr;

	while (ss >> curr) {
		if (curr == "/" || curr == "*" || curr == "-" || curr == "+") {
			if (stk.size() < 2)
				throw std::runtime_error("Error");
			b = stk.top();
			stk.pop();
			a = stk.top();
			stk.pop();
			switch (curr.at(0))
			{
				case '+':
					res = a + b ; break;
				case '-':
					res = a - b ; break;
				case '*':
					res = a * b ; break;
				case '/':
					if (b != 0)
						res = a / b;
					else
						throw std::runtime_error("Error");
					break;
			}
			stk.push(res);
		}
		else
			stk.push(strToInt(curr));
	}
	return stk.top();
}
