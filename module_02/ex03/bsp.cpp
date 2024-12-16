/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:31:51 by jsobreir          #+#    #+#             */
/*   Updated: 2024/12/16 17:57:12 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(Point const &a, Point const &b, Point const &c) {
	float area;

	area = ( a.getX().toFloat()*(b.getY().toFloat() - c.getY().toFloat() )
		+ ( b.getX().toFloat()*(c.getY().toFloat() - a.getY().toFloat()) )
		+ ( c.getX().toFloat()*(a.getY().toFloat() - b.getY().toFloat()) ));
	area *= 0.5;
	if (area >= 0)
		return area;
	else
		return -area;
}

bool bsp( Point const &a, Point const &b, Point const &c, Point const &point) {
	float area1 = area(point, a, b);
	float area2 = area(point, b, c);
	float area3 = area(point, a, c);
	float aTriangle = area(a, b, c);
	if (aTriangle == area1 + area2 + area3)
		return (true);
	else if (!area1 || !area2 || !area3)
		return (true);
	else
		return (false);
}