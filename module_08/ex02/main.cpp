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
#include <list>
#include "MutantStack.tpp"

int main() {
	MutantStack<int>	mstack;

	mstack.push(0);
	mstack.push(42);

	std::cout << "Highest value: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Stack size: " << mstack.size() << std::endl;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite) {
		std::cout << "Stack: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	//list version
	std::list<int>	mlist;

	mlist.push_back(0);
	mlist.push_back(42);

	mlist.pop_back();

	std::cout << std::endl;
	std::cout << "Stack size: " << mlist.size() << std::endl;

	mlist.push_back(1);
	mlist.push_back(2);
	mlist.push_back(3);
	mlist.push_back(4);

	std::list<int>::iterator itList = mlist.begin();
	std::list<int>::iterator iteList = mlist.end();

	++it;
	--it;

	while (itList != iteList) {
		std::cout << "List: " << *itList << std::endl;
		++itList;
	}

	return 0;
}
