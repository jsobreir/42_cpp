/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:48:21 by jsobreir          #+#    #+#             */
/*   Updated: 2025/03/26 12:56:24 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> void swap (T *one, T *two) {
	T temp;
	temp = *one;
	*one = *two;
	*two = temp;
}

template <typename T> T min (T one, T two) {
	if (one > two)
		return two;
	else if (one == two)
		return two;
	else
		return one;
}

template <typename T> T max (T one, T two) {
	if (one > two)
		return one;
	else if (one == two)
		return two;
	else
		return two;
}