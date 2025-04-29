/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:25:48 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/07 17:57:58 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
} ;

template <typename T> int *easyfind (T cont, int N) {
	typename T::iterator ret = std::find(cont.begin(), cont.end(), N);
	if (ret != cont.end())
		return (&(*ret));
	else
		throw NotFoundException();
}
