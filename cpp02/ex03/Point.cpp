#include "Point.hpp"
#include <iostream>

Point::Point(void): x(0), y(0)
{
}

Point::Point(const float xVal, const float yVal): x(xVal), y(yVal)
{
}

Point::~Point(void)
{
}

Point::Point(const Point& other): x(other.getX()), y(other.getY())
{
}

Point& Point::operator=(const Point& other)
{
	(void)other;
    std::cerr << "Error: Cannot assign to Point object" << std::endl
              << "Reason: x and y are const members" << std::endl
              << "Solution: Use copy constructor instead or create new Point"
			  << std::endl;
    return *this;
}

Fixed Point::getX(void) const
{
	return x;
}

Fixed Point::getY(void) const
{
	return y;
}
