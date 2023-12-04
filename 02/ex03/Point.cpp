#include "Point.hpp"

Point::Point() : x(0), y(0)
{
};

const Fixed   &Point::getFixedX(void) const
{
	return x;
};

const Fixed   &Point::getFixedY(void) const
{
	return y;
};

Point::Point(float const x, float const y) : x(Fixed(x)), y(Fixed(y))
{
};

Point::Point(Point const &pt): x(pt.getFixedX()), y(pt.getFixedY())
{
};

Point &Point::operator=(Point const &pt)
{
	(void)pt;
	return *this;
};

Point::~Point(){
};