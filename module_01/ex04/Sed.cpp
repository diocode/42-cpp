/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:30 by digoncal          #+#    #+#             */
/*   Updated: 2023/11/08 11:36:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "Sed.hpp"

Sed::Sed(std::string file)
{
	this->_inFile = file;
	this->_outFile = file + ".replace";
}

Sed::~Sed() {}

void	Sed::replace(std::string s1, std::string s2)
{
	std::ifstream	infile(_inFile.c_str());
	if (infile.is_open())
	{
		std::ofstream	outFile(_outFile.c_str());
		std::string 	line;

		while (std::getline(infile, line))
		{
			size_t	pos = line.find(s1, 0);
			while (pos != std::string::npos)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos = line.find(s1, 0);
			}
			outFile << line << std::endl;
		}
		infile.close();
		outFile.close();
	}
	else
	{
		std::cerr << "Unable to open file." << std::endl;
		exit(EXIT_FAILURE);
	}
}
