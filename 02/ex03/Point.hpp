#include <iostream>
#include "Fixed.hpp"

class Point
{
    public:
    Point();
    Point(float const x, float const y);
    Point(Point const &pt);
    Point &operator=(Point const &pt);
    ~Point();
    const Fixed   &getFixedX(void) const;
    const Fixed   &getFixedY(void) const;

    private:
    const Fixed   x;
    const Fixed   y;
};