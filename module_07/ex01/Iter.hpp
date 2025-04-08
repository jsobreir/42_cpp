/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:59:32 by jsobreir          #+#    #+#             */
/*   Updated: 2025/04/03 15:48:45 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
static void printArray(T *array, int len) {
    std::cout << "[";
    for(int i = 0; i < len; i++) {
        std::cout << array[i];
        if (i != len - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

template <typename T, typename S> void iter(T *array, int len, S function) {
	for (int i = 0; i < len; i++) {
        function(array[i]);
    }
    printArray(array, len);
}