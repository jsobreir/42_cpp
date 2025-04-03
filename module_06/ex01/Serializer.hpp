/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:00:31 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/25 15:00:32 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Data.hpp"
#include <stdint.h>

class Serializer {
	private:
		Data *_data;
		Serializer();
	public:
		Serializer(Data *data);
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
} ;
