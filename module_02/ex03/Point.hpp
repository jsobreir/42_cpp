/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:58:11 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 17:58:12 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point ( void );
		Point (const float x, const float y);
		Point (const Point &point);
		Point& operator=(const Point& point);
		// Getters
		const Fixed getX(void) const;
		const Fixed getY(void) const;
} ;

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point);

#endif