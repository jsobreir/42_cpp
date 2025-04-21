/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:00:24 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/21 11:34:04 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main (void) {
	Data data;
	Data new_data;
	uintptr_t ptr;
	data.age = 11;
	data.name = "Sofia";
	std::cout << "Before Serialize" << std::endl;
	std::cout << "Name: " << data.name << std::endl;
	std::cout << "Age: " << data.age << "\n" << std::endl;
	ptr = Serializer::serialize(&data);
	new_data = *Serializer::deserialize(ptr);
	std::cout << "After Serialize" << std::endl;
	std::cout << "Name: " << new_data.name << std::endl;
	std::cout << "Age: " << new_data.age << std::endl;
}