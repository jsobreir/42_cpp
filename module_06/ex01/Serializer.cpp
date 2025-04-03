/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:00:28 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/25 15:00:29 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer () { }

Serializer::Serializer (Data *data) {
	_data = data;
}

Serializer::Serializer (Serializer const &other) {
	*this = other;
}

Serializer &Serializer::operator=(const Serializer & other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

Serializer::~Serializer() { }

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast <uintptr_t> (ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast <Data *> (raw);
}
