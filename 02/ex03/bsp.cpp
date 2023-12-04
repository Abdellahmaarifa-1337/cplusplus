#include "Point.hpp"

Fixed get_tringle_area(Point const a, Point const b, Point const c)
{
    Fixed nb(0.5f);

    Fixed trap = ((a.getFixedX() * (b.getFixedY() - c.getFixedY()))
             + (b.getFixedX() * (c.getFixedY() - a.getFixedY())) 
             + (c.getFixedX() * (a.getFixedY() - b.getFixedY())));
    if ((nb * trap) < 0)
        return (nb * trap * -1);
    return nb * trap;
};


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed abcArea = get_tringle_area(a, b, c);
    Fixed apbArea = get_tringle_area(a, point, b);
    Fixed bpcArea = get_tringle_area(b, point, c);
    Fixed acpArea = get_tringle_area(a, c, point);

    if (apbArea == 0 || bpcArea == 0 || acpArea == 0)
        return false;
    if (abcArea == (apbArea + bpcArea + acpArea))
        return true;
    return false;
}