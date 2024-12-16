/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:58:08 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 17:58:09 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point ( void ) :_x(0), _y(0) { };
Point::Point (const float x, const float y) :_x(x), _y(y) {	}
Point::Point (const Point &point) {
	*this = point;
}
Point& Point::operator=(const Point& point) {
	(void) point;
	return *this;
}
// Getters
const Fixed Point::getX(void) const {
	return _x;
}
const Fixed Point::getY(void) const {
	return _y;
}
