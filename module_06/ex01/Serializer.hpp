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

#pragma once

# include <stdint.h>
# include "data.hpp"

class	Serializer {
private:
	Serializer();
	Serializer(const Serializer&);
	Serializer &operator=(const Serializer&);
	~Serializer();

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*	deserialize(uintptr_t raw);
};