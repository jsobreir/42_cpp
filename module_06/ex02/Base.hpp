/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:00:46 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/26 12:32:19 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time()



class Base {
	public:
		virtual ~Base();
} ;

Base *generate(void);
void identify(Base *p);
void identify(Base &p);