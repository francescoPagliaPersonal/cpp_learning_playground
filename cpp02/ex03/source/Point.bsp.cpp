#include "Point.hpp"
#include "Fixed.hpp"

Fixed Point::vector (const Point& p1, const Point& p2, const Point& p3) const {

	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point) const
{
	Fixed d1 = vector(point, a, b);
	Fixed d2 = vector(point, b, c);
	Fixed d3 = vector(point, c, a);
	if ((d1 > 0 && d2 > 0 && d3 > 0)
		|| (d1 < 0 && d2 < 0 && d3 < 0))
		return (true);
	return (false);
}