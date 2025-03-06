/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/05 18:15:09 by digoncal         ###   ########.fr       */
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
