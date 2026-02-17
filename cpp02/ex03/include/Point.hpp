/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:38:50 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/17 17:55:20 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point {

	public:

	Point(void);
	Point(float const xpos, float const ypos);
	Point(const Point& point);
	Point& operator=(const Point& point);
	~Point(void);
	
	bool bsp( Point const a, Point const b, Point const c, Point const point) const;

	float getXpos(void) const;
	float getYpos(void) const;
	
	private:
	
	Fixed const	x;
	Fixed const	y;
	Fixed sign(const Point& p1, const Point& p2, const Point& p3) const ;
};

#endif