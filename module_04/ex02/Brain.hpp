/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:06:21 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/17 15:28:24 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		Brain& operator=(const Brain &brain);
		~Brain();
		void setIdea( int i, std::string idea );
		const std::string getIdea( int i );
} ;