#include "Point.hpp"

// CONSTRUCTORS  -------------------------------------------------------------/

Point::Point(void)
	: x(0), y(0) {};

Point::Point(float const xpos, float const ypos)
	: x(xpos), y(ypos) {};

Point::Point(const Point& point)
	: x(point.x), y(point.y) {};
	
Point& Point::operator=(const Point& point) {
	(void)point;
	return (*this);
}

Point::~Point(void) {};

// METHODS  -------------------------------------------------------------/

float Point::getXpos(void) const
{
	return (this->x.toFloat());
}

float Point::getYpos(void) const
{
	return (this->y.toFloat());
}

